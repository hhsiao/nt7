-- ═══════════════════════════════════════════════════════════════════
-- WuxiaGUI v3 — Modern Tabbed Character Panel
-- GMCP-driven, no mudlib changes needed.
--
-- Tabs: 總覽 | 屬性 | 技能 | 天賦 | 裝備
-- INSTALL: Paste into Mudlet Script Editor as a single script.
-- REMOVE:  lua WuxiaGUI3.destroy()
-- ═══════════════════════════════════════════════════════════════════

-- ─── Cleanup previous instance ───
if WuxiaGUI3 and WuxiaGUI3.destroy then
  WuxiaGUI3.destroy()
end

WuxiaGUI3 = {}
WuxiaGUI3._handlers    = {}
WuxiaGUI3._sysHandlers = {}

-- ═══════════════════════════════════════════════
-- § 1  Configuration
-- ═══════════════════════════════════════════════
local PW       = 320          -- right panel width px
local LPW      = 280          -- left panel width px
local BG       = "#111122"    -- main background
local BG2      = "#161630"    -- card / section bg
local BORDER   = "#2a2a50"    -- borders, separators
local TEXT      = "#cccccc"    -- default text
local TEXT_DIM  = "#777790"    -- dimmed labels
local GOLD      = "#e8c170"   -- titles, highlights
local GOLD_DIM  = "#8a7040"   -- inactive tab
local WHITE     = "#eeeeee"   -- bright values

-- Pin icon: pushpin U+1F4CC + Variation Selector 15 (U+FE0E) = text mode, colorable
local PIN_CHAR  = "📌︎"

local CHAT_H    = 180         -- chat panel height px

-- Gauge colours  { foreground, background }
local C_JING   = { "#cc3333", "#3d1111" }
local C_QI     = { "#33aa44", "#113318" }
local C_JINGLI = { "#3388cc", "#112240" }
local C_NEILI  = { "#aa44cc", "#271140" }
local C_FOOD   = { "#cc9933", "#332811" }
local C_WATER  = { "#4488cc", "#112244" }
local C_EXP    = { "#55bb55", "#113311" }

-- Tab names (order matters)
local TABS = { "總覽", "屬性", "技能", "天賦", "裝備" }

-- ═══════════════════════════════════════════════
-- § 2  State
-- ═══════════════════════════════════════════════
WuxiaGUI3.activeTab = "總覽"
WuxiaGUI3.activeChatTab = "全部"

WuxiaGUI3.vitals = {
  jing=0, eff_jing=0, max_jing=1,
  qi=0, eff_qi=0, max_qi=1,
  jingli=0, max_jingli=1, jiajing=0,
  neili=0, max_neili=1, jiali=0,
  food=0, max_food=300, water=0, max_water=300,
  potential=0, experience=0, combat_exp=0,
  craze=0, max_craze=0, jianu=0,
}

WuxiaGUI3.status = {
  name="", id="", title="", age=0, gender="",
  str=0, int_=0, con=0, dex=0, per=0, kar=0,
  level=1, wugong_level=1, combat_exp=0, next_level=0,
  jingli_limit=0, neili_limit=0, potential_limit=0, experience_limit=0,
  ability=0, achievement=0, active=0,
  xuemai_level=0, yuanshen_level=0,
  force=0, dodge=0, parry=0, unarmed=0,
  sword=0, blade=0, staff=0, whip=0,
  throwing=0, shooting=0, literate=0,
  max_jiali=0, max_jianu=0,
  xuemai_progress=100, yuanshen_next=0,
  death_protect=0, kill_protect=0,
}

-- Char.Buffs: raw source data from server
WuxiaGUI3.buffs = {}
WuxiaGUI3._buffsActiveFilter = "all"

-- Char.Inventory: items, equipment, sets
WuxiaGUI3.inventory = {}

-- Char.Talents: talent tree data from server
WuxiaGUI3.talents = {}

-- Char.Skills: raw data from server
WuxiaGUI3.skillData = {}

-- ═══════════════════════════════════════════════
-- § 3  Helpers
-- ═══════════════════════════════════════════════
local MX = 10                       -- horizontal margin
local GW = PW - MX * 2             -- gauge / content width

-- Base64 encoder for inline SVG data URIs
local function _b64(data)
  local b = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/'
  return ((data:gsub('.', function(x)
    local r, byte = '', x:byte()
    for i = 8, 1, -1 do r = r .. (byte % 2^i - byte % 2^(i-1) > 0 and '1' or '0') end
    return r
  end) .. '0000'):gsub('%d%d%d?%d?%d?%d?', function(x)
    if #x < 6 then return '' end
    local c = 0
    for i = 1, 6 do c = c + (x:sub(i,i) == '1' and 2^(6-i) or 0) end
    return b:sub(c+1, c+1)
  end) .. ({'', '==', '='})[#data % 3 + 1])
end

-- Format large numbers: 12345 → "12,345"
local function fmtNum(n)
  n = tonumber(n) or 0
  if n < 1000 then return tostring(n) end
  local s = tostring(n)
  local pre, rest = s:match("^(-?%d+)(%d%d%d)$")
  if not pre then return s end
  -- simple thousands
  return pre .. "," .. rest
end

-- Create a styled gauge with label above it
-- Returns next y position
local function makeGauge(parent, id, y, h, fgColor, bgColor)
  -- Label
  local lbl = Geyser.Label:new({
    name = "W3."..id..".lbl",
    x = MX, y = y, width = GW, height = 15,
  }, parent)
  lbl:setStyleSheet("background-color: transparent;")
  lbl:setFontSize(9)
  WuxiaGUI3[id.."Lbl"] = lbl

  -- Gauge container (manual bar, not Geyser.Gauge)
  local gc = Geyser.Container:new({
    name = "W3."..id..".gc",
    x = MX, y = y + 15, width = GW, height = h,
  }, parent)

  -- Single gradient label (never resized — preserves border-radius)
  local back = Geyser.Label:new({
    name = "W3."..id..".back",
    x = 0, y = 0, width = "100%", height = "100%",
  }, gc)
  back:setStyleSheet(string.format(
    "background-color: %s; border-radius: 5px;", bgColor))

  -- 100% marker line (thin vertical line, overflow only)
  local marker = Geyser.Label:new({
    name = "W3."..id..".marker",
    x = "50%", y = 0, width = 2, height = "100%",
  }, gc)
  marker:setStyleSheet("background-color: rgba(255,255,255,0.6);")
  marker:hide()

  -- Precompute brighter overflow color
  local brightColor = fgColor
  local r, gr2, b = fgColor:match("#(%x%x)(%x%x)(%x%x)")
  if r then
    brightColor = string.format("rgb(%d,%d,%d)",
      math.min(255, tonumber(r, 16) + 60),
      math.min(255, tonumber(gr2, 16) + 60),
      math.min(255, tonumber(b, 16) + 60))
  end

  WuxiaGUI3[id.."Gauge"] = {
    container = gc, back = back, marker = marker,
    fgColor = fgColor, bgColor = bgColor, brightColor = brightColor,
  }

  return y + 15 + h + 4
end

-- Apply gauge fill via CSS gradient on the back label (no resize — preserves border-radius)
-- Uses tiny offset between stops to avoid duplicate-position ambiguity in Qt.
local function applyGaugeFill(g, ratio)
  local fg, bg, bright = g.fgColor, g.bgColor, g.brightColor
  if ratio <= 0.001 then
    g.back:setStyleSheet(string.format(
      "background-color: %s; border-radius: 5px;", bg))
    g.marker:hide()
  elseif ratio >= 0.999 and ratio <= 1.001 then
    -- At or very near 100%: show solid fill color
    g.back:setStyleSheet(string.format(
      "background-color: %s; border-radius: 5px;", fg))
    g.marker:hide()
  elseif ratio < 1.0 then
    local s1 = string.format("%.4f", ratio)
    local s2 = string.format("%.4f", ratio + 0.001)
    g.back:setStyleSheet(string.format(
      "border-radius: 5px; background: qlineargradient(x1:0,y1:0,x2:1,y2:0," ..
      "stop:0 %s, stop:%s %s, stop:%s %s, stop:1 %s);",
      fg, s1, fg, s2, bg, bg))
    g.marker:hide()
  else
    -- Overflow (ratio > 1)
    local base = math.max(0.01, math.min(0.98, 1.0 / ratio))
    local s1 = string.format("%.4f", base)
    local s2 = string.format("%.4f", base + 0.001)
    g.back:setStyleSheet(string.format(
      "border-radius: 5px; background: qlineargradient(x1:0,y1:0,x2:1,y2:0," ..
      "stop:0 %s, stop:%s %s, stop:%s %s, stop:1 %s);",
      fg, s1, fg, s2, bright, bright))
    g.marker:move(math.floor(base * 100).."%", 0)
    g.marker:show()
  end
end

-- Animate gauge from current displayed ratio to target ratio
local GAUGE_ANIM_DURATION = 0.3
local GAUGE_ANIM_STEP = 0.016

local function animateGauge(g, targetRatio)
  if g._animTimer then
    killTimer(g._animTimer)
    g._animTimer = nil
  end

  local startRatio = g._animRatio or 0
  g._animRatio = targetRatio  -- record target in case of rapid updates

  if math.abs(startRatio - targetRatio) < 0.005 then
    g._animRatio = targetRatio
    applyGaugeFill(g, targetRatio)
    return
  end

  local steps = math.ceil(GAUGE_ANIM_DURATION / GAUGE_ANIM_STEP)
  local step = 0

  local function tick()
    step = step + 1
    local t = math.min(step / steps, 1)
    t = 1 - (1 - t) ^ 3  -- ease-out cubic
    local current = startRatio + (targetRatio - startRatio) * t
    g._animRatio = current
    applyGaugeFill(g, current)
    if t >= 1 then
      g._animTimer = nil
      return
    end
    g._animTimer = tempTimer(GAUGE_ANIM_STEP, tick)
  end

  tick()
end

-- Animate a Geyser.Gauge (food/water) from current to target value
local function animateGeyserGauge(gauge, targetCur, targetMax)
  if gauge._animTimer then
    killTimer(gauge._animTimer)
    gauge._animTimer = nil
  end

  local startCur = gauge._animCur or 0
  if targetMax < 1 then targetMax = 1 end
  local startRatio = startCur / targetMax
  local targetRatio = targetCur / targetMax

  if math.abs(startRatio - targetRatio) < 0.005 then
    gauge._animCur = targetCur
    gauge:setValue(targetCur, targetMax)
    return
  end

  local steps = math.ceil(GAUGE_ANIM_DURATION / GAUGE_ANIM_STEP)
  local step = 0

  local function tick()
    step = step + 1
    local t = math.min(step / steps, 1)
    t = 1 - (1 - t) ^ 3  -- ease-out cubic
    local current = startCur + (targetCur - startCur) * t
    gauge._animCur = current
    gauge:setValue(current, targetMax)
    if t >= 1 then
      gauge._animTimer = nil
      return
    end
    gauge._animTimer = tempTimer(GAUGE_ANIM_STEP, tick)
  end

  tick()
end

-- Create a horizontal separator line
local function makeSep(parent, y)
  local s = Geyser.Label:new({
    name = "W3.sep."..tostring(y),
    x = MX, y = y, width = GW, height = 1,
  }, parent)
  s:setStyleSheet("background-color: "..BORDER..";")
  return y + 6
end

-- Create a label for text content
local function makeLabel(parent, id, y, h)
  local lbl = Geyser.Label:new({
    name = "W3."..id,
    x = MX, y = y, width = GW, height = h,
  }, parent)
  lbl:setStyleSheet("background-color: transparent; qproperty-alignment: 'AlignLeft | AlignTop';")
  lbl:setFontSize(9)
  WuxiaGUI3[id] = lbl
  return y + h
end

-- Styled HTML span
local function span(color, text)
  return string.format('<span style="color:%s;">%s</span>', color, text)
end

-- Convert ANSI color codes to HTML spans
-- Handles ESC[Nm and ESC[N;N;Nm sequences
local _ansiColors = {
  ["30"] = "#000",    ["31"] = "#a00",    ["32"] = "#0a0",    ["33"] = "#a50",
  ["34"] = "#00a",    ["35"] = "#a0a",    ["36"] = "#0aa",    ["37"] = "#aaa",
  ["1;30"] = "#555",  ["1;31"] = "#f55",  ["1;32"] = "#5f5",  ["1;33"] = "#ff5",
  ["1;34"] = "#55f",  ["1;35"] = "#f5f",  ["1;36"] = "#5ff",  ["1;37"] = "#fff",
}
local function stripAnsi(s)
  if not s or s == "" then return "" end
  return s:gsub("\27%[[%d;]*m", "")
end

local function ansiToHtml(s)
  if not s or s == "" then return "" end
  -- Match ESC[ ... m sequences and replace with <span> or </span>
  local result = ""
  local openSpans = 0
  local i = 1
  local len = #s
  while i <= len do
    local esc = string.find(s, "\027%[", i)
    if not esc then
      result = result .. string.sub(s, i)
      break
    end
    -- Append text before ESC
    if esc > i then
      result = result .. string.sub(s, i, esc - 1)
    end
    -- Find the 'm' terminator
    local mpos = string.find(s, "m", esc + 2)
    if not mpos then
      result = result .. string.sub(s, i)
      break
    end
    local codes = string.sub(s, esc + 2, mpos - 1)
    i = mpos + 1

    -- Reset code (0 or 2;37;0m style resets)
    if codes == "0" or codes == "" or codes:match("^2;37;0$") then
      if openSpans > 0 then
        result = result .. "</span>"
        openSpans = openSpans - 1
      end
    else
      -- Look up color
      local color = _ansiColors[codes]
      if not color then
        -- Try extracting just the bold+fg part (e.g. "1;35" from "1;35")
        local bold, fg = codes:match("^(1);(%d+)$")
        if bold and fg then
          color = _ansiColors[bold .. ";" .. fg]
        else
          fg = codes:match("^(%d+)$")
          if fg then color = _ansiColors[fg] end
        end
      end
      if color then
        -- Close previous span if open
        if openSpans > 0 then
          result = result .. "</span>"
          openSpans = openSpans - 1
        end
        result = result .. '<span style="color:' .. color .. ';">'
        openSpans = openSpans + 1
      end
    end
  end
  -- Close any remaining open spans
  for _ = 1, openSpans do
    result = result .. "</span>"
  end
  return result
end

-- Key-value pair for display
local function kv(label, value, valueColor)
  valueColor = valueColor or WHITE
  return span(TEXT_DIM, label) .. " " .. span(valueColor, tostring(value))
end

-- ═══════════════════════════════════════════════
-- § 3b  Persistence (save/load across sessions)
-- ═══════════════════════════════════════════════
WuxiaGUI3._saveFile = getMudletHomeDir() .. "/WuxiaGUI3_settings.lua"

function WuxiaGUI3._saveSettings()
  local data = {
    pinnedTabs = WuxiaGUI3.pinnedTabs or {},
    tabOrder = WuxiaGUI3._tabOrder or {},
    allTabSendChannel = WuxiaGUI3._allTabSendChannel or "閒聊",
    chatHeight = WuxiaGUI3._currentChatH or CHAT_H,
    bigMapOpen = WuxiaGUI3._bigMapVisible or false,
  }
  table.save(WuxiaGUI3._saveFile, data)
end

function WuxiaGUI3._loadSettings()
  local data = {}
  if io.open(WuxiaGUI3._saveFile, "r") then
    table.load(WuxiaGUI3._saveFile, data)
  end
  if data.pinnedTabs then WuxiaGUI3.pinnedTabs = data.pinnedTabs end
  if data.tabOrder then WuxiaGUI3._tabOrder = data.tabOrder end
  if data.allTabSendChannel then WuxiaGUI3._allTabSendChannel = data.allTabSendChannel end
  if data.chatHeight then
    local h = tonumber(data.chatHeight)
    if h and h >= CHAT_H then
      WuxiaGUI3._currentChatH = h
    end
  end
  WuxiaGUI3._savedBigMapOpen = data.bigMapOpen or false
end

-- ═══════════════════════════════════════════════
-- § 4  Build GUI Structure
-- ═══════════════════════════════════════════════
function WuxiaGUI3.build()
  -- Load saved settings before building
  WuxiaGUI3._loadSettings()

  local chatH = WuxiaGUI3._currentChatH or CHAT_H
  WuxiaGUI3._currentChatH = chatH

  setBorderRight(PW)
  setBorderLeft(LPW)
  setBorderTop(chatH)

  -- ═════════════════════════════════════════
  -- LEFT PANEL: 地圖 / 場景 / 戰鬥 (stacked)
  -- ═════════════════════════════════════════
  WuxiaGUI3.leftMain = Geyser.Container:new({
    name = "W3.left", x = 0, y = 0,
    width = LPW, height = "100%",
  })

  -- Background fill → atmospheric image
  local leftBgPath = getMudletHomeDir() .. "/WuxiaGUI3/wuxia_left_panel_background.png"
  WuxiaGUI3.leftBg = Geyser.Label:new({
    name = "W3.left.bg", x = 0, y = 0,
    width = "100%", height = "100%",
  }, WuxiaGUI3.leftMain)
  local fhLB = io.open(leftBgPath, "r")
  if fhLB then fhLB:close()
    WuxiaGUI3.leftBg:setStyleSheet("border-image:url(" .. leftBgPath .. ") 0 0 0 0 stretch stretch;")
  else
    WuxiaGUI3.leftBg:setStyleSheet(string.format("background-color: %s;", BG))
  end
  -- Dark overlay for text readability
  WuxiaGUI3.leftOverlay = Geyser.Label:new({
    name = "W3.left.overlay", x = 0, y = 0,
    width = "100%", height = "100%",
  }, WuxiaGUI3.leftMain)
  WuxiaGUI3.leftOverlay:setStyleSheet("background-color:rgba(0,0,0,0.35); border-right:1px solid " .. BORDER .. ";")

  WuxiaGUI3._buildLeftPanel()

  -- ═════════════════════════════════════════
  -- RIGHT PANEL: 人物
  -- ═════════════════════════════════════════

  -- ─── Root container ───
  WuxiaGUI3.main = Geyser.Container:new({
    name = "W3.main", x = -PW, y = 0,
    width = PW, height = "100%",
  })

  -- Background fill
  WuxiaGUI3.bgLabel = Geyser.Label:new({
    name = "W3.bg", x = 0, y = 0,
    width = "100%", height = "100%",
  }, WuxiaGUI3.main)
  WuxiaGUI3.bgLabel:setStyleSheet(string.format(
    "background-color: %s; border-left: 1px solid %s;", BG, BORDER))

  -- ─── Header background image ───
  -- Adjust headerBgH to stretch/shrink the title background on Y axis
  local headerBgH = 54
  local headerBgPath = getMudletHomeDir() .. "/WuxiaGUI3/wuxia_panel_title.png"
  WuxiaGUI3.headerBg = Geyser.Label:new({
    name = "W3.headerBg", x = 0, y = 0,
    width = PW, height = headerBgH,
  }, WuxiaGUI3.main)
  local fhHdr = io.open(headerBgPath, "r")
  if fhHdr then fhHdr:close()
    WuxiaGUI3.headerBg:setStyleSheet("border-image:url(" .. headerBgPath .. ") 0 0 0 0 stretch stretch;")
  else
    WuxiaGUI3.headerBg:setStyleSheet("background-color:" .. BG .. ";")
  end

  -- ─── Title bar ───
  WuxiaGUI3.titleLbl = Geyser.Label:new({
    name = "W3.titleLbl", x = 0, y = 2,
    width = "100%", height = 24,
  }, WuxiaGUI3.main)
  WuxiaGUI3.titleLbl:setStyleSheet(
    "background-color: transparent; qproperty-alignment: AlignCenter;")
  WuxiaGUI3.titleLbl:setFontSize(12)
  WuxiaGUI3.titleLbl:echo(span(GOLD, "<b>╋ 人 物 ╋</b>"))

  -- ─── Tab bar ───
  local tabBarY = 28
  local tabW = math.floor(PW / #TABS)
  WuxiaGUI3.tabButtons = {}

  for i, name in ipairs(TABS) do
    local btn = Geyser.Label:new({
      name = "W3.tab."..name,
      x = (i-1) * tabW, y = tabBarY,
      width = tabW, height = 22,
    }, WuxiaGUI3.main)
    btn:setFontSize(9)
    btn:setClickCallback("WuxiaGUI3.switchTab", name)
    WuxiaGUI3.tabButtons[name] = btn
  end

  -- ─── Tab content area (below tab bar) ───
  local contentY = tabBarY + 24
  WuxiaGUI3.tabContainers = {}

  for _, name in ipairs(TABS) do
    local c = Geyser.Container:new({
      name = "W3.content."..name,
      x = 0, y = contentY,
      width = PW, height = "-0px",  -- fill remaining
    }, WuxiaGUI3.main)
    WuxiaGUI3.tabContainers[name] = c
    c:hide()
  end

  -- Build each tab's contents
  WuxiaGUI3._buildOverview()
  WuxiaGUI3._buildAttributes()
  WuxiaGUI3._buildSkills()
  WuxiaGUI3._buildTalents()
  WuxiaGUI3._buildEquipment()

  -- Build chat panel (bottom)
  WuxiaGUI3._buildChat()
  WuxiaGUI3._registerChatGMCP()
  WuxiaGUI3._registerChatAlias()

  -- ─── Vitals bar (above main command line) ───
  local vitalsH = 18
  setBorderBottom(vitalsH)
  local vScreenW, _ = getMainWindowSize()
  local vitalsW = (vScreenW or 800) - PW - LPW
  if vitalsW < 200 then vitalsW = 400 end
  WuxiaGUI3._chatVitalsBar = Geyser.Label:new({
    name = "W3.vitalsBar",
    x = LPW, y = -vitalsH,
    width = vitalsW, height = vitalsH,
  })
  WuxiaGUI3._chatVitalsBar:setStyleSheet(string.format([[
    background-color: %s;
    border-top: 1px solid %s;
    qproperty-alignment: AlignVCenter;
    padding-left: 6px;
  ]], BG, BORDER))
  WuxiaGUI3._chatVitalsBar:setFontSize(8)
  WuxiaGUI3._chatVitalsBar:echo(span(TEXT_DIM, "連線中..."))

  -- Show default tab
  WuxiaGUI3.switchTab("總覽")

  WuxiaGUI3.initialized = true
end

-- ═══════════════════════════════════════════════
-- § 4a  Tab: 總覽 (Overview / HUD)
-- ═══════════════════════════════════════════════
function WuxiaGUI3._buildOverview()
  local p = WuxiaGUI3.tabContainers["總覽"]
  local imgDir = getMudletHomeDir() .. "/WuxiaGUI3/"
  local bgPath     = imgDir .. "wuxia_overview_bg.png"
  local bannerPath = imgDir .. "wuxia_overview_banner.png"
  local SHADOW = "text-shadow:1px 1px 3px #000, 0px 0px 6px #000;"
  local CARD_CSS = "background-color:rgba(20,15,10,0.5); border:1px solid rgba(138,106,58,0.5); border-radius:3px;"
  local fh
  local y = 0

  -- ── Layer 1: Background texture ──
  local bgLabel = Geyser.Label:new({
    name = "W3.overview.bg", x = 0, y = 0, width = PW, height = "100%",
  }, p)
  fh = io.open(bgPath, "r")
  if fh then fh:close()
    bgLabel:setStyleSheet("background-color:transparent; border-image:url(" .. bgPath .. ") 0 0 0 0 stretch stretch;")
  else
    bgLabel:setStyleSheet("background-color:#0a0810;")
  end

  -- Dark overlay for text readability
  local overlay = Geyser.Label:new({
    name = "W3.overview.overlay", x = 0, y = 0, width = PW, height = "100%",
  }, p)
  overlay:setStyleSheet("background-color:rgba(0,0,0,0.45);")

  -- ── Zone A: Vitals ──
  y = 4
  y = makeGauge(p, "jing",   y, 18, C_JING[1],   C_JING[2])
  y = makeGauge(p, "qi",     y, 18, C_QI[1],     C_QI[2])
  y = makeGauge(p, "jingli", y, 18, C_JINGLI[1], C_JINGLI[2])
  y = makeGauge(p, "neili",  y, 18, C_NEILI[1],  C_NEILI[2])

  -- Food / Water small gauges
  y = y + 2
  local halfW = math.floor((GW - 6) / 2)
  local foodG = Geyser.Gauge:new({
    name = "W3.food.gauge",
    x = MX, y = y + 14, width = halfW, height = 10,
  }, p)
  foodG.front:setStyleSheet("background-color:"..C_FOOD[1]..";border-radius:2px;")
  foodG.back:setStyleSheet("background-color:"..C_FOOD[2]..";border-radius:2px;")
  WuxiaGUI3.foodGauge = foodG

  local foodLbl = Geyser.Label:new({
    name = "W3.food.lbl",
    x = MX, y = y, width = halfW, height = 14,
  }, p)
  foodLbl:setStyleSheet("background-color:transparent;")
  foodLbl:setFontSize(8)
  WuxiaGUI3.foodLbl = foodLbl

  local waterG = Geyser.Gauge:new({
    name = "W3.water.gauge",
    x = MX + halfW + 6, y = y + 14, width = halfW, height = 10,
  }, p)
  waterG.front:setStyleSheet("background-color:"..C_WATER[1]..";border-radius:2px;")
  waterG.back:setStyleSheet("background-color:"..C_WATER[2]..";border-radius:2px;")
  WuxiaGUI3.waterGauge = waterG

  local waterLbl = Geyser.Label:new({
    name = "W3.water.lbl",
    x = MX + halfW + 6, y = y, width = halfW, height = 14,
  }, p)
  waterLbl:setStyleSheet("background-color:transparent;")
  waterLbl:setFontSize(8)
  WuxiaGUI3.waterLbl = waterLbl

  y = y + 28

  -- Craze / Pinghe indicator
  y = makeLabel(p, "crazeLbl", y, 16)
  y = y + 2

  -- ── Banner divider 1 ──
  local banner1 = Geyser.Label:new({
    name = "W3.overview.banner1", x = 0, y = y, width = PW, height = 30,
  }, p)
  fh = io.open(bannerPath, "r")
  if fh then fh:close()
    banner1:setStyleSheet("background-color:transparent; border-image:url(" .. bannerPath .. ") 0 0 0 0 stretch stretch;")
  else
    banner1:setStyleSheet("background-color:#0a0806;")
  end
  y = y + 30

  -- ── Zone B: Experience ──
  local expHdr = Geyser.Label:new({
    name = "W3.overview.expHdr", x = MX, y = y, width = GW, height = 18,
  }, p)
  expHdr:setStyleSheet("background-color:transparent;")
  expHdr:setFontSize(8)
  expHdr:echo('<div style="' .. SHADOW .. '">' .. span(GOLD, "── 修煉 ──") .. '</div>')
  y = y + 20

  local expCard = Geyser.Label:new({
    name = "W3.overview.expCard", x = MX + 2, y = y, width = GW - 4, height = 52,
  }, p)
  expCard:setStyleSheet(CARD_CSS)

  local expBlock = Geyser.Label:new({
    name = "W3.expBlock", x = 4, y = 2, width = GW - 12, height = 48,
  }, expCard)
  expBlock:setStyleSheet("background-color:transparent; qproperty-alignment:'AlignLeft|AlignTop';")
  expBlock:setFontSize(9)
  WuxiaGUI3.expBlock = expBlock
  y = y + 56

  -- ── Banner divider 2 ──
  local banner2 = Geyser.Label:new({
    name = "W3.overview.banner2", x = 0, y = y, width = PW, height = 30,
  }, p)
  fh = io.open(bannerPath, "r")
  if fh then fh:close()
    banner2:setStyleSheet("background-color:transparent; border-image:url(" .. bannerPath .. ") 0 0 0 0 stretch stretch;")
  else
    banner2:setStyleSheet("background-color:#0a0806;")
  end
  y = y + 30

  -- ── Zone C: Identity ──
  local idHdr = Geyser.Label:new({
    name = "W3.overview.idHdr", x = MX, y = y, width = GW, height = 18,
  }, p)
  idHdr:setStyleSheet("background-color:transparent;")
  idHdr:setFontSize(8)
  idHdr:echo('<div style="' .. SHADOW .. '">' .. span(GOLD, "── 身份 ──") .. '</div>')
  y = y + 20

  local idCard = Geyser.Label:new({
    name = "W3.overview.idCard", x = MX + 2, y = y, width = GW - 4, height = 86,
  }, p)
  idCard:setStyleSheet(CARD_CSS)

  local identityBlock = Geyser.Label:new({
    name = "W3.identityBlock", x = 4, y = 2, width = GW - 12, height = 82,
  }, idCard)
  identityBlock:setStyleSheet("background-color:transparent; qproperty-alignment:'AlignLeft|AlignTop';")
  identityBlock:setFontSize(9)
  WuxiaGUI3.identityBlock = identityBlock

  -- Store shadow for refresh function
  WuxiaGUI3._overviewShadow = SHADOW

  -- ── Raise all content above bg/overlay (z-order) ──
  for _, id in ipairs({"jing", "qi", "jingli", "neili"}) do
    local l = WuxiaGUI3[id.."Lbl"]
    local g = WuxiaGUI3[id.."Gauge"]
    if l then l:raiseAll() end
    if g and g.container then g.container:raiseAll() end
  end
  if WuxiaGUI3.foodLbl    then WuxiaGUI3.foodLbl:raiseAll() end
  if WuxiaGUI3.foodGauge  then WuxiaGUI3.foodGauge:raiseAll() end
  if WuxiaGUI3.waterLbl   then WuxiaGUI3.waterLbl:raiseAll() end
  if WuxiaGUI3.waterGauge then WuxiaGUI3.waterGauge:raiseAll() end
  if WuxiaGUI3.crazeLbl   then WuxiaGUI3.crazeLbl:raiseAll() end
  banner1:raiseAll()
  expHdr:raiseAll()
  expCard:raiseAll()
  banner2:raiseAll()
  idHdr:raiseAll()
  idCard:raiseAll()
end

-- ═══════════════════════════════════════════════
-- § 4b  Tab: 屬性 (Attributes / Stats)
-- ═══════════════════════════════════════════════
function WuxiaGUI3._buildAttributes()
  local p = WuxiaGUI3.tabContainers["屬性"]
  local imgDir = getMudletHomeDir() .. "/WuxiaGUI3/"
  local bannerPath = imgDir .. "wuxia_attr_banner.png"
  local bgPath     = imgDir .. "wuxia_attr_bg.png"
  local fh
  local y = 0

  -- Zone 1: Decorative Top Banner
  local banner1 = Geyser.Label:new({
    name = "W3.attr.banner1", x = 0, y = y, width = PW, height = 40,
  }, p)
  fh = io.open(bannerPath, "r")
  if fh then fh:close()
    banner1:setStyleSheet("background-color:transparent; border-image:url("..bannerPath..") 0 0 0 0 stretch stretch;")
  else
    banner1:setStyleSheet("background-color:#0a0806;")
  end
  y = y + 40

  -- Zone 2: Radar Chart
  -- Background image offset (pixels) to center the bagua image.
  -- Adjust these if the bagua hexagon isn't centered in the 320x320 area.
  local bgOffsetX = 0   -- positive = shift image right
  local bgOffsetY = 0   -- positive = shift image down
  local radarBg = Geyser.Label:new({
    name = "W3.attr.radarBg", x = bgOffsetX, y = y + bgOffsetY,
    width = PW, height = 320,
  }, p)
  fh = io.open(bgPath, "r")
  if fh then fh:close()
    radarBg:setStyleSheet("background-color:transparent; border-image:url("..bgPath..") 0 0 0 0 stretch stretch;")
  else
    radarBg:setStyleSheet("background-color:#0a0810;")
  end
  WuxiaGUI3._attrRadarBg = radarBg

  local radarOverlay = Geyser.Label:new({
    name = "W3.attr.radarOverlay", x = 0, y = y, width = PW, height = 320,
  }, p)
  radarOverlay:setStyleSheet("background-color:rgba(0,0,0,0.15);")

  local radarLabel = Geyser.Label:new({
    name = "W3.attr.radar", x = 0, y = y, width = PW, height = 320,
  }, p)
  radarLabel:setStyleSheet("background-color:transparent;")
  WuxiaGUI3._attrRadarLabel = radarLabel

  local radarPoly = Geyser.Label:new({
    name = "W3.attr.radarPoly", x = 0, y = y, width = PW, height = 320,
  }, p)
  radarPoly:setStyleSheet("background-color:transparent;")
  radarPoly:raiseAll()
  WuxiaGUI3._attrRadarPoly = radarPoly

  -- Raise text label above polygon
  radarLabel:raiseAll()
  -- Radar zone height for layout. Reduce to move everything below upward.
  -- Default 320; e.g. set to 300 to pull the 等級 section up by 20px.
  local radarZoneH = 295
  y = y + radarZoneH

  -- Banner separator
  local banner2 = Geyser.Label:new({
    name = "W3.attr.banner2", x = 0, y = y, width = PW, height = 30,
  }, p)
  fh = io.open(bannerPath, "r")
  if fh then fh:close()
    banner2:setStyleSheet("background-color:transparent; border-image:url("..bannerPath..") 0 0 0 0 stretch stretch;")
  else
    banner2:setStyleSheet("background-color:#0a0806;")
  end
  y = y + 30

  -- Zone 3: Progression Cards (merged 等級 & 修煉 + 上限)
  local SHADOW = "text-shadow:1px 1px 3px #000, 0px 0px 6px #000;"
  local CARD_BORDER = "border:1px solid rgba(138,106,58,0.5); border-radius:3px;"
  local CARD_BG = "background-color:rgba(20,15,10,0.5);"
  local CARD_CSS = CARD_BG .. CARD_BORDER
  local CARD_HDR_CSS = "background-color:transparent; qproperty-alignment:'AlignLeft|AlignTop';"
  local cardX = MX + 2
  local cardW = GW - 4

  -- Background for cards zone (covers hdr1 through filter buttons)
  local cardZoneY = y
  local cardZoneBg = Geyser.Label:new({
    name = "W3.attr.cardZoneBg", x = 0, y = y, width = PW, height = 10,
  }, p)
  local bgPath2 = getMudletHomeDir() .. "/WuxiaGUI3/wuxia_attr_bg2.png"
  local fh2 = io.open(bgPath2, "r")
  if fh2 then fh2:close()
    cardZoneBg:setStyleSheet("border-image:url(" .. bgPath2 .. ") 0 0 0 0 stretch stretch;")
  else
    cardZoneBg:setStyleSheet("background-color:#111122;")
  end

  -- ── Section header ──
  local hdr1 = Geyser.Label:new({
    name = "W3.attr.progHdr1", x = MX, y = y, width = GW, height = 18,
  }, p)
  hdr1:setStyleSheet("background-color:transparent;")
  hdr1:setFontSize(8)
  hdr1:echo('<div style="' .. SHADOW .. '">' .. span(GOLD, "── 等級 & 修煉 ──") .. '</div>')
  y = y + 20

  -- Card 1: 等級 (Tabbed: 等級 / 血脈 / 元神)
  local card1H = 56
  local card1 = Geyser.Label:new({
    name = "W3.attr.card1", x = cardX, y = y, width = cardW, height = card1H,
  }, p)
  card1:setStyleSheet(CARD_CSS)

  -- Tab buttons
  local lvlTabs = { "等級", "血脈", "元神" }
  local tabW = 40
  local tabH = 14
  WuxiaGUI3._lvlTabBtns = {}
  WuxiaGUI3._lvlActiveTab = "等級"
  for ti, tname in ipairs(lvlTabs) do
    local tx = 4 + (ti - 1) * (tabW + 2)
    local tbtn = Geyser.Label:new({
      name = "W3.attr.lvlTab" .. ti, x = tx, y = 2, width = tabW, height = tabH,
    }, card1)
    tbtn:setFontSize(7)
    tbtn:setStyleSheet("background-color:transparent; qproperty-alignment:AlignCenter;")
    tbtn:setClickCallback("WuxiaGUI3._onLvlTabClick", tname)
    WuxiaGUI3._lvlTabBtns[tname] = tbtn
  end

  -- Body area
  local card1Body = Geyser.Label:new({
    name = "W3.attr.card1body", x = 4, y = 16, width = cardW - 8, height = 20,
  }, card1)
  card1Body:setStyleSheet("background-color:transparent; qproperty-alignment:'AlignLeft|AlignTop';")
  card1Body:setFontSize(9)
  WuxiaGUI3.attrCard1Body = card1Body

  -- Progress bar
  local barY = 38
  local barH = 12
  local barW = cardW - 8
  local barBg = Geyser.Label:new({
    name = "W3.attr.xpBarBg", x = 4, y = barY, width = barW, height = barH,
  }, card1)
  barBg:setStyleSheet("background-color:rgba(10,8,6,0.8); border:1px solid rgba(80,60,30,0.4); border-radius:2px;")

  local barFill = Geyser.Label:new({
    name = "W3.attr.xpBarFill", x = 1, y = 1, width = "0%", height = barH - 2,
  }, barBg)
  barFill:setStyleSheet("background-color:#8b6914; border-radius:1px;")
  WuxiaGUI3._xpBarFill = barFill

  local barLbl = Geyser.Label:new({
    name = "W3.attr.xpBarLbl", x = 0, y = 0, width = barW, height = barH,
  }, barBg)
  barLbl:setStyleSheet("background-color:transparent;")
  barLbl:setFontSize(7)
  WuxiaGUI3._xpBarLbl = barLbl

  y = y + card1H + 4

  -- Card 2: 點數 (Ability, Achievement, Active, Jiali, Jianu, Protections)
  local card2H = 48
  local card2 = Geyser.Label:new({
    name = "W3.attr.card2", x = cardX, y = y, width = cardW, height = card2H,
  }, p)
  card2:setStyleSheet(CARD_CSS)

  local card2Hdr = Geyser.Label:new({
    name = "W3.attr.card2hdr", x = 4, y = 1, width = 40, height = 13,
  }, card2)
  card2Hdr:setStyleSheet(CARD_HDR_CSS)
  card2Hdr:setFontSize(7)
  card2Hdr:echo(span(GOLD, "點數"))

  local card2Body = Geyser.Label:new({
    name = "W3.attr.card2body", x = 4, y = 14, width = cardW - 8, height = 32,
  }, card2)
  card2Body:setStyleSheet("background-color:transparent; qproperty-alignment:'AlignLeft|AlignTop';")
  card2Body:setFontSize(9)
  WuxiaGUI3.attrCard2Body = card2Body

  y = y + card2H + 4

  -- Card 3: 上限 (Limits + protection status)
  local card3H = 52
  local card3 = Geyser.Label:new({
    name = "W3.attr.card3", x = cardX, y = y, width = cardW, height = card3H,
  }, p)
  card3:setStyleSheet(CARD_CSS)

  local card3Hdr = Geyser.Label:new({
    name = "W3.attr.card3hdr", x = 4, y = 1, width = 40, height = 13,
  }, card3)
  card3Hdr:setStyleSheet(CARD_HDR_CSS)
  card3Hdr:setFontSize(7)
  card3Hdr:echo(span(GOLD, "上限"))

  local card3Body = Geyser.Label:new({
    name = "W3.attr.card3body", x = 4, y = 14, width = cardW - 8, height = 36,
  }, card3)
  card3Body:setStyleSheet("background-color:transparent; qproperty-alignment:'AlignLeft|AlignTop';")
  card3Body:setFontSize(9)
  WuxiaGUI3.attrCard3Body = card3Body

  y = y + card3H + 4

  -- Banner separator
  local banner3 = Geyser.Label:new({
    name = "W3.attr.banner3", x = 0, y = y, width = PW, height = 30,
  }, p)
  fh = io.open(bannerPath, "r")
  if fh then fh:close()
    banner3:setStyleSheet("background-color:transparent; border-image:url("..bannerPath..") 0 0 0 0 stretch stretch;")
  else
    banner3:setStyleSheet("background-color:#0a0806;")
  end
  y = y + 30
  local cardZoneEndY = y

  -- Zone 4: Bonus stats with scrollbar
  local filterZoneY = y
  local filterZoneBg = Geyser.Label:new({
    name = "W3.attr.filterZoneBg", x = 0, y = y, width = PW, height = 10,
  }, p)
  local bgPath3top = getMudletHomeDir() .. "/WuxiaGUI3/wuxia_attr_bg3_top.png"
  local fh3t = io.open(bgPath3top, "r")
  if fh3t then fh3t:close()
    filterZoneBg:setStyleSheet("border-image:url(" .. bgPath3top .. ") 0 0 0 0 stretch stretch;")
  else
    filterZoneBg:setStyleSheet("background-color:#1e1e35;")
  end

  local hdr3 = Geyser.Label:new({
    name = "W3.attr.bonusHdr", x = MX, y = y, width = GW, height = 18,
  }, p)
  hdr3:setStyleSheet("background-color:transparent;")
  hdr3:setFontSize(8)
  hdr3:echo('<div style="' .. SHADOW .. '">' .. span(GOLD, "── 附加屬性 ──") .. '</div>')
  y = y + 20

  local filterSources = {
    { key = "all",       label = "總計" },
    { key = "equipment", label = "裝備" },
    { key = "skillmix",  label = "技能" },
    { key = "jingmai",   label = "經脈" },
    { key = "yuanshen",  label = "元神" },
    { key = "ability",   label = "能力" },
    { key = "talent",    label = "天賦" },
    { key = "temp",      label = "暫時" },
  }
  WuxiaGUI3._buffsFilterSources = filterSources
  WuxiaGUI3._buffsFilterBtns = {}

  local btnW = math.floor(GW / 4)
  local btnH = 15
  for i, src in ipairs(filterSources) do
    local row = math.floor((i - 1) / 4)
    local col = (i - 1) % 4
    local btn = Geyser.Label:new({
      name = "W3.buffsFilter." .. src.key,
      x = MX + col * btnW, y = y + row * btnH,
      width = btnW, height = btnH,
    }, p)
    btn:setFontSize(8)
    btn:setClickCallback("WuxiaGUI3._onBuffsFilterClick", src.key)
    WuxiaGUI3._buffsFilterBtns[src.key] = btn
  end
  y = y + math.ceil(#filterSources / 4) * btnH + 2
  WuxiaGUI3._updateBuffsFilterBtns()

  y = makeLabel(p, "bonusStatsInfo", y, 14)

  local bonusListY = y
  WuxiaGUI3._bonusListY = bonusListY

  -- Resize card zone background to cover from hdr1 to banner3
  cardZoneBg:resize(PW, cardZoneEndY - cardZoneY)

  -- Resize filter zone background to cover from hdr3 to bonusList
  filterZoneBg:resize(PW, bonusListY - filterZoneY)
  WuxiaGUI3._attrParent = p
  local bonusListH = 300

  local bonusListLabel = Geyser.Label:new({
    name = "W3.attr.bonusList",
    x = 0, y = bonusListY, width = PW, height = bonusListH,
  }, p)
  local bgPath3bot = getMudletHomeDir() .. "/WuxiaGUI3/wuxia_attr_bg3_bot.png"
  local fh3b = io.open(bgPath3bot, "r")
  if fh3b then fh3b:close()
    bonusListLabel:setStyleSheet("border-image:url(" .. bgPath3bot .. ") 0 0 0 0 stretch stretch; qproperty-alignment: 'AlignLeft | AlignTop';")
  else
    bonusListLabel:setStyleSheet("background-color:#181830; qproperty-alignment: 'AlignLeft | AlignTop';")
  end
  bonusListLabel:setFontSize(9)
  WuxiaGUI3._bonusListLabel = bonusListLabel

  local sbTrack = Geyser.Label:new({
    name = "W3.attr.bonusSbTrack",
    x = PW - MX - 8, y = bonusListY + 2,
    width = 6, height = bonusListH - 4,
  }, p)
  sbTrack:setStyleSheet("background-color:rgba(30,15,8,0.6); border:1px solid #3a2a1a; border-radius:3px;")
  sbTrack:raiseAll()
  WuxiaGUI3._bonusSbTrack = sbTrack

  local sbThumb = Geyser.Label:new({
    name = "W3.attr.bonusSbThumb",
    x = 0, y = 0, width = "100%", height = 30,
  }, sbTrack)
  sbThumb:setStyleSheet("background-color:rgba(180,140,80,0.7); border-radius:3px;")
  sbThumb:raiseAll()
  WuxiaGUI3._bonusSbThumb = sbThumb

  -- Raise all elements above bonusList so scrolled content goes behind them
  local raiseList = {
    banner1, radarBg, radarOverlay, radarLabel, radarPoly,
    banner2, cardZoneBg, hdr1, card1, card2, card3, banner3, filterZoneBg, hdr3,
    sbTrack, sbThumb,
  }
  WuxiaGUI3._bonusRaiseList = raiseList
  for _, elem in ipairs(raiseList) do
    elem:raiseAll()
  end
  for _, btn in pairs(WuxiaGUI3._buffsFilterBtns) do
    btn:raiseAll()
  end

  WuxiaGUI3._bonusEntries = {}
  WuxiaGUI3._bonusScrollPx = 0
  WuxiaGUI3._bonusLineH = 18
  WuxiaGUI3._bonusSbThumbRelY = 0
  WuxiaGUI3._bonusSbThumbRelH = 30
  WuxiaGUI3._bonusSbDragging = false

  -- Dynamic resize handler for attributes tab
  WuxiaGUI3._repositionAttributes = function()
    local ap = WuxiaGUI3._attrParent
    if not ap then return end
    local containerH = ap:get_height()
    if containerH <= 0 then containerH = 800 end
    local bListY = WuxiaGUI3._bonusListY or 0
    local listH = containerH - bListY
    if listH < 80 then listH = 80 end
    local bl = WuxiaGUI3._bonusListLabel
    local st = WuxiaGUI3._bonusSbTrack
    if bl then bl:resize(nil, listH) end
    if st then
      st:move(nil, bListY + 2)
      st:resize(nil, listH - 4)
    end
    if WuxiaGUI3._renderBonusScroll then WuxiaGUI3._renderBonusScroll() end
  end

  -- Initial resize after layout settles
  tempTimer(0.2, function()
    if WuxiaGUI3._repositionAttributes then WuxiaGUI3._repositionAttributes() end
  end)

  local function totalContentH()
    local h = 0
    for _, e in ipairs(WuxiaGUI3._bonusEntries or {}) do h = h + e.h end
    return h
  end

  local function applyThumbY(newThumbY)
    local trackH = sbTrack:get_height()
    local thumbH = WuxiaGUI3._bonusSbThumbRelH or 30
    local maxThumbY = trackH - thumbH
    if maxThumbY <= 0 then return end
    newThumbY = math.max(0, math.min(maxThumbY, newThumbY))
    local labelH = bonusListLabel:get_height()
    if labelH <= 0 then labelH = 200 end
    local maxPx = math.max(0, totalContentH() - labelH)
    WuxiaGUI3._bonusScrollPx = math.floor(maxPx * newThumbY / maxThumbY + 0.5)
    WuxiaGUI3._renderBonusScroll()
  end

  sbThumb:setClickCallback(function(event)
    WuxiaGUI3._bonusSbDragging = true
    WuxiaGUI3._bonusSbDragStartGlobalY = event.globalY
    WuxiaGUI3._bonusSbDragStartThumbY = WuxiaGUI3._bonusSbThumbRelY or 0
  end)
  sbThumb:setMoveCallback(function(event)
    if not WuxiaGUI3._bonusSbDragging then return end
    local deltaY = event.globalY - WuxiaGUI3._bonusSbDragStartGlobalY
    applyThumbY(WuxiaGUI3._bonusSbDragStartThumbY + deltaY)
  end)
  sbThumb:setReleaseCallback(function()
    WuxiaGUI3._bonusSbDragging = false
  end)

  sbTrack:setClickCallback(function(event)
    local thumbY = WuxiaGUI3._bonusSbThumbRelY or 0
    local thumbH = WuxiaGUI3._bonusSbThumbRelH or 30
    if event.y >= thumbY and event.y <= thumbY + thumbH then return end
    local labelH = bonusListLabel:get_height()
    if labelH <= 0 then labelH = 200 end
    local maxPx = math.max(0, totalContentH() - labelH)
    if event.y < thumbY then
      WuxiaGUI3._bonusScrollPx = math.max(0, WuxiaGUI3._bonusScrollPx - labelH)
    else
      WuxiaGUI3._bonusScrollPx = math.min(maxPx, WuxiaGUI3._bonusScrollPx + labelH)
    end
    WuxiaGUI3._renderBonusScroll()
  end)
  sbTrack:setReleaseCallback(function() end)

  bonusListLabel:setWheelCallback(function(event)
    if not event then return end
    local delta = event.angleDeltaY or 0
    cecho("\n<cyan>BONUS_PARENT_WHEEL: delta=" .. tostring(delta) .. "<reset>\n")
    local step = 8  -- smooth pixel scroll step
    local labelH = bonusListLabel:get_height()
    if labelH <= 0 then labelH = 200 end
    local maxPx = math.max(0, totalContentH() - labelH)
    if delta > 0 then
      WuxiaGUI3._bonusScrollPx = math.max(0, WuxiaGUI3._bonusScrollPx - step)
    elseif delta < 0 then
      WuxiaGUI3._bonusScrollPx = math.min(maxPx, WuxiaGUI3._bonusScrollPx + step)
    end
    WuxiaGUI3._renderBonusScroll()
  end)
end

function WuxiaGUI3._onBuffsFilterClick(source)
  WuxiaGUI3._buffsActiveFilter = source
  WuxiaGUI3._updateBuffsFilterBtns()
  WuxiaGUI3._refreshBonusStats()
end

function WuxiaGUI3._updateBuffsFilterBtns()
  if not WuxiaGUI3._buffsFilterBtns then return end
  local active = WuxiaGUI3._buffsActiveFilter or "all"
  for _, src in ipairs(WuxiaGUI3._buffsFilterSources or {}) do
    local btn = WuxiaGUI3._buffsFilterBtns[src.key]
    if btn then
      if src.key == active then
        btn:setStyleSheet(string.format(
          "background-color: %s; border: 1px solid %s; qproperty-alignment: AlignCenter;",
          BG2, GOLD))
        btn:echo(span(GOLD, "<b>" .. src.label .. "</b>"))
      else
        btn:setStyleSheet(string.format(
          "background-color: %s; border: 1px solid %s; qproperty-alignment: AlignCenter;",
          BG, BORDER))
        btn:echo(span(TEXT_DIM, src.label))
      end
    end
  end
end


-- ═══════════════════════════════════════════════
-- § 4c  Tab: 技能 (Skills)
-- ═══════════════════════════════════════════════

-- Skill level description tables (match server-side skills.c)
-- martial/default: every 100 levels
WuxiaGUI3._skillLevelDesc = {
  { color = "#4444aa", text = "不堪一擊" },
  { color = "#4444aa", text = "毫不足慮" },
  { color = "#4444aa", text = "不足掛齒" },
  { color = "#4444aa", text = "初學乍練" },
  { color = "#4444aa", text = "勉勉強強" },
  { color = "#5555ff", text = "初窺門徑" },
  { color = "#5555ff", text = "初出茅廬" },
  { color = "#5555ff", text = "略知一二" },
  { color = "#5555ff", text = "普普通通" },
  { color = "#5555ff", text = "平平淡淡" },
  { color = "#00aaaa", text = "平淡無奇" },
  { color = "#00aaaa", text = "粗通皮毛" },
  { color = "#00aaaa", text = "半生不熟" },
  { color = "#00aaaa", text = "馬馬虎虎" },
  { color = "#00aaaa", text = "略有小成" },
  { color = "#55ffff", text = "已有小成" },
  { color = "#55ffff", text = "鶴立雞群" },
  { color = "#55ffff", text = "駕輕就熟" },
  { color = "#55ffff", text = "青出於藍" },
  { color = "#55ffff", text = "融會貫通" },
  { color = "#55ff55", text = "心領神會" },
  { color = "#55ff55", text = "爐火純青" },
  { color = "#55ff55", text = "瞭然於胸" },
  { color = "#55ff55", text = "略有大成" },
  { color = "#55ff55", text = "已有大成" },
  { color = "#aa5500", text = "豁然貫通" },
  { color = "#aa5500", text = "出類拔萃" },
  { color = "#aa5500", text = "無可匹敵" },
  { color = "#aa5500", text = "技冠群雄" },
  { color = "#aa5500", text = "神乎其技" },
  { color = "#ffff55", text = "出神入化" },
  { color = "#ffff55", text = "非同凡響" },
  { color = "#ffff55", text = "傲視群雄" },
  { color = "#ffff55", text = "登峰造極" },
  { color = "#ffff55", text = "無與倫比" },
  { color = "#aa0000", text = "所向披靡" },
  { color = "#aa0000", text = "一代宗師" },
  { color = "#aa0000", text = "精深奧妙" },
  { color = "#aa0000", text = "神功蓋世" },
  { color = "#aa0000", text = "舉世無雙" },
  { color = "#aaaaaa", text = "驚世駭俗" },
  { color = "#aaaaaa", text = "撼天動地" },
  { color = "#aaaaaa", text = "震古鑠今" },
  { color = "#aaaaaa", text = "超凡入聖" },
  { color = "#aaaaaa", text = "威鎮寰宇" },
  { color = "#ffffff", text = "空前絕後" },
  { color = "#ffffff", text = "天人合一" },
  { color = "#aa00aa", text = "深藏不露" },
  { color = "#ff55ff", text = "深不可測" },
  { color = "#ff5555", text = "返璞歸真" },
}

WuxiaGUI3._knowledgeLevelDesc = {
  { color = "#4444aa", text = "新學乍用" },
  { color = "#4444aa", text = "初窺門徑" },
  { color = "#5555ff", text = "略知一二" },
  { color = "#5555ff", text = "半生不熟" },
  { color = "#00aaaa", text = "馬馬虎虎" },
  { color = "#00aaaa", text = "已有小成" },
  { color = "#55ffff", text = "融會貫通" },
  { color = "#55ffff", text = "心領神會" },
  { color = "#00aa00", text = "瞭然於胸" },
  { color = "#00aa00", text = "豁然貫通" },
  { color = "#aa5500", text = "非同凡響" },
  { color = "#aa5500", text = "舉世無雙" },
  { color = "#ffff55", text = "震古鑠今" },
  { color = "#aa0000", text = "無與倫比" },
  { color = "#aaaaaa", text = "超凡入聖" },
  { color = "#ffffff", text = "空前絕後" },
}

WuxiaGUI3._basicSkills = {
  force=true, dodge=true, unarmed=true, leg=true,
  cuff=true, strike=true, finger=true, hand=true,
  claw=true, sword=true, blade=true, staff=true,
  hammer=true, club=true, stick=true, whip=true,
  hook=true, dagger=true, throwing=true, parry=true,
  magic=true, medical=true, poison=true, array=true,
  shooting=true, literate=true, training=true,
  ["martial-arts"]=true,
  ["chuixiao-jifa"]=true, ["tanqin-jifa"]=true,
  ["guzheng-jifa"]=true, cooking=true,
}

WuxiaGUI3._enableTypeNames = {
  unarmed="拳腳", sword="劍法", arrow="箭法", axe="斧法",
  blade="刀法", staff="杖法", hammer="錘法", club="棍法",
  spear="槍法", throwing="暗器", force="內功", parry="招架",
  dodge="輕功", magic="法術", whip="鞭法", dagger="短兵",
  finger="指法", hand="手法", cuff="拳法", claw="爪法",
  strike="掌法", medical="醫術", poison="毒技", cooking="廚藝",
  array="陣法", taoism="道術", shooting="弓術",
  leg="腿法", stick="棒法", hook="鉤法",
  ["chuixiao-jifa"]="吹蕭", ["guzheng-jifa"]="古箏",
  ["tanqin-jifa"]="彈琴",
}

function WuxiaGUI3._getSkillLevelInfo(skillType, level)
  level = tonumber(level) or 0
  local desc, grade
  if skillType == "knowledge" then
    grade = math.floor(level / 200)
    desc = WuxiaGUI3._knowledgeLevelDesc
  else
    grade = math.floor(level / 100)
    desc = WuxiaGUI3._skillLevelDesc
  end
  if grade < 0 then grade = 0 end
  if grade >= #desc then grade = #desc - 1 end
  local entry = desc[grade + 1]
  return entry.text, entry.color
end

function WuxiaGUI3._computeEffective(slot)
  -- Effective = floor((add_skill_buff + base_skill) / 2) + (add_skill_buff + special_skill)
  local sd = WuxiaGUI3.skillData or {}
  local skillMap = sd.skill_map or {}
  local allSkills = sd.skills or {}

  local specialId = skillMap[slot]
  if not specialId then return 0 end

  local baseLvl = tonumber(allSkills[slot]) or 0
  local specLvl = tonumber(allSkills[specialId]) or 0
  local addBuff = 0
  local buffs = WuxiaGUI3.buffs or {}
  for _, srcData in pairs(buffs) do
    if type(srcData) == "table" and srcData["add_skill"] then
      addBuff = addBuff + (tonumber(srcData["add_skill"]) or 0)
    end
  end
  return math.floor((addBuff + baseLvl) / 2) + (addBuff + specLvl)
end

function WuxiaGUI3._skillCategory(skillId, skillType)
  if skillType == "knowledge" then return "knowledge"
  elseif WuxiaGUI3._basicSkills[skillId] then return "basic"
  elseif skillType == "martial" or skillType == "poison" then return "martial"
  else return "other" end
end

-- ─── Skill card builder ───
-- Returns: innerHtml, cardBg, cardBorder, barInfo
-- innerHtml: name line only (bar is rendered via Geyser sub-labels)
-- barInfo: {color, pct, levelText, xpText} for the progress bar sub-labels
function WuxiaGUI3._buildSkillCardHtml(sk, enabledAs, preparedAs, progressOverride, flashBg, levelOverride)
  local displayLevel = levelOverride or sk.raw
  local descText, descColor = WuxiaGUI3._getSkillLevelInfo(sk.type, displayLevel)
  local nextReq = (displayLevel + 1) * (displayLevel + 1)
  local progress = progressOverride or sk.learnedXP
  local progressPct = 0
  if nextReq > 0 then progressPct = math.floor(progress / nextReq * 100) end
  progressPct = math.max(0, math.min(100, progressPct))
  local canLvl = (sk.learnedXP > (sk.raw + 1) * (sk.raw + 1))

  local badges = ""
  if enabledAs and enabledAs[sk.id] then
    for _, slot in ipairs(enabledAs[sk.id]) do
      local sn = WuxiaGUI3._enableTypeNames[slot] or slot
      badges = badges .. ' <span style="color:#c8a050;">★'..sn..'</span>'
    end
  end
  if preparedAs and preparedAs[sk.id] then
    for _, slot in ipairs(preparedAs[sk.id]) do
      local sn = WuxiaGUI3._enableTypeNames[slot] or slot
      badges = badges .. ' <span style="color:#8888aa;">◇備'..sn..'</span>'
    end
  end

  local lvlUpIcon = canLvl and ' <span style="color:#ffff55;">▲</span>' or ""

  local cardBg = flashBg or "rgba(17,17,28,160)"
  local cardBorder = flashBg and "#e8c170" or "#2a2a50"

  local levelText = '等級 '..tostring(displayLevel)..' '..descText..lvlUpIcon
  local xpText = tostring(math.floor(progress))..' / '..tostring(nextReq)

  local innerHtml =
         '<span style="color:'..descColor..';">'..sk.name..'</span>' ..
         ' <span style="color:#666;">('..sk.id..')</span>'..badges

  local barInfo = {
    color = descColor,
    pct = progressPct,
    levelText = levelText,
    xpText = xpText,
  }

  return innerHtml, cardBg, cardBorder, barInfo
end

-- ─── Skill card animation system ───
-- Kill all active skill card animations and clear queue
function WuxiaGUI3._killSkillAnims()
  if WuxiaGUI3._skillAnimTimer then
    killTimer(WuxiaGUI3._skillAnimTimer)
    WuxiaGUI3._skillAnimTimer = nil
  end
  WuxiaGUI3._skillAnimQueue = nil
  WuxiaGUI3._skillAnimIdx = nil
  WuxiaGUI3._skillAnimCurrent = nil
end

-- Scroll the skill list so that entry at entryIdx is visible (instant scroll)
function WuxiaGUI3._scrollSkillEntryIntoView(entryIdx)
  local entries = WuxiaGUI3._skillEntries or {}
  if not entries[entryIdx] then return end
  local label = WuxiaGUI3._skillListLabel
  if not label then return end
  local labelH = label:get_height()
  if labelH <= 0 then labelH = 200 end

  -- Calculate cumulative height to the target entry
  local cumH = 0
  for i = 1, entryIdx - 1 do
    cumH = cumH + (entries[i] and entries[i].h or 0)
  end
  local entryH = entries[entryIdx].h or 0

  -- Calculate total content height
  local totalH = 0
  for _, e in ipairs(entries) do totalH = totalH + e.h end
  local maxPx = math.max(0, totalH - labelH)

  -- Try to center the entry in the viewport; clamp to valid range
  local targetPx = cumH - math.floor((labelH - entryH) / 2)
  targetPx = math.max(0, math.min(maxPx, targetPx))
  WuxiaGUI3._skillScrollPx = targetPx
end

-- Start skill card level-up animations for upgraded entries (sequential, top-to-bottom)
-- upgradedEntries: array of { skId, entryIdx, skData, enabledAs, preparedAs, oldLevel, oldLearned, newLevel, newLearned }
function WuxiaGUI3._startSkillAnims(upgradedEntries)
  WuxiaGUI3._killSkillAnims()
  if not upgradedEntries or #upgradedEntries == 0 then return end

  -- Sort by entryIdx (top-to-bottom order)
  table.sort(upgradedEntries, function(a, b) return a.entryIdx < b.entryIdx end)

  WuxiaGUI3._skillAnimQueue = upgradedEntries
  WuxiaGUI3._skillAnimIdx = 1

  -- Begin the first animation
  WuxiaGUI3._beginNextSkillAnim()
end

-- Begin animating the next entry in the queue
function WuxiaGUI3._beginNextSkillAnim()
  local queue = WuxiaGUI3._skillAnimQueue
  local idx = WuxiaGUI3._skillAnimIdx
  if not queue or not idx or idx > #queue then
    -- All done
    WuxiaGUI3._killSkillAnims()
    if WuxiaGUI3._renderSkillScroll then
      WuxiaGUI3._renderSkillScroll()
    end
    return
  end

  local info = queue[idx]
  -- Scroll this entry into view
  WuxiaGUI3._scrollSkillEntryIntoView(info.entryIdx)

  -- Set up current animation state
  WuxiaGUI3._skillAnimCurrent = {
    entryIdx   = info.entryIdx,
    skData     = info.skData,
    enabledAs  = info.enabledAs,
    preparedAs = info.preparedAs,
    oldLevel   = info.oldLevel,
    oldLearned = info.oldLearned,
    newLevel   = info.newLevel,
    newLearned = info.newLearned,
    phase      = "fill",    -- "fill" -> "flash" -> "refill" -> "done"
    startTime  = os.clock(),
  }

  -- Start tick loop
  WuxiaGUI3._tickSkillAnims()
end

-- Animation tick function (called at ~60fps during animation)
-- Processes ONE entry at a time; advances queue when done.
function WuxiaGUI3._tickSkillAnims()
  local anim = WuxiaGUI3._skillAnimCurrent
  if not anim then return end

  local entries = WuxiaGUI3._skillEntries or {}
  local entry = entries[anim.entryIdx]

  if not entry then
    -- Entry disappeared; skip to next
    anim.phase = "done"
  end

  if anim.phase ~= "done" then
    local now = os.clock()
    local elapsed = now - anim.startTime
    local sk = anim.skData

    if anim.phase == "fill" then
      -- Phase 1: Fill progress bar from old progress to 100% (0.6s)
      local oldNextReq = (anim.oldLevel + 1) * (anim.oldLevel + 1)
      local t = math.min(elapsed / 0.6, 1)
      t = 1 - (1 - t) ^ 3  -- ease-out cubic
      local progress = anim.oldLearned + (oldNextReq - anim.oldLearned) * t
      entry.html, entry.cardBg, entry.cardBorder, entry.barInfo = WuxiaGUI3._buildSkillCardHtml(
        sk, anim.enabledAs, anim.preparedAs, progress, nil, anim.oldLevel)
      if elapsed >= 0.6 then
        anim.phase = "flash"
        anim.startTime = now
      end

    elseif anim.phase == "flash" then
      -- Phase 2: Flash card background golden, show new level (0.4s)
      local t = math.min(elapsed / 0.4, 1)
      local flashBg
      if t < 0.5 then
        flashBg = "rgba(42,37,16,200)"  -- golden tint
      else
        flashBg = nil  -- fade back to normal
      end
      entry.html, entry.cardBg, entry.cardBorder, entry.barInfo = WuxiaGUI3._buildSkillCardHtml(
        sk, anim.enabledAs, anim.preparedAs, 0, flashBg, anim.newLevel)
      if elapsed >= 0.4 then
        anim.phase = "refill"
        anim.startTime = now
      end

    elseif anim.phase == "refill" then
      -- Phase 3: Fill progress bar from 0 to new progress (0.6s)
      local t = math.min(elapsed / 0.6, 1)
      t = 1 - (1 - t) ^ 3  -- ease-out cubic
      local progress = anim.newLearned * t
      entry.html, entry.cardBg, entry.cardBorder, entry.barInfo = WuxiaGUI3._buildSkillCardHtml(
        sk, anim.enabledAs, anim.preparedAs, progress)
      if elapsed >= 0.6 then
        -- Final state with actual values
        entry.html, entry.cardBg, entry.cardBorder, entry.barInfo = WuxiaGUI3._buildSkillCardHtml(
          sk, anim.enabledAs, anim.preparedAs)
        anim.phase = "done"
      end
    end
  end

  -- Re-render the scroll to show updated card
  if WuxiaGUI3._renderSkillScroll then
    WuxiaGUI3._renderSkillScroll()
  end

  if anim.phase ~= "done" then
    WuxiaGUI3._skillAnimTimer = tempTimer(0.016, WuxiaGUI3._tickSkillAnims)
  else
    -- Current entry done, advance to next in queue
    WuxiaGUI3._skillAnimTimer = nil
    WuxiaGUI3._skillAnimCurrent = nil
    WuxiaGUI3._skillAnimIdx = (WuxiaGUI3._skillAnimIdx or 1) + 1
    WuxiaGUI3._beginNextSkillAnim()
  end
end

function WuxiaGUI3._buildSkills()
  local p = WuxiaGUI3.tabContainers["技能"]
  local imgDir = getMudletHomeDir() .. "/WuxiaGUI3/"
  local topPath = imgDir .. "wuxia_skills_top.png"
  local bg1Path = imgDir .. "wuxia_skills_1.png"
  local bg2Path = imgDir .. "wuxia_skills_2.png"
  local bg3Path = imgDir .. "wuxia_skills_3.png"
  local botPath = imgDir .. "wuxia_skills_bottom.png"
  local topH = 50     -- top frame height (unchanged)
  local bg1H = 330    -- fixed height for top section (激發技能 + 預備技能)
  local bg2H = 30     -- fixed height for filter section
  local bg3H = 800    -- minimum height for skill cards bg (stretches if more space)
  local botH = 25     -- bottom frame height
  local MIN_LIST_H = 120  -- minimum skill card list height before clipping
  local CX = 20
  local CW = PW - CX * 2
  local SB_RIGHT = 18    -- scrollbar right-edge inset from panel edge (increase to shift right)
  local SB_SHRINK = 20  -- total pixels shorter than list (split top/bottom)
  local SHADOW = "text-shadow:1px 1px 3px #000, 0px 0px 6px #000;"
  local fh

  -- Store layout constants for reflow
  WuxiaGUI3._skillCX = CX
  WuxiaGUI3._skillCW = CW
  WuxiaGUI3._skillTopH = topH
  WuxiaGUI3._skillBg1H = bg1H
  WuxiaGUI3._skillBg2H = bg2H
  WuxiaGUI3._skillBg3H = bg3H
  WuxiaGUI3._skillBotH = botH
  WuxiaGUI3._skillMinListH = MIN_LIST_H
  WuxiaGUI3._skillSbRight = SB_RIGHT
  WuxiaGUI3._skillSbShrink = SB_SHRINK
  WuxiaGUI3._skillSHADOW = SHADOW

  -- ─── Layer 1: Three distinct backgrounds (below the top frame) ───
  -- bg1: top section (激發技能 + 預備技能) – fixed height
  local bg1Label = Geyser.Label:new({
    name="W3.skill.bg1", x=0, y=topH, width=PW, height=bg1H,
  }, p)
  fh = io.open(bg1Path, "r")
  if fh then fh:close()
    bg1Label:setStyleSheet("background-color:transparent; border-image:url("..bg1Path..") 0 0 0 0 stretch stretch;")
  else bg1Label:setStyleSheet("background-color:#0a0806;") end
  WuxiaGUI3._skillBg1 = bg1Label

  -- bg2: filter section – fixed height
  local bg2Label = Geyser.Label:new({
    name="W3.skill.bg2", x=0, y=topH+bg1H, width=PW, height=bg2H,
  }, p)
  fh = io.open(bg2Path, "r")
  if fh then fh:close()
    bg2Label:setStyleSheet("background-color:transparent; border-image:url("..bg2Path..") 0 0 0 0 stretch stretch;")
  else bg2Label:setStyleSheet("background-color:#0a0806;") end
  WuxiaGUI3._skillBg2 = bg2Label

  -- bg3: skill cards list – fixed height
  local bg3Label = Geyser.Label:new({
    name="W3.skill.bg3", x=0, y=topH+bg1H+bg2H, width=PW, height=bg3H,
  }, p)
  fh = io.open(bg3Path, "r")
  if fh then fh:close()
    bg3Label:setStyleSheet("background-color:transparent; border-image:url("..bg3Path..") 0 0 0 0 stretch stretch;")
  else bg3Label:setStyleSheet("background-color:#0a0806;") end
  WuxiaGUI3._skillBg3 = bg3Label

  -- Bottom frame – sits on top of cards, fixed at bottom of available space
  local botLabel = Geyser.Label:new({
    name="W3.skill.frameBot", x=0, y=0, width=PW, height=botH,
  }, p)
  fh = io.open(botPath, "r")
  if fh then fh:close()
    botLabel:setStyleSheet("background-color:transparent; border-image:url("..botPath..") 0 0 0 0 stretch stretch;")
  else botLabel:setStyleSheet("background-color:#1a1008;") end
  WuxiaGUI3._skillBotLabel = botLabel

  -- ─── Layer 2: Content widgets (all stored for reflow) ───
  local y = topH + 8
  local baseY = y  -- first widget starts here

  -- Summary line
  local summaryLbl = Geyser.Label:new({
    name="W3.skill.summary", x=CX, y=y, width=CW, height=18,
  }, p)
  summaryLbl:setStyleSheet("background-color:transparent;")
  summaryLbl:setFontSize(9)
  summaryLbl:echo(span(TEXT_DIM, "等待技能資料..."))
  summaryLbl:raiseAll()
  WuxiaGUI3._skillSummaryLbl = summaryLbl

  -- Enable header
  local enableHdr = Geyser.Label:new({
    name="W3.skill.enableHdr", x=CX, y=0, width=CW, height=16,
  }, p)
  enableHdr:setStyleSheet("background-color:transparent;")
  enableHdr:setFontSize(8)
  enableHdr:echo('<div style="'..SHADOW..'">' .. span(GOLD, "── 激發技能 ──") .. '</div>')
  enableHdr:raiseAll()
  WuxiaGUI3._skillEnableHdr = enableHdr

  -- Enable container (height set dynamically during refresh)
  local enableContainer = Geyser.Label:new({
    name="W3.skill.enableContainer", x=CX, y=0, width=CW, height=10,
  }, p)
  enableContainer:setStyleSheet("background-color:transparent;")
  enableContainer:raiseAll()
  WuxiaGUI3._skillEnableContainer = enableContainer
  WuxiaGUI3._skillEnableBoxes = {}

  -- Prepare header
  local prepHdr = Geyser.Label:new({
    name="W3.skill.prepHdr", x=CX, y=0, width=CW, height=16,
  }, p)
  prepHdr:setStyleSheet("background-color:transparent;")
  prepHdr:setFontSize(8)
  prepHdr:echo('<div style="'..SHADOW..'">' .. span(GOLD, "── 預備技能 ──") .. '</div>')
  prepHdr:raiseAll()
  WuxiaGUI3._skillPrepHdr = prepHdr

  -- Prepare container (for prepare boxes)
  local prepContainer = Geyser.Label:new({
    name="W3.skill.prepContainer", x=CX, y=0, width=CW, height=10,
  }, p)
  prepContainer:setStyleSheet("background-color:transparent;")
  prepContainer:raiseAll()
  WuxiaGUI3._skillPrepContainer = prepContainer
  WuxiaGUI3._skillPrepBoxes = {}

  -- Category filter tabs
  local filterCats = {
    {key="all", label="全部"}, {key="knowledge", label="知識"},
    {key="basic", label="基本"}, {key="martial", label="特殊"},
    {key="other", label="其它"},
  }
  WuxiaGUI3._skillFilterCats = filterCats
  WuxiaGUI3._skillsActiveFilter = "all"
  WuxiaGUI3._skillFilterBtns = {}
  local btnW = math.floor(CW / #filterCats)
  local btnH = 20
  for i, cat in ipairs(filterCats) do
    local btn = Geyser.Label:new({
      name="W3.skillFilter."..cat.key,
      x=CX+(i-1)*btnW, y=0, width=btnW, height=btnH,
    }, p)
    btn:setFontSize(8)
    local catKey = cat.key
    btn:setClickCallback(function() WuxiaGUI3._onSkillFilterClick(catKey) end)
    btn:raiseAll()
    WuxiaGUI3._skillFilterBtns[cat.key] = btn
  end
  WuxiaGUI3._skillBtnH = btnH
  WuxiaGUI3._updateSkillFilterBtns()

  -- Scrollable skill list
  local skillListBg = Geyser.Label:new({
    name="W3.skillListBg", x=CX, y=0, width=CW, height=100,
  }, p)
  skillListBg:setStyleSheet("background-color:transparent;")
  skillListBg:raiseAll()
  WuxiaGUI3._skillListBg = skillListBg

  local skillListLabel = Geyser.Label:new({
    name="W3.skillList", x=CX, y=0, width=CW-8, height=100,
  }, p)
  skillListLabel:setStyleSheet("background-color:transparent;")
  skillListLabel:raiseAll()
  WuxiaGUI3._skillListLabel = skillListLabel
  WuxiaGUI3._skillScrollPx = 0
  WuxiaGUI3._skillEntries = {}
  WuxiaGUI3._skillLineH = 22

  -- Inner label for smooth scroll clipping (same technique as 屬性 bonus scroll)
  -- Parent (skillListLabel) clips this inner label at its boundary edges
  local skillInnerLabel = Geyser.Label:new({
    name = "W3.skillInner",
    x = 0, y = 0, width = "100%", height = 100,
  }, skillListLabel)
  skillInnerLabel:setStyleSheet("background-color:transparent; qproperty-alignment:'AlignLeft|AlignTop';")
  skillListLabel:echo("")
  WuxiaGUI3._skillInnerLabel = skillInnerLabel

  -- Card label pool: individual Geyser Labels for each visible card (enables border-radius)
  -- Each card gets 3 bar sub-labels: barBg, barFill, barText (for rounded progress bar)
  local POOL_SIZE = 20
  local BAR_H = 18
  local cardPool = {}
  for ci = 1, POOL_SIZE do
    local cl = Geyser.Label:new({
      name = "W3.skillCard."..ci, x = 0, y = 0, width = "100%", height = 20,
    }, skillInnerLabel)
    cl:setStyleSheet("background-color:transparent;")
    cl:setFontSize(9)
    cl:hide()

    -- Bar background (full width, sits at bottom of card)
    local barBg = Geyser.Label:new({
      name = "W3.skillCard."..ci..".barBg", x = 2, y = 0, width = "-4px", height = BAR_H,
    }, cl)
    barBg:setStyleSheet("background-color:#1a1a30; border-radius:3px;")
    barBg:hide()

    -- Bar fill (left-aligned, variable width)
    local barFill = Geyser.Label:new({
      name = "W3.skillCard."..ci..".barFill", x = 0, y = 0, width = 0, height = "100%",
    }, barBg)
    barFill:setStyleSheet("background-color:#4488ff; border-radius:3px;")
    barFill:hide()

    -- Bar text overlay (transparent, full width, on top)
    local barText = Geyser.Label:new({
      name = "W3.skillCard."..ci..".barText", x = 0, y = 0, width = "100%", height = "100%",
    }, barBg)
    barText:setStyleSheet("background-color:transparent; qproperty-alignment:'AlignLeft|AlignVCenter';")
    barText:setFontSize(8)
    barText:raiseAll()
    barText:hide()

    cl._barBg = barBg
    cl._barFill = barFill
    cl._barText = barText
    cardPool[ci] = cl
  end
  WuxiaGUI3._skillCardPool = cardPool
  WuxiaGUI3._skillBarH = BAR_H

  -- Scrollbar track
  local sbTrack = Geyser.Label:new({
    name="W3.skillSbTrack", x=PW-CX-4, y=0, width=6, height=100,
  }, p)
  sbTrack:setStyleSheet("background-color:rgba(30,15,8,0.6); border:1px solid #3a2a1a; border-radius:3px;")
  sbTrack:raiseAll()
  WuxiaGUI3._skillSbTrack = sbTrack

  local sbThumb = Geyser.Label:new({
    name="W3.skillSbThumb", x=0, y=0, width="100%", height=30,
  }, sbTrack)
  sbThumb:setStyleSheet("background-color:rgba(180,140,80,0.7); border-radius:3px;")
  sbThumb:raiseAll()
  WuxiaGUI3._skillSbThumb = sbThumb
  WuxiaGUI3._skillSbDragging = false

  -- ─── Reflow function: positions all widgets based on dynamic enable/prepare heights ───
  function WuxiaGUI3._reflowSkillLayout()
    local CX2 = WuxiaGUI3._skillCX
    local CW2 = WuxiaGUI3._skillCW
    local tH = WuxiaGUI3._skillTopH
    local prepVisible = WuxiaGUI3._skillPrepVisible or false

    -- Simple top-down layout: each section gets its natural height
    local y2 = tH + 8

    -- Summary (fixed 20px)
    WuxiaGUI3._skillSummaryLbl:move(CX2, y2); y2 = y2 + 20

    -- Enable header (fixed 18px)
    WuxiaGUI3._skillEnableHdr:move(CX2, y2); y2 = y2 + 18

    -- Enable container (natural height from refresh)
    local enableH = WuxiaGUI3._skillEnableContainer:get_height()
    if enableH <= 0 then enableH = 10 end
    WuxiaGUI3._skillEnableContainer:move(CX2, y2); y2 = y2 + enableH + 4

    -- Prepare section (only if visible)
    if prepVisible then
      WuxiaGUI3._skillPrepHdr:move(CX2, y2); y2 = y2 + 18
      local prepH = WuxiaGUI3._skillPrepContainer:get_height()
      if prepH <= 0 then prepH = 10 end
      WuxiaGUI3._skillPrepContainer:move(CX2, y2); y2 = y2 + prepH + 4
    end

    -- Move the filter buttons down to compensate for the separator bar in bg1
    y2 = y2 + 19
    -- Filter buttons
    local btnW2 = math.floor(CW2 / 5)
    local btnH2 = WuxiaGUI3._skillBtnH or 20
    local i2 = 0
    for _, cat in ipairs(WuxiaGUI3._skillFilterCats) do
      local btn = WuxiaGUI3._skillFilterBtns[cat.key]
      if btn then btn:move(CX2 + i2 * btnW2, y2) end
      i2 = i2 + 1
    end
    y2 = y2 + btnH2 + 2

    -- Skill list area
    local containerH = p:get_height()
    if containerH <= 0 then containerH = 600 end
    local b3H = WuxiaGUI3._skillBg3H
    local bH = WuxiaGUI3._skillBotH
    local minLH = WuxiaGUI3._skillMinListH

    -- bg3: minimum b3H, stretch if more space available
    local availBg3 = containerH - y2
    local effBg3H = math.max(b3H, availBg3)
    if WuxiaGUI3._skillBg3 then
      WuxiaGUI3._skillBg3:move(0, y2)
      WuxiaGUI3._skillBg3:resize(PW, effBg3H)
    end

    -- Push skill card content down within bg3
    local CARD_TOP_PAD = 8  -- extra top padding for card list inside bg3
    y2 = y2 + CARD_TOP_PAD

    -- Available space for cards: from y2 to container bottom
    local naturalListH = containerH - y2
    -- Enforce minimum: if too small, content extends past container (clips)
    local listH = math.max(minLH, naturalListH)

    if WuxiaGUI3._skillListBg then
      WuxiaGUI3._skillListBg:move(CX2, y2)
      WuxiaGUI3._skillListBg:resize(CW2, listH)
    end
    WuxiaGUI3._skillListLabel:move(CX2, y2)
    WuxiaGUI3._skillListLabel:resize(CW2 - 8, listH)
    local sbR = WuxiaGUI3._skillSbRight or 6
    local sbSh = WuxiaGUI3._skillSbShrink or 20
    local sbPad = math.floor(sbSh / 2)
    WuxiaGUI3._skillSbTrack:move(PW - sbR, y2 + sbPad)
    WuxiaGUI3._skillSbTrack:resize(nil, listH - sbSh)

    -- Bottom frame: decorative, at bottom of container (clips with content)
    if WuxiaGUI3._skillBotLabel then
      WuxiaGUI3._skillBotLabel:move(0, containerH - bH)
      WuxiaGUI3._skillBotLabel:resize(PW, bH)
    end

    if WuxiaGUI3._renderSkillScroll then WuxiaGUI3._renderSkillScroll() end
  end

  -- ─── totalContentH (closure for scroll) ───
  local function totalContentH()
    local h = 0
    for _, e in ipairs(WuxiaGUI3._skillEntries or {}) do h = h + e.h end
    return h
  end

  -- ─── Scrollbar drag (per SCROLLBAR_PATTERN.md) ───
  sbThumb:setClickCallback(function(event)
    WuxiaGUI3._skillSbDragging = true
    WuxiaGUI3._skillSbDragStartGlobalY = event.globalY
    WuxiaGUI3._skillSbDragStartThumbY = WuxiaGUI3._skillSbThumbRelY or 0
  end)
  sbThumb:setMoveCallback(function(event)
    if not WuxiaGUI3._skillSbDragging then return end
    local deltaY = event.globalY - WuxiaGUI3._skillSbDragStartGlobalY
    local newThumbY = WuxiaGUI3._skillSbDragStartThumbY + deltaY
    local trackH = sbTrack:get_height()
    local thumbH = WuxiaGUI3._skillSbThumbRelH or 30
    local maxThumbY = trackH - thumbH
    if maxThumbY <= 0 then return end
    newThumbY = math.max(0, math.min(maxThumbY, newThumbY))
    local labelH = WuxiaGUI3._skillListLabel:get_height()
    if labelH <= 0 then labelH = 200 end
    local maxPx = math.max(0, totalContentH() - labelH)
    WuxiaGUI3._skillScrollPx = math.floor(maxPx * newThumbY / maxThumbY + 0.5)
    WuxiaGUI3._renderSkillScroll()
  end)
  sbThumb:setReleaseCallback(function()
    WuxiaGUI3._skillSbDragging = false
  end)

  -- ─── Scroll rendering (inner-label technique, same as 屬性 bonus scroll) ───
  -- Pool labels are children of skillInnerLabel, which is a child of skillListLabel.
  -- Scrolling moves skillInnerLabel; skillListLabel clips at its boundary.
  function WuxiaGUI3._renderSkillScroll()
    local entries = WuxiaGUI3._skillEntries or {}
    local label = WuxiaGUI3._skillListLabel
    local inner = WuxiaGUI3._skillInnerLabel
    local pool = WuxiaGUI3._skillCardPool or {}
    if not label or not inner then return end

    local labelH = label:get_height()
    if labelH <= 0 then labelH = 200 end

    if #entries == 0 then
      for _, pl in ipairs(pool) do
        pl:hide()
        if pl._barBg then pl._barBg:hide() end
      end
      -- Show placeholder via first pool label
      if pool[1] then
        pool[1]:setStyleSheet("background-color:transparent; qproperty-alignment:'AlignHCenter|AlignVCenter';")
        pool[1]:echo(span(TEXT_DIM, "等待資料..."))
        pool[1]:move(0, 0)
        pool[1]:resize("100%", labelH)
        pool[1]:show()
      end
      inner:move(0, -labelH)
      inner:resize("100%", labelH)
      if WuxiaGUI3._skillSbTrack then WuxiaGUI3._skillSbTrack:hide() end
      return
    end

    local contentH = totalContentH()
    local maxPx = math.max(0, contentH - labelH)
    WuxiaGUI3._skillScrollPx = math.max(0, math.min(WuxiaGUI3._skillScrollPx, maxPx))
    local scrollPx = WuxiaGUI3._skillScrollPx

    -- Move and resize inner label (negative Y = from bottom of parent in Geyser)
    -- y = -labelH means top of inner = top of parent; subtracting scrollPx shifts up
    inner:move(0, -labelH - scrollPx)
    inner:resize("100%", contentH)

    local poolIdx = 0
    local cumH = 0
    local GAP = 3  -- gap between cards
    local barH = WuxiaGUI3._skillBarH or 18

    for _, e in ipairs(entries) do
      local entryTop = cumH
      local entryBot = cumH + e.h
      if entryBot > scrollPx and entryTop < scrollPx + labelH then
        poolIdx = poolIdx + 1
        if poolIdx > #pool then break end
        local pl = pool[poolIdx]

        -- Natural card height (excluding inter-card gap)
        local naturalH = e.cardBg and (e.h - GAP) or e.h

        local newSS
        if e.cardBg then
          newSS = "background-color:" .. e.cardBg .. "; " ..
            "border:1px solid " .. e.cardBorder .. "; " ..
            "border-radius:3px; " ..
            "padding:4px 4px 2px 4px; " ..
            "qproperty-alignment:'AlignLeft|AlignTop'; qproperty-wordWrap:true;"
        else
          newSS = "background-color:transparent; " ..
            "qproperty-alignment:'AlignLeft|AlignTop'; qproperty-wordWrap:true;"
        end

        -- Position at absolute entryTop within inner label (not relative to viewport)
        -- Parent clipping handles the partial visibility at scroll edges
        pl:move(0, entryTop)
        pl:resize("100%", naturalH)
        if pl._lastSS ~= newSS then
          pl:setStyleSheet(newSS)
          pl._lastSS = newSS
        end
        pl:echo('<div style="font-size:9pt; '..SHADOW..' line-height:14px; word-wrap:break-word;">' .. (e.html or "") .. '</div>')
        pl:show()

        -- Bar sub-labels at natural positions (always within card bounds)
        if e.barInfo and pl._barBg then
          local bi = e.barInfo
          local barY = naturalH - barH - 4
          if barY < 0 then barY = 0 end
          pl._barBg:move(2, barY)
          pl._barBg:resize("-6px", barH)
          pl._barBg:setStyleSheet("background-color:#1a1a30; border-radius:3px;")
          pl._barBg:show()

          -- Fill width
          local fillW = math.max(0, math.min(100, bi.pct))
          if fillW > 0 then
            pl._barFill:resize(tostring(fillW).."%", "100%")
            pl._barFill:move(0, 0)
            local fillSS = "background-color:" .. bi.color .. "; border-radius:3px;"
            if pl._barFill._lastSS ~= fillSS then
              pl._barFill:setStyleSheet(fillSS)
              pl._barFill._lastSS = fillSS
            end
            pl._barFill:show()
          else
            pl._barFill:hide()
          end

          -- Text overlay
          pl._barText:echo(
            '<div style="font-size:8pt; '..SHADOW..'">' ..
            '<table width="100%" cellspacing="0" cellpadding="0"><tr>' ..
              '<td style="padding-left:6px;"><span style="color:#cccccc;">' .. bi.levelText .. '</span></td>' ..
              '<td align="right" style="padding-right:4px;"><span style="color:#999999; font-size:7pt;">' .. bi.xpText .. '</span></td>' ..
            '</tr></table></div>')
          pl._barText:show()
          pl._barText:raiseAll()
        elseif pl._barBg then
          pl._barBg:hide()
        end
      end
      cumH = entryBot
      if cumH > scrollPx + labelH then break end
    end

    -- Hide unused pool labels
    for i = poolIdx + 1, #pool do
      pool[i]:hide()
      if pool[i]._barBg then pool[i]._barBg:hide() end
    end

    -- Re-raise mask layers above cards so they cover overflow
    if WuxiaGUI3._skillBg1 then WuxiaGUI3._skillBg1:raiseAll() end
    if WuxiaGUI3._skillBg2 then WuxiaGUI3._skillBg2:raiseAll() end
    if WuxiaGUI3._skillBotLabel then WuxiaGUI3._skillBotLabel:raiseAll() end
    if WuxiaGUI3._skillTopLabel then WuxiaGUI3._skillTopLabel:raiseAll() end
    -- Re-raise interactive widgets above masks
    if WuxiaGUI3._skillSummaryLbl then WuxiaGUI3._skillSummaryLbl:raiseAll() end
    if WuxiaGUI3._skillEnableHdr then WuxiaGUI3._skillEnableHdr:raiseAll() end
    if WuxiaGUI3._skillEnableContainer then WuxiaGUI3._skillEnableContainer:raiseAll() end
    if WuxiaGUI3._skillPrepHdr then WuxiaGUI3._skillPrepHdr:raiseAll() end
    if WuxiaGUI3._skillPrepContainer then WuxiaGUI3._skillPrepContainer:raiseAll() end
    for _, cat in ipairs(WuxiaGUI3._skillFilterCats or {}) do
      local btn = WuxiaGUI3._skillFilterBtns[cat.key]
      if btn then btn:raiseAll() end
    end

    -- Scrollbar
    if WuxiaGUI3._skillSbTrack then
      if contentH <= labelH then
        WuxiaGUI3._skillSbTrack:hide()
      else
        WuxiaGUI3._skillSbTrack:show()
        local trackH = WuxiaGUI3._skillSbTrack:get_height()
        local thumbRatio = labelH / contentH
        local tH = math.max(16, math.floor(trackH * thumbRatio))
        local tY = 0
        if maxPx > 0 then tY = math.floor((trackH - tH) * (scrollPx / maxPx)) end
        WuxiaGUI3._skillSbThumb:resize(nil, tH)
        WuxiaGUI3._skillSbThumb:move(0, tY)
        WuxiaGUI3._skillSbThumbRelY = tY
        WuxiaGUI3._skillSbThumbRelH = tH
      end
    end
  end

  -- Mouse wheel handler (shared by container and all pool cards)
  local function skillWheelHandler(event)
    if not event then return end
    local delta = event.angleDeltaY or 0
    local step = WuxiaGUI3._skillLineH * 3
    local labelH = WuxiaGUI3._skillListLabel:get_height()
    if labelH <= 0 then labelH = 200 end
    local maxPx = math.max(0, totalContentH() - labelH)
    if delta > 0 then
      WuxiaGUI3._skillScrollPx = math.max(0, WuxiaGUI3._skillScrollPx - step)
    elseif delta < 0 then
      WuxiaGUI3._skillScrollPx = math.min(maxPx, WuxiaGUI3._skillScrollPx + step)
    end
    WuxiaGUI3._renderSkillScroll()
  end
  skillListLabel:setWheelCallback(skillWheelHandler)
  skillInnerLabel:setWheelCallback(skillWheelHandler)
  for _, cl in ipairs(cardPool) do
    cl:setWheelCallback(skillWheelHandler)
    if cl._barBg then cl._barBg:setWheelCallback(skillWheelHandler) end
    if cl._barFill then cl._barFill:setWheelCallback(skillWheelHandler) end
    if cl._barText then cl._barText:setWheelCallback(skillWheelHandler) end
  end

  -- Track click = page up/down
  sbTrack:setClickCallback(function(event)
    if not event then return end
    local thumbY = WuxiaGUI3._skillSbThumbRelY or 0
    local thumbH = WuxiaGUI3._skillSbThumbRelH or 30
    if event.y >= thumbY and event.y <= thumbY + thumbH then return end
    local labelH = WuxiaGUI3._skillListLabel:get_height()
    if labelH <= 0 then labelH = 200 end
    local maxPx = math.max(0, totalContentH() - labelH)
    if event.y < thumbY then
      WuxiaGUI3._skillScrollPx = math.max(0, WuxiaGUI3._skillScrollPx - labelH)
    else
      WuxiaGUI3._skillScrollPx = math.min(maxPx, WuxiaGUI3._skillScrollPx + labelH)
    end
    WuxiaGUI3._renderSkillScroll()
  end)
  sbTrack:setReleaseCallback(function() end)

  -- Forward wheel events from bg labels to skill scroll handler
  local function _skillWheelHandler(event)
    if not WuxiaGUI3._skillListLabel then return end
    local delta = event and event.angleDeltaY or 0
    local step = (WuxiaGUI3._skillLineH or 20) * 3
    local labelH = WuxiaGUI3._skillListLabel:get_height()
    if labelH <= 0 then labelH = 200 end
    local tch = 0
    for _, e in ipairs(WuxiaGUI3._skillEntries or {}) do tch = tch + e.h end
    local maxPx = math.max(0, tch - labelH)
    if delta > 0 then
      WuxiaGUI3._skillScrollPx = math.max(0, (WuxiaGUI3._skillScrollPx or 0) - step)
    elseif delta < 0 then
      WuxiaGUI3._skillScrollPx = math.min(maxPx, (WuxiaGUI3._skillScrollPx or 0) + step)
    end
    if WuxiaGUI3._renderSkillScroll then WuxiaGUI3._renderSkillScroll() end
  end
  bg1Label:setWheelCallback(_skillWheelHandler)
  bg2Label:setWheelCallback(_skillWheelHandler)
  bg3Label:setWheelCallback(_skillWheelHandler)
  botLabel:setWheelCallback(_skillWheelHandler)

  -- ─── Top frame (drawn above everything else to mask content at top edge) ───
  local topLabel = Geyser.Label:new({ name="W3.skill.frameTop", x=0, y=0, width=PW, height=topH }, p)
  fh = io.open(topPath, "r")
  if fh then fh:close()
    topLabel:setStyleSheet("background-color:transparent; border-image:url("..topPath..") 0 0 0 0 stretch stretch;")
  else topLabel:setStyleSheet("background-color:#1a1008;") end
  WuxiaGUI3._skillTopLabel = topLabel

  -- Z-order layers (bottom to top):
  -- 1. Background images (lowest)
  bg1Label:raiseAll()
  bg3Label:raiseAll()
  -- 2. Scroll area overlay and container
  skillListBg:raiseAll()
  skillListLabel:raiseAll()
  -- 3. Masking layers ABOVE scroll content
  bg1Label:raiseAll()
  bg2Label:raiseAll()
  botLabel:raiseAll()
  topLabel:raiseAll()
  -- 4. Interactive widgets ABOVE masks (clickable)
  summaryLbl:raiseAll()
  enableHdr:raiseAll()
  enableContainer:raiseAll()
  prepHdr:raiseAll()
  prepContainer:raiseAll()
  for _, cat in ipairs(filterCats) do
    local btn = WuxiaGUI3._skillFilterBtns[cat.key]
    if btn then btn:raiseAll() end
  end
  -- 5. Scrollbar (topmost)
  sbTrack:raiseAll()
  sbThumb:raiseAll()

  -- Resize handler
  WuxiaGUI3._repositionSkills = function()
    if WuxiaGUI3._reflowSkillLayout then WuxiaGUI3._reflowSkillLayout() end
  end

  -- Initial reflow
  WuxiaGUI3.skillData = {}
  tempTimer(0.2, function() WuxiaGUI3._reflowSkillLayout() end)
end


function WuxiaGUI3._onSkillFilterClick(cat)
  WuxiaGUI3._skillsActiveFilter = cat
  WuxiaGUI3._updateSkillFilterBtns()
  WuxiaGUI3._refreshSkills()
end

function WuxiaGUI3._updateSkillFilterBtns()
  if not WuxiaGUI3._skillFilterBtns then return end
  local active = WuxiaGUI3._skillsActiveFilter or "all"
  for _, cat in ipairs(WuxiaGUI3._skillFilterCats or {}) do
    local btn = WuxiaGUI3._skillFilterBtns[cat.key]
    if btn then
      if cat.key == active then
        btn:setStyleSheet(string.format("background-color:%s; border:1px solid %s; qproperty-alignment:AlignCenter;", BG2, GOLD))
        btn:echo(span(GOLD, "<b>"..cat.label.."</b>"))
      else
        btn:setStyleSheet(string.format("background-color:%s; border:1px solid %s; qproperty-alignment:AlignCenter;", BG, BORDER))
        btn:echo(span(TEXT_DIM, cat.label))
      end
    end
  end
end

-- ═══════════════════════════════════════════════
-- § 4d  Tab: 天賦 (Talents)
-- ═══════════════════════════════════════════════
function WuxiaGUI3._buildTalents()
  local p = WuxiaGUI3.tabContainers["天賦"]

  local imgDir = getMudletHomeDir() .. "/WuxiaGUI3/"
  local bgPath  = imgDir .. "wuxia_talent_bg.png"
  local topPath = imgDir .. "wuxia_talent_frame_top.png"
  local midPath = imgDir .. "wuxia_talent_frame_middle.png"
  local botPath = imgDir .. "wuxia_talent_frame_bottom.png"

  local topH = 50   -- top frame height (title bar + dragon)
  local botH = 25   -- bottom frame height (corner ornaments)
  local fh

  -- ── Layer 1: Background texture (full panel, stretched) ──
  local bgLabel = Geyser.Label:new({
    name = "W3.talent.bg",
    x = 0, y = 0, width = PW, height = "100%",
  }, p)
  fh = io.open(bgPath, "r")
  if fh then
    fh:close()
    bgLabel:setStyleSheet(
      "background-color: transparent; " ..
      "border-image: url(" .. bgPath .. ") 0 0 0 0 stretch stretch;")
  else
    bgLabel:setStyleSheet("background-color: #0a0806;")
  end

  -- Dark overlay for text readability
  local overlay = Geyser.Label:new({
    name = "W3.talent.overlay",
    x = 0, y = 0, width = PW, height = "100%",
  }, p)
  overlay:setStyleSheet("background-color: rgba(0,0,0,0.45);")

  -- ── Layer 2: Content (between top and bottom frame) ──
  local y = topH + 4

  -- Points summary bar
  y = makeLabel(p, "talentPoints", y, 20)
  WuxiaGUI3.talentPoints:setStyleSheet(
    "background-color: transparent; padding-left: 6px; qproperty-alignment: 'AlignLeft | AlignVCenter';")
  y = y + 4

  -- Separator
  y = makeSep(p, y)

  -- Column header row
  local colHdr = Geyser.Label:new({
    name = "W3.talent.colHdr", x = 16, y = y, width = GW, height = 16,
  }, p)
  colHdr:setStyleSheet("background-color:transparent;")
  colHdr:setFontSize(8)
  colHdr:echo(
    span(TEXT_DIM, "天賦名稱") ..
    "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" ..
    span(TEXT_DIM, "等級") ..
    "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" ..
    span(TEXT_DIM, "效果")
  )
  y = y + 18

  -- Talent list label (scrollable, fills remaining minus bottom frame)
  local talentListLabel = Geyser.Label:new({
    name = "W3.talentList",
    x = 10, y = y, width = PW - 28, height = "-" .. (botH + 8) .. "px",
  }, p)
  talentListLabel:setStyleSheet(
    "background-color: transparent; " ..
    "qproperty-alignment: 'AlignLeft | AlignTop'; " ..
    "qproperty-wordWrap: true; padding: 2px;")
  talentListLabel:setFontSize(10)
  talentListLabel:echo(span(TEXT_DIM, "等待資料..."))
  talentListLabel:raiseAll()
  WuxiaGUI3.talentList = talentListLabel
  WuxiaGUI3._talentScrollPx = 0       -- pixel-based scroll offset
  WuxiaGUI3._talentEntries = {}        -- { html, h } per entry
  WuxiaGUI3._talentLineH = 18         -- single visual line height
  WuxiaGUI3._talentLabelW = PW - 28 - 4  -- usable width after padding

  -- ── Scrollbar ──
  local sbTrackX = PW - 20
  local sbTrack = Geyser.Label:new({
    name = "W3.talentSbTrack",
    x = sbTrackX, y = y + 6, width = 6, height = "-" .. (botH + 2) .. "px",
  }, p)
  sbTrack:setStyleSheet(
    "background-color: rgba(30,15,8,0.6); " ..
    "border: 1px solid #3a2a1a; border-radius: 3px;")
  sbTrack:raiseAll()
  WuxiaGUI3._talentSbTrack = sbTrack

  local sbThumb = Geyser.Label:new({
    name = "W3.talentSbThumb",
    x = 0, y = 0, width = "100%", height = 30,
  }, sbTrack)
  sbThumb:setStyleSheet(
    "background-color: rgba(160,120,60,0.7); " ..
    "border: 1px solid #8a6a3a; border-radius: 3px;")
  sbThumb:raiseAll()
  WuxiaGUI3._talentSbThumb = sbThumb
  WuxiaGUI3._talentSbDragging = false

  -- Helper: compute total content height
  local function totalContentH()
    local h = 0
    for _, e in ipairs(WuxiaGUI3._talentEntries or {}) do h = h + e.h end
    return h
  end

  local function applyThumbY(newThumbY)
    local trackH = sbTrack:get_height()
    local thumbH = WuxiaGUI3._talentSbThumbRelH or 30
    local maxThumbY = trackH - thumbH
    if maxThumbY <= 0 then return end
    newThumbY = math.max(0, math.min(maxThumbY, newThumbY))
    local labelH = WuxiaGUI3.talentList and WuxiaGUI3.talentList:get_height() or 200
    local maxPx = math.max(0, totalContentH() - labelH)
    WuxiaGUI3._talentScrollPx = math.floor(maxPx * newThumbY / maxThumbY + 0.5)
    WuxiaGUI3._renderTalentScroll()
  end

  sbThumb:setClickCallback(function(event)
    WuxiaGUI3._talentSbDragging = true
    WuxiaGUI3._talentSbDragStartGlobalY = event.globalY
    WuxiaGUI3._talentSbDragStartThumbY = WuxiaGUI3._talentSbThumbRelY or 0
  end)
  sbThumb:setMoveCallback(function(event)
    if not WuxiaGUI3._talentSbDragging then return end
    local deltaY = event.globalY - WuxiaGUI3._talentSbDragStartGlobalY
    applyThumbY(WuxiaGUI3._talentSbDragStartThumbY + deltaY)
  end)
  sbThumb:setReleaseCallback(function()
    WuxiaGUI3._talentSbDragging = false
  end)

  sbTrack:setClickCallback(function(event)
    local thumbY = WuxiaGUI3._talentSbThumbRelY or 0
    local thumbH = WuxiaGUI3._talentSbThumbRelH or 30
    if event.y >= thumbY and event.y <= thumbY + thumbH then return end
    local labelH = WuxiaGUI3.talentList and WuxiaGUI3.talentList:get_height() or 200
    local maxPx = math.max(0, totalContentH() - labelH)
    -- Page up/down by labelH
    if event.y < thumbY then
      WuxiaGUI3._talentScrollPx = math.max(0, WuxiaGUI3._talentScrollPx - labelH)
    else
      WuxiaGUI3._talentScrollPx = math.min(maxPx, WuxiaGUI3._talentScrollPx + labelH)
    end
    WuxiaGUI3._renderTalentScroll()
  end)
  sbTrack:setReleaseCallback(function() end)

  -- Scroll render (pixel-based)
  function WuxiaGUI3._renderTalentScroll()
    local entries = WuxiaGUI3._talentEntries or {}
    local label = WuxiaGUI3.talentList
    if not label then return end
    if #entries == 0 then
      label:echo(span(TEXT_DIM, "等待天賦資料..."))
      if WuxiaGUI3._talentSbTrack then WuxiaGUI3._talentSbTrack:hide() end
      return
    end

    local labelH = label:get_height()
    local contentH = totalContentH()
    local maxPx = math.max(0, contentH - labelH)
    WuxiaGUI3._talentScrollPx = math.min(WuxiaGUI3._talentScrollPx, maxPx)
    WuxiaGUI3._talentScrollPx = math.max(0, WuxiaGUI3._talentScrollPx)
    local scrollPx = WuxiaGUI3._talentScrollPx

    -- Find which entries are visible
    local lines = {}
    local cumH = 0
    for _, e in ipairs(entries) do
      local entryTop = cumH
      local entryBot = cumH + e.h
      -- Entry is visible if it overlaps [scrollPx, scrollPx + labelH]
      if entryBot > scrollPx and entryTop < scrollPx + labelH then
        lines[#lines + 1] = e.html
      end
      cumH = entryBot
      if cumH > scrollPx + labelH then break end
    end

    local lineH = WuxiaGUI3._talentLineH
    local html = '<div style="line-height:' .. lineH .. 'px; font-size:10pt; word-wrap:break-word; text-shadow: 0px 0px 4px #000, 1px 1px 2px #000;">' ..
                 table.concat(lines, "<br>") .. '</div>'
    label:echo(html)

    -- Update scrollbar
    if WuxiaGUI3._talentSbTrack then
      if contentH <= labelH then
        WuxiaGUI3._talentSbTrack:hide()
      else
        WuxiaGUI3._talentSbTrack:show()
        local trackH = WuxiaGUI3._talentSbTrack:get_height()
        local thumbRatio = labelH / contentH
        local thumbH = math.max(16, math.floor(trackH * thumbRatio))
        local thumbY = 0
        if maxPx > 0 then
          thumbY = math.floor((trackH - thumbH) * (scrollPx / maxPx))
        end
        WuxiaGUI3._talentSbThumb:resize(nil, thumbH)
        WuxiaGUI3._talentSbThumb:move(0, thumbY)
        WuxiaGUI3._talentSbThumbRelY = thumbY
        WuxiaGUI3._talentSbThumbRelH = thumbH
      end
    end
  end

  -- Mouse wheel (scroll by ~3 lines worth of pixels)
  local function talentWheelHandler(event)
    if not event then return end
    local delta = event.angleDeltaY or 0
    local step = WuxiaGUI3._talentLineH * 3
    local labelH = WuxiaGUI3.talentList and WuxiaGUI3.talentList:get_height() or 200
    local maxPx = math.max(0, totalContentH() - labelH)
    if delta > 0 then
      WuxiaGUI3._talentScrollPx = math.max(0, WuxiaGUI3._talentScrollPx - step)
    elseif delta < 0 then
      WuxiaGUI3._talentScrollPx = math.min(maxPx, WuxiaGUI3._talentScrollPx + step)
    end
    WuxiaGUI3._renderTalentScroll()
  end
  talentListLabel:setWheelCallback(talentWheelHandler)
  sbTrack:setWheelCallback(talentWheelHandler)
  sbThumb:setWheelCallback(talentWheelHandler)
  WuxiaGUI3._talentWheelHandler = talentWheelHandler

  -- ── Layer 3: Frame pieces (on top of everything) ──

  -- Top frame (fixed height)
  local topLabel = Geyser.Label:new({
    name = "W3.talent.frameTop",
    x = 0, y = 0, width = PW, height = topH,
  }, p)
  fh = io.open(topPath, "r")
  if fh then
    fh:close()
    topLabel:setStyleSheet(
      "background-color: transparent; " ..
      "border-image: url(" .. topPath .. ") 0 0 0 0 stretch stretch;")
  end
  topLabel:raiseAll()

  -- Middle frame (side borders, stretched)
  local midLabel = Geyser.Label:new({
    name = "W3.talent.frameMid",
    x = 0, y = topH, width = PW, height = "-" .. botH .. "px",
  }, p)
  fh = io.open(midPath, "r")
  if fh then
    fh:close()
    midLabel:setStyleSheet(
      "background-color: transparent; " ..
      "border-image: url(" .. midPath .. ") 0 0 0 0 stretch stretch;")
  end
  midLabel:raiseAll()
  midLabel:setWheelCallback(function(event)
    if WuxiaGUI3._talentWheelHandler then WuxiaGUI3._talentWheelHandler(event) end
  end)

  -- Bottom frame (fixed, anchored to bottom)
  local botLabel = Geyser.Label:new({
    name = "W3.talent.frameBot",
    x = 0, y = -botH, width = PW, height = botH,
  }, p)
  fh = io.open(botPath, "r")
  if fh then
    fh:close()
    botLabel:setStyleSheet(
      "background-color: transparent; " ..
      "border-image: url(" .. botPath .. ") 0 0 0 0 stretch stretch;")
  end
  botLabel:raiseAll()
  botLabel:setWheelCallback(function(event)
    if WuxiaGUI3._talentWheelHandler then WuxiaGUI3._talentWheelHandler(event) end
  end)

  -- Raise scrollbar above frame layers
  sbTrack:raiseAll()
  sbThumb:raiseAll()

  -- Store references for resize handler
  local minPanelH = 450
  local sbTrackY = y + 6  -- track's absolute Y position

  -- Handle window resize: enforce minimum height (clip below 450px)
  WuxiaGUI3._repositionTalent = function()
    local containerH = p:get_height()
    local contentY = topH + 16
    if containerH < minPanelH then
      -- Too small: force fixed sizes, content clips off-screen
      local fixedH = minPanelH - contentY - botH - 8
      talentListLabel:resize(PW - 28, fixedH)
      midLabel:resize(PW, minPanelH - topH - botH)
      botLabel:move(0, minPanelH - botH)
      overlay:resize(PW, minPanelH)
      bgLabel:resize(PW, minPanelH)
      sbTrack:resize(nil, minPanelH - botH - sbTrackY - 4)
    else
      -- Normal: restore auto-fill layout
      local availH = containerH - contentY - botH - 8
      talentListLabel:resize(PW - 28, availH)
      midLabel:resize(PW, containerH - topH - botH)
      botLabel:move(0, containerH - botH)
      overlay:resize(PW, containerH)
      bgLabel:resize(PW, containerH)
      sbTrack:resize(nil, containerH - botH - sbTrackY - 4)
    end
    if WuxiaGUI3._renderTalentScroll then WuxiaGUI3._renderTalentScroll() end
  end
end

-- ═══════════════════════════════════════════════
-- § 4e  Tab: 裝備 (Equipment) - placeholder
-- ═══════════════════════════════════════════════
function WuxiaGUI3._buildEquipment()
  local p = WuxiaGUI3.tabContainers["裝備"]
  local y = 0

  -- ═══ Dimensions ═══
  local SW = 120   -- slot width
  local SH = 56    -- slot height
  local GAP = 3    -- vertical gap between rows
  local LX = MX
  local RX = MX + GW - SW

  -- Toggle button width = same as a slot
  local toggleW = SW
  local toggleH = SH

  -- Total height: 6 rows (row 0 has toggle+slot, rows 1-5 have 2 slots each)
  local totalH = 6 * (SH + GAP)

  -- ── Background: Character artwork ──
  local silLabel = Geyser.Label:new({
    name = "W3.equip.silhouette",
    x = 0, y = y,
    width = PW, height = totalH,
  }, p)
  local imgPath = getMudletHomeDir() .. "/WuxiaGUI3/wuxia_equip_bg.png"
  local fh = io.open(imgPath, "r")
  if fh then
    fh:close()
    silLabel:setStyleSheet(
      "background-color: transparent; " ..
      "border-image: url(" .. imgPath .. ") 0 0 0 0 stretch stretch;")
  else
    silLabel:setStyleSheet("background-color: transparent; border: none;")
  end
  WuxiaGUI3._equipSilLabel = silLabel

  -- ── Toggle button (top-left) ──
  local toggleBtn = Geyser.Label:new({
    name = "W3.equip.toggle",
    x = LX, y = y + GAP,
    width = toggleW, height = toggleH,
  }, p)
  toggleBtn:setFontSize(11)
  toggleBtn:raiseAll()
  WuxiaGUI3._equipToggleBtn = toggleBtn

  -- ── Create all slots for both pages ──
  WuxiaGUI3._equipCatSlots = { ["裝備"] = {}, ["飾品"] = {} }

  -- Helper: row/col to pixel position
  -- Row 0: toggle at LX, slot at RX
  -- Rows 1-5: LX and RX
  local function slotPos(row, col)
    local sx = (col == 0) and LX or RX
    local sy = y + row * (SH + GAP) + GAP
    return sx, sy
  end

  -- 裝備 page slots
  local equipLayout = {
    { row = 0, col = 1, key = "hand_primary",  label = "主手" },
    { row = 1, col = 0, key = "hand_secondary", label = "副手" },
    { row = 1, col = 1, key = "head",          label = "頭盔 head" },
    { row = 2, col = 0, key = "mask",          label = "面具 mask" },
    { row = 2, col = 1, key = "surcoat",       label = "披風 surcoat" },
    { row = 3, col = 0, key = "armor",         label = "護甲 armor" },
    { row = 3, col = 1, key = "cloth",         label = "衣服 cloth" },
    { row = 4, col = 0, key = "wrists",        label = "護腕 wrists" },
    { row = 4, col = 1, key = "waist",         label = "腰帶 waist" },
    { row = 5, col = 0, key = "leggings",      label = "腿甲 leggings" },
    { row = 5, col = 1, key = "boots",         label = "鞋子 boots" },
  }

  local equipKeys = {}
  for _, s in ipairs(equipLayout) do
    local sx, sy = slotPos(s.row, s.col)
    WuxiaGUI3._makeEquipSlot(p, s.key, s.label, sx, sy, SW, SH)
    equipKeys[#equipKeys + 1] = s.key
  end
  WuxiaGUI3._equipCatSlots["裝備"] = equipKeys

  -- 飾品 page slots
  local accLayout = {
    { row = 0, col = 1, key = "necklace",  label = "項鏈 necklace" },
    { row = 1, col = 0, key = "earring",   label = "耳墜 earring" },
    { row = 1, col = 1, key = "hairpin",   label = "髮飾 hairpin" },
    { row = 2, col = 0, key = "ring",      label = "戒指 ring" },
    { row = 2, col = 1, key = "medal_1",   label = "勳章①" },
    { row = 3, col = 0, key = "medal_2",   label = "勳章②" },
    { row = 3, col = 1, key = "medal_3",   label = "勳章③" },
    { row = 4, col = 0, key = "medal_4",   label = "勳章④" },
    { row = 4, col = 1, key = "medal_5",   label = "勳章⑤" },
    { row = 5, col = 0, key = "heart",     label = "胸口 heart" },
    { row = 5, col = 1, key = "charm",     label = "護符 charm" },
  }

  local accKeys = {}
  for _, s in ipairs(accLayout) do
    local sx, sy = slotPos(s.row, s.col)
    WuxiaGUI3._makeEquipSlot(p, s.key, s.label, sx, sy, SW, SH)
    accKeys[#accKeys + 1] = s.key
  end
  WuxiaGUI3._equipCatSlots["飾品"] = accKeys

  y = y + totalH

  -- ── Wire up toggle ──
  WuxiaGUI3._equipActiveCat = "裝備"
  toggleBtn:setClickCallback(function()
    if WuxiaGUI3._equipActiveCat == "裝備" then
      WuxiaGUI3._equipActiveCat = "飾品"
    else
      WuxiaGUI3._equipActiveCat = "裝備"
    end
    WuxiaGUI3._updateEquipCatDisplay()
  end)

  WuxiaGUI3._updateEquipCatDisplay()

  -- ═══ Equipment Buffs Summary ═══
  -- ═══ Equipment Buffs with dragon frame background ═══
  local effectH = 160
  local effectFrame = Geyser.Label:new({
    name = "W3.equip.effectFrame", x = 0, y = y, width = PW, height = effectH,
  }, p)
  local effectImgPath = getMudletHomeDir() .. "/WuxiaGUI3/wuxia_effect_bg.png"
  if io.open(effectImgPath, "r") then
    effectFrame:setStyleSheet(
      "background-color: transparent; " ..
      "border-image: url(" .. effectImgPath .. ") 0 0 0 0 stretch stretch;")
  else
    effectFrame:setStyleSheet("background-color: rgba(30,20,15,200); border: 1px solid #5a4a2a;")
  end

  -- Title "裝備效果" positioned in the dark banner of the frame
  local effectTitle = Geyser.Label:new({
    name = "W3.equip.effectTitle",
    x = PW / 2 - 59, y = y + 15, width = 120, height = 18,
  }, p)
  effectTitle:setStyleSheet("background-color: transparent; qproperty-alignment: AlignCenter;")
  effectTitle:setFontSize(10)
  effectTitle:echo(span(GOLD, "裝備效果"))
  effectTitle:raiseAll()

  -- Buff content: single label, rendered as rows with 4 columns
  local buffLabel = Geyser.Label:new({
    name = "W3.equipBuffSummary",
    x = 26, y = y + 30, width = PW - 24, height = effectH - 38,
  }, p)
  buffLabel:setStyleSheet(
    "background-color: transparent; " ..
    "qproperty-alignment: 'AlignLeft | AlignTop'; padding: 2px;")
  buffLabel:setFontSize(9)
  buffLabel:echo(span(TEXT_DIM, "無裝備效果"))
  buffLabel:raiseAll()
  WuxiaGUI3._equipBuffLabel = buffLabel
  WuxiaGUI3._equipBuffColW = math.floor((PW - 24) / 3)

  y = y + effectH  -- flush, no gap

  -- ═══ Equipment Sets with weapon rack background ═══
  local setH = 160  -- matches image aspect ratio at PW width
  local setFrame = Geyser.Label:new({
    name = "W3.equip.setFrame", x = 0, y = y, width = PW, height = setH,
  }, p)
  local setImgPath = getMudletHomeDir() .. "/WuxiaGUI3/wuxia_equip_set_bg.png"
  if io.open(setImgPath, "r") then
    setFrame:setStyleSheet(
      "background-color: transparent; " ..
      "border-image: url(" .. setImgPath .. ") 0 0 0 0 stretch stretch;")
  else
    setFrame:setStyleSheet("background-color: rgba(30,20,15,200); border: 1px solid #5a4a2a;")
  end

  -- Title "套裝組合" in the dark banner (~35% from top)
  local setTitle = Geyser.Label:new({
    name = "W3.equip.setTitle",
    x = PW / 2 - 59, y = y + math.floor(setH * 0.28), width = 120, height = 18,
  }, p)
  setTitle:setStyleSheet("background-color: transparent; qproperty-alignment: AlignCenter;")
  setTitle:setFontSize(10)
  setTitle:echo(span(GOLD, "套裝組合"))
  setTitle:raiseAll()

  -- 5 set buttons positioned over the 5 dark slots
  -- Slots: ~17% to ~74% horizontally, ~55% to ~85% vertically
  WuxiaGUI3._equipSetBtns = {}
  WuxiaGUI3._equipSetCooldowns = {}
  local slotStartX = math.floor(PW * 0.132)
  local slotEndX = math.floor(PW * 0.865)
  local totalSlotW = slotEndX - slotStartX
  local slotW = math.floor(totalSlotW / 5 * 0.899)
  local slotGap = math.floor((totalSlotW - slotW * 5) / 4)
  local slotY = y + math.floor(setH * 0.43)
  local slotBtnH = math.floor(setH * 0.212)

  for i = 1, 5 do
    local idx = i
    local btnX = slotStartX + (i - 1) * (slotW + slotGap)
    local btn = Geyser.Label:new({
      name = "W3.equipSet." .. tostring(i),
      x = btnX, y = slotY,
      width = slotW, height = slotBtnH,
    }, p)
    btn:setFontSize(10)
    btn:setStyleSheet(
      "background-color: transparent; border: none; " ..
      "qproperty-alignment: AlignCenter;")

    btn:setClickCallback(function(event)
      if WuxiaGUI3._equipSetCooldowns[idx] then return end

      local inv = WuxiaGUI3.inventory or {}
      local sets = inv.sets or {}
      local hasSet = sets[tostring(idx)] ~= nil

      if type(event) == "table" and event.button == "RightButton" then
        if hasSet then
          sendGMCP('Char.Inventory.DeleteSet {"set":"' .. tostring(idx) .. '"}')
        else
          sendGMCP('Char.Inventory.SaveSet {"set":"' .. tostring(idx) .. '"}')
        end
      else
        if not hasSet then return end
        sendGMCP('Char.Inventory.LoadSet {"set":"' .. tostring(idx) .. '"}')
        WuxiaGUI3._startSetCooldown(idx)
      end
    end)

    btn:raiseAll()
    WuxiaGUI3._equipSetBtns[i] = btn
  end

  -- Hint inside the bottom bar of the image (~90% from top)
  local hint = Geyser.Label:new({
    name = "W3.equip.setsHint",
    x = MX, y = y + math.floor(setH * 0.795), width = GW, height = 14,
  }, p)
  hint:setStyleSheet("background-color:transparent; qproperty-alignment: AlignCenter;")
  hint:setFontSize(7)
  hint:echo(span(TEXT_DIM, "點擊切換 · 右鍵儲存/刪除"))
  hint:raiseAll()

  y = y + setH

  -- ═══ Inventory List with 3-part frame ═══
  local invBgPath = getMudletHomeDir() .. "/WuxiaGUI3/wuxia_inventory_bg.png"

  -- Top frame (fixed, contains title banner)
  local invTopH = 34

  -- Bg texture behind top frame
  local invTopBg = Geyser.Label:new({
    name = "W3.equip.invTopBg", x = 8, y = y,
    width = PW - 16, height = invTopH,
  }, p)
  if io.open(invBgPath, "r") then
    invTopBg:setStyleSheet(
      "background-color: transparent; " ..
      "border-image: url(" .. invBgPath .. ") 0 0 0 0 stretch stretch;")
  end

  local invTopLabel = Geyser.Label:new({
    name = "W3.equip.invTop", x = 0, y = y,
    width = PW, height = invTopH,
  }, p)
  local invTopPath = getMudletHomeDir() .. "/WuxiaGUI3/wuxia_inventory_frame_top.png"
  if io.open(invTopPath, "r") then
    invTopLabel:setStyleSheet(
      "background-color: transparent; " ..
      "border-image: url(" .. invTopPath .. ") 0 0 0 0 stretch stretch;")
  end
  invTopLabel:raiseAll()

  -- Title + item count + weight in one banner line
  local invTitle = Geyser.Label:new({
    name = "W3.equip.invTitle",
    x = 15, y = y + 8, width = PW - 30, height = 20,
  }, p)
  invTitle:setStyleSheet("background-color: transparent; qproperty-alignment: AlignCenter;")
  invTitle:setFontSize(11)
  invTitle:raiseAll()
  WuxiaGUI3.invHeader = invTitle  -- reuse as header, updated in refresh
  invTitle:setWheelCallback(function(event) if WuxiaGUI3._invWheelHandler then WuxiaGUI3._invWheelHandler(event) end end)

  y = y + invTopH

  -- Middle frame (fills available space, min 300px via resize handler)
  local invMidLabel = Geyser.Label:new({
    name = "W3.equip.invMid", x = 0, y = y,
    width = PW, height = "-19px",
  }, p)
  local invMidPath = getMudletHomeDir() .. "/WuxiaGUI3/wuxia_inventory_frame_middle.png"
  if io.open(invMidPath, "r") then
    invMidLabel:setStyleSheet(
      "background-color: transparent; " ..
      "border-image: url(" .. invMidPath .. ") 0 0 0 0 stretch stretch;")
  end
  invMidLabel:raiseAll()
  WuxiaGUI3._invMidLabel = invMidLabel
  WuxiaGUI3._invMidY = y
  invMidLabel:setWheelCallback(function(event) if WuxiaGUI3._invWheelHandler then WuxiaGUI3._invWheelHandler(event) end end)

  -- Background texture inside middle frame (covers black center, under text)
  local invMidBg = Geyser.Label:new({
    name = "W3.equip.invMidBg", x = 8, y = y,
    width = PW - 16, height = "-19px",
  }, p)
  if io.open(invBgPath, "r") then
    invMidBg:setStyleSheet(
      "background-color: transparent; " ..
      "border-image: url(" .. invBgPath .. ") 0 0 0 0 stretch stretch;")
  end
  invMidBg:raiseAll()
  WuxiaGUI3._invMidBg = invMidBg
  invMidBg:setWheelCallback(function(event) if WuxiaGUI3._invWheelHandler then WuxiaGUI3._invWheelHandler(event) end end)

  -- Inventory item list (single label, repopulate on scroll)
  local invListLabel = Geyser.Label:new({
    name = "W3.invList",
    x = 15, y = y + 4, width = PW - 42, height = "-27px",
  }, p)
  invListLabel:setStyleSheet(
    "background-color: transparent; " ..
    "qproperty-alignment: 'AlignLeft | AlignTop'; padding: 2px;")
  invListLabel:setFontSize(10)
  invListLabel:echo(span(TEXT_DIM, "等待資料..."))
  invListLabel:raiseAll()
  WuxiaGUI3.invList = invListLabel
  WuxiaGUI3._invListIsCon = false
  WuxiaGUI3._invScrollOffset = 0
  WuxiaGUI3._invEntries = {}
  WuxiaGUI3._invLineH = 18

  -- Custom scrollbar track (right side, flush against frame)
  local sbTrackX = PW - 18
  local sbTrack = Geyser.Label:new({
    name = "W3.invSbTrack",
    x = sbTrackX, y = y + 6, width = 10, height = "-29px",
  }, p)
  sbTrack:setStyleSheet(
    "background-color: rgba(30,15,8,0.6); " ..
    "border: 1px solid #3a2a1a; border-radius: 3px;")
  sbTrack:raiseAll()
  WuxiaGUI3._invSbTrack = sbTrack

  -- Custom scrollbar thumb
  local sbThumb = Geyser.Label:new({
    name = "W3.invSbThumb",
    x = 0, y = 0, width = "100%", height = 30,
  }, sbTrack)
  sbThumb:setStyleSheet(
    "background-color: rgba(160,120,60,0.7); " ..
    "border: 1px solid #8a6a3a; border-radius: 3px;")
  sbThumb:raiseAll()
  WuxiaGUI3._invSbThumb = sbThumb
  WuxiaGUI3._invSbDragging = false
  WuxiaGUI3._invSbDragStartGlobalY = 0
  WuxiaGUI3._invSbDragStartThumbY = 0

  -- Helper: apply scroll from absolute thumb Y position within track
  local function applyThumbY(newThumbY)
    local trackH = sbTrack:get_height()
    local thumbH = WuxiaGUI3._invSbThumbRelH or 30
    local maxThumbY = trackH - thumbH
    if maxThumbY <= 0 then return end

    newThumbY = math.max(0, math.min(maxThumbY, newThumbY))

    local entries = WuxiaGUI3._invEntries or {}
    local labelH = WuxiaGUI3.invList and WuxiaGUI3.invList:get_height() or 200
    local visibleCount = math.max(1, math.floor(labelH / WuxiaGUI3._invLineH))
    local maxOffset = math.max(0, #entries - visibleCount)

    WuxiaGUI3._invScrollOffset = math.floor(maxOffset * newThumbY / maxThumbY + 0.5)
    WuxiaGUI3._renderInvScroll()
  end

  -- Thumb: mouse down = start drag, record globalY and current thumb position
  sbThumb:setClickCallback(function(event)
    WuxiaGUI3._invSbDragging = true
    WuxiaGUI3._invSbDragStartGlobalY = event.globalY
    WuxiaGUI3._invSbDragStartThumbY = WuxiaGUI3._invSbThumbRelY or 0
  end)

  -- Thumb: mouse move = drag using globalY delta
  sbThumb:setMoveCallback(function(event)
    if not WuxiaGUI3._invSbDragging then return end
    local deltaY = event.globalY - WuxiaGUI3._invSbDragStartGlobalY
    local newThumbY = WuxiaGUI3._invSbDragStartThumbY + deltaY
    applyThumbY(newThumbY)
  end)

  -- Thumb: mouse release = stop drag
  sbThumb:setReleaseCallback(function(event)
    WuxiaGUI3._invSbDragging = false
  end)

  -- Track click: page up/down based on click position relative to thumb
  sbTrack:setClickCallback(function(event)
    local thumbY = WuxiaGUI3._invSbThumbRelY or 0
    local thumbH = WuxiaGUI3._invSbThumbRelH or 30

    -- Ignore clicks on the thumb itself
    if event.y >= thumbY and event.y <= thumbY + thumbH then return end

    local labelH = WuxiaGUI3.invList and WuxiaGUI3.invList:get_height() or 200
    local visibleCount = math.max(1, math.floor(labelH / WuxiaGUI3._invLineH))
    local entries = WuxiaGUI3._invEntries or {}
    local maxOffset = math.max(0, #entries - visibleCount)

    if event.y < thumbY then
      -- Clicked above bar: page up
      WuxiaGUI3._invScrollOffset = math.max(0, WuxiaGUI3._invScrollOffset - visibleCount)
    else
      -- Clicked below bar: page down
      WuxiaGUI3._invScrollOffset = math.min(maxOffset, WuxiaGUI3._invScrollOffset + visibleCount)
    end
    WuxiaGUI3._renderInvScroll()
  end)

  sbTrack:setReleaseCallback(function(event) end)

  -- Scroll render function
  function WuxiaGUI3._renderInvScroll()
    local entries = WuxiaGUI3._invEntries or {}
    local label = WuxiaGUI3.invList
    if not label then return end

    if #entries == 0 then
      label:echo(span(TEXT_DIM, "背包為空"))
      if WuxiaGUI3._invSbTrack then WuxiaGUI3._invSbTrack:hide() end
      return
    end

    local lineH = WuxiaGUI3._invLineH
    local labelH = label:get_height()
    local visibleCount = math.max(1, math.floor(labelH / lineH))
    local maxOffset = math.max(0, #entries - visibleCount)
    WuxiaGUI3._invScrollOffset = math.min(WuxiaGUI3._invScrollOffset, maxOffset)
    local offset = WuxiaGUI3._invScrollOffset

    -- Build visible HTML
    local lines = {}
    for i = offset + 1, math.min(offset + visibleCount, #entries) do
      lines[#lines + 1] = entries[i].html
    end

    local html = '<div style="line-height:' .. lineH .. 'px; font-size:10pt;">' ..
                 table.concat(lines, "<br>") .. '</div>'
    label:echo(html)

    -- Update scrollbar
    if WuxiaGUI3._invSbTrack then
      if #entries <= visibleCount then
        WuxiaGUI3._invSbTrack:hide()
      else
        WuxiaGUI3._invSbTrack:show()
        local trackH = WuxiaGUI3._invSbTrack:get_height()
        local thumbRatio = visibleCount / #entries
        local thumbH = math.max(16, math.floor(trackH * thumbRatio))
        local thumbY = 0
        if maxOffset > 0 then
          thumbY = math.floor((trackH - thumbH) * (offset / maxOffset))
        end
        WuxiaGUI3._invSbThumb:resize(nil, thumbH)
        WuxiaGUI3._invSbThumb:move(0, thumbY)
        WuxiaGUI3._invSbThumbRelY = thumbY
        WuxiaGUI3._invSbThumbRelH = thumbH
      end
    end
  end

  -- Mouse wheel handler (angleDeltaY = vertical scroll, ±120 per tick)
  local function invWheelHandler(event)
    if not event then return end
    local delta = event.angleDeltaY or 0
    if delta > 0 then
      WuxiaGUI3._invScrollOffset = math.max(0, WuxiaGUI3._invScrollOffset - 2)
    elseif delta < 0 then
      local entries = WuxiaGUI3._invEntries or {}
      local labelH = WuxiaGUI3.invList and WuxiaGUI3.invList:get_height() or 200
      local visibleCount = math.max(1, math.floor(labelH / WuxiaGUI3._invLineH))
      local maxOffset = math.max(0, #entries - visibleCount)
      WuxiaGUI3._invScrollOffset = math.min(maxOffset, WuxiaGUI3._invScrollOffset + 2)
    end
    WuxiaGUI3._renderInvScroll()
  end
  invListLabel:setWheelCallback(invWheelHandler)
  sbTrack:setWheelCallback(invWheelHandler)
  sbThumb:setWheelCallback(invWheelHandler)
  WuxiaGUI3._invWheelHandler = invWheelHandler

  -- Bottom frame (anchored to container bottom)
  local invBotH = 19

  -- Bg texture behind bottom frame
  local invBotBg = Geyser.Label:new({
    name = "W3.equip.invBotBg", x = 8, y = -invBotH,
    width = PW - 16, height = invBotH,
  }, p)
  if io.open(invBgPath, "r") then
    invBotBg:setStyleSheet(
      "background-color: transparent; " ..
      "border-image: url(" .. invBgPath .. ") 0 0 0 0 stretch stretch;")
  end
  WuxiaGUI3._invBotBg = invBotBg

  local invBotLabel = Geyser.Label:new({
    name = "W3.equip.invBot", x = 0, y = -invBotH,
    width = PW, height = invBotH,
  }, p)
  local invBotPath = getMudletHomeDir() .. "/WuxiaGUI3/wuxia_inventory_frame_bottom.png"
  if io.open(invBotPath, "r") then
    invBotLabel:setStyleSheet(
      "background-color: transparent; " ..
      "border-image: url(" .. invBotPath .. ") 0 0 0 0 stretch stretch;")
  end
  invBotLabel:raiseAll()
  WuxiaGUI3._invBotLabel = invBotLabel
  invBotLabel:setWheelCallback(function(event) if WuxiaGUI3._invWheelHandler then WuxiaGUI3._invWheelHandler(event) end end)
  WuxiaGUI3._invBotH = invBotH
  WuxiaGUI3._invMinMidH = 300

  -- Handle window resize: only intervene when container too small for min-height
  WuxiaGUI3._repositionInvBot = function()
    if not (WuxiaGUI3._invMidLabel and WuxiaGUI3._invBotLabel) then return end
    local midY = WuxiaGUI3._invMidY
    local containerH = p:get_height()
    local availH = containerH - midY - 19  -- 19 = bottom frame height
    if availH < 150 then
      -- Too small: force min-height, bottom goes off-screen
      WuxiaGUI3._invMidLabel:resize(PW, 150)
      WuxiaGUI3._invBotLabel:move(0, midY + 150)
      WuxiaGUI3.invList:resize(PW - 42, 142)
      if WuxiaGUI3._invMidBg then WuxiaGUI3._invMidBg:resize(PW - 16, 150) end
      if WuxiaGUI3._invBotBg then WuxiaGUI3._invBotBg:move(8, midY + 150) end
      if WuxiaGUI3._invSbTrack then WuxiaGUI3._invSbTrack:resize(nil, 142) end
    else
      -- Normal: restore Geyser's auto-fill layout
      WuxiaGUI3._invMidLabel:resize(PW, availH)
      WuxiaGUI3._invBotLabel:move(0, containerH - 19)
      WuxiaGUI3.invList:resize(PW - 42, availH - 8)
      if WuxiaGUI3._invMidBg then WuxiaGUI3._invMidBg:resize(PW - 16, availH) end
      if WuxiaGUI3._invBotBg then WuxiaGUI3._invBotBg:move(8, containerH - 19) end
      if WuxiaGUI3._invSbTrack then WuxiaGUI3._invSbTrack:resize(nil, availH - 10) end
    end
    -- Re-render to update visible count and scrollbar thumb
    if WuxiaGUI3._renderInvScroll then WuxiaGUI3._renderInvScroll() end
  end
end

-- ─── Equipment set cooldown with sweep effect ───
function WuxiaGUI3._startSetCooldown(clickedIdx)
  local COOLDOWN = 10  -- seconds
  local STEPS = 20
  local interval = COOLDOWN / STEPS
  local gray = "#222233"
  local active = "#161630"

  -- Mark all buttons as in cooldown
  for i = 1, 5 do
    WuxiaGUI3._equipSetCooldowns[i] = true
  end

  -- Chain tempTimers for each animation step
  for step = 1, STEPS do
    tempTimer(interval * step, function()
      if not WuxiaGUI3._equipSetCooldowns[1] then return end

      local pct = step / STEPS

      for i = 1, 5 do
        local btn = WuxiaGUI3._equipSetBtns[i]
        if btn then
          -- qconicalgradient: angle=90 means stop:0 starts at 12 o'clock
          -- stop:0 to pct = active (revealed), pct to 1 = gray (remaining)
          local css = string.format(
            "background-color: qconicalgradient(cx:0.5, cy:0.5, angle:90, " ..
            "stop:0 %s, stop:%.4f %s, stop:%.4f %s, stop:1 %s); " ..
            "border: 1px solid #333; qproperty-alignment: AlignCenter;",
            active, pct - 0.001, active, pct, gray, gray)
          btn:setStyleSheet(css)
          btn:echo(span("#888", tostring(i)))
        end
      end

      if step == STEPS then
        for i = 1, 5 do
          WuxiaGUI3._equipSetCooldowns[i] = nil
        end
        WuxiaGUI3._refreshEquipment()
      end
    end)
  end
end

-- ─── Toggle equipment category display ───
function WuxiaGUI3._updateEquipCatDisplay()
  local active = WuxiaGUI3._equipActiveCat or "裝備"
  local catSlots = WuxiaGUI3._equipCatSlots or {}
  local labels = WuxiaGUI3._equipSlotLabels or {}
  local headers = WuxiaGUI3._equipSlotHeaders or {}

  -- Show/hide slot labels per category
  for cat, slots in pairs(catSlots) do
    local visible = (cat == active)
    for _, slotKey in ipairs(slots) do
      if labels[slotKey] then
        if visible then labels[slotKey]:show(); labels[slotKey]:raiseAll()
        else labels[slotKey]:hide() end
      end
      if headers[slotKey] then
        if visible then headers[slotKey]:show(); headers[slotKey]:raiseAll()
        else headers[slotKey]:hide() end
      end
    end
  end

  -- Update toggle button
  local btn = WuxiaGUI3._equipToggleBtn
  if btn then
    local other = (active == "裝備") and "飾品" or "裝備"
    btn:setStyleSheet(string.format(
      "background-color: rgba(40,30,20,220); border: 1px solid %s; " ..
      "qproperty-alignment: AlignCenter;", GOLD))
    btn:echo(
      span(GOLD, "<b>" .. active .. "</b>") ..
      '<br><span style="color:#888;font-size:9px;">▶ ' .. other .. '</span>')
    btn:raiseAll()
  end
end

-- ─── Create a single equipment slot label (compact character sheet style) ───
function WuxiaGUI3._makeEquipSlot(parent, slotKey, slotLabel, x, y, w, h)
  local hdrH = 16

  -- Item label (full slot, name centered in entire button)
  local itemLbl = Geyser.Label:new({
    name = "W3.eqSlot." .. slotKey,
    x = x, y = y, width = w, height = h,
  }, parent)
  itemLbl:setStyleSheet(
    "background-color: rgba(17,17,28,160); border: 1px solid " .. BORDER .. "; " ..
    "padding: " .. (hdrH + 2) .. "px 5px 2px 5px; " ..
    "qproperty-alignment: 'AlignHCenter | AlignVCenter';")
  itemLbl:setFontSize(12)
  itemLbl:echo(span("#555", "空"))
  itemLbl:setToolTip(slotLabel)
  itemLbl:raiseAll()

  -- Header panel (semi-transparent dark strip, slightly less see-through than item area)
  local hdr = Geyser.Label:new({
    name = "W3.eqSlot." .. slotKey .. ".hdr",
    x = x + 1, y = y + 1, width = w - 2, height = hdrH,
  }, parent)
  hdr:setStyleSheet(
    "background-color: rgba(8,6,4,140); " ..
    "border-bottom: 1px solid rgba(80,60,30,80); " ..
    "padding: 0px 4px; " ..
    "qproperty-alignment: 'AlignLeft | AlignVCenter';")
  hdr:setFontSize(7)
  hdr:echo('<span style="color:#888;font-size:10px;">' .. slotLabel .. '</span>')
  hdr:raiseAll()

  if not WuxiaGUI3._equipSlotLabels then WuxiaGUI3._equipSlotLabels = {} end
  WuxiaGUI3._equipSlotLabels[slotKey] = itemLbl
  if not WuxiaGUI3._equipSlotHeaders then WuxiaGUI3._equipSlotHeaders = {} end
  WuxiaGUI3._equipSlotHeaders[slotKey] = hdr
  return y + h
end

-- ─── Equipment set button handler (via GMCP, no console output) ───
-- ═══════════════════════════════════════════════
-- § 4f  Chat Panel (bottom of screen)
--
-- Channel mapping from CHANNEL_D:
--   chat=閒聊, rumor=謠言, mess=江湖, family=門派,
--   party=幫派, combat=戰鬥, gt=隊伍, dt=洞天,
--   sys=系統, wiz=巫師, news=新聞, auc=拍賣
--
-- Text triggers match the 【頻道名】 prefix patterns
-- from do_channel() output to route lines to tabs.
-- ═══════════════════════════════════════════════

-- Channel definitions: all known channels for console pre-creation
local CHAT_CHANNELS = {
  { name = "全部",   cmd = nil },
  { name = "閒聊",   cmd = "chat" },
  { name = "謠言",   cmd = "rumor" },
  { name = "江湖",   cmd = "mess" },
  { name = "巫師",   cmd = "wiz" },
  { name = "系統",   cmd = "sys" },
  { name = "監測",   cmd = "nch" },
  { name = "新聞",   cmd = "news" },
  { name = "國際",   cmd = "gwiz" },
  { name = "未知",   cmd = "other" },
  { name = "廣告",   cmd = "ad" },
  { name = "門派",   cmd = "family" },
  { name = "幫派",   cmd = "party" },
  { name = "股票",   cmd = "stock" },
  { name = "拍賣",   cmd = "auc" },
  { name = "戰鬥",   cmd = "combat" },
  { name = "隊伍",   cmd = "gt" },
  { name = "洞天",   cmd = "dt" },
  { name = "戰場",   cmd = "war" },
  { name = "調試",   cmd = "debug" },
}

-- Default pinned tabs (before server data arrives)
local CHAT_TABS = { "全部", "閒聊", "門派", "幫派", "系統", "新聞" }

-- All channel names for console creation
local ALL_CHANNEL_NAMES = {}
for _, ch in ipairs(CHAT_CHANNELS) do
  ALL_CHANNEL_NAMES[#ALL_CHANNEL_NAMES+1] = ch.name
end

-- ═══════════════════════════════════════════════
-- § 4f  Left Panel: 地圖 / 場景 / 戰鬥 (stacked)
-- ═══════════════════════════════════════════════

function WuxiaGUI3._buildLeftPanel()
  local p = WuxiaGUI3.leftMain
  local imgDir = getMudletHomeDir() .. "/WuxiaGUI3/"
  local w = LPW - 8
  local mapH = w          -- square map area (matches width)
  local battleH = 200
  local hotkeyH = 42
  local bannerH = 20
  local SHADOW = "text-shadow:1px 1px 3px #000, 0px 0px 6px #000;"
  local CARD_CSS = "background-color:rgba(20,15,10,0.5); border:1px solid rgba(138,106,58,0.5); border-radius:3px; padding:4px; qproperty-alignment:AlignTop;"
  local fh

  -- ─── Section 1: 地圖 (top, fixed) ───
  local y = 4
  local mapHdr = Geyser.Label:new({
    name = "W3.left.mapHdr", x = 4, y = y, width = w, height = 18,
  }, p)
  mapHdr:setStyleSheet("background-color:transparent; qproperty-alignment: AlignCenter;")
  mapHdr:setFontSize(9)
  mapHdr:echo('<div style="' .. SHADOW .. '">' .. span(GOLD, "── 地圖 ──") .. '</div>')
  y = y + 20

  WuxiaGUI3.mapArea = Geyser.Label:new({
    name = "W3.left.map",
    x = 4, y = y, width = w, height = mapH,
  }, p)
  WuxiaGUI3.mapArea:setStyleSheet("background-color: #2A2A2A;")
  WuxiaGUI3.mapArea:echo("")

  -- ─── Graph Map: Create minimap context ───
  local mapOk, mapErr = pcall(function()
    WuxiaGUI3.miniMapCtx = WuxiaGUI3._createMapCtx(
      "mini", WuxiaGUI3.mapArea, WuxiaGUI3.leftMain,
      { room = 120, edge = 200, entity = 30 }
    )
    WuxiaGUI3.miniMapCtx.drivesScenePanel = true
    WuxiaGUI3.miniMapCtx.followPlayer = true
  end)
  if not mapOk then
    debugc(string.format("WuxiaGUI3: Graph Map init error: %s", tostring(mapErr)))
  end

  -- Map frame overlay (decorative gold corners)
  local framePath = imgDir .. "wuxia_left_map_frame.png"
  fh = io.open(framePath, "r")
  if fh then fh:close()
    WuxiaGUI3._mapFrame = Geyser.Label:new({
      name = "W3.left.mapFrame", x = 4, y = y, width = w, height = mapH,
    }, p)
    WuxiaGUI3._mapFrame:setStyleSheet(
      "background-color:transparent; border-image:url(" .. framePath .. ") 0 0 0 0 stretch stretch;")
    if WuxiaGUI3._mapFrame.enableClickthrough then
      WuxiaGUI3._mapFrame:enableClickthrough()
    end
  end

  local sceneTopY = y + mapH  -- where banner1 starts

  -- ─── Banner divider 1 (between map and scene) ───
  local bannerPath = imgDir .. "wuxia_left_section_divider.png"
  local bannerCSS
  fh = io.open(bannerPath, "r")
  if fh then fh:close()
    bannerCSS = "background-color:transparent; border-image:url(" .. bannerPath .. ") 0 0 0 0 stretch stretch;"
  else
    bannerCSS = "background-color:transparent;"
  end

  local banner1 = Geyser.Label:new({
    name = "W3.left.banner1", x = 0, y = sceneTopY, width = LPW, height = bannerH,
  }, p)
  banner1:setStyleSheet(bannerCSS)
  sceneTopY = sceneTopY + bannerH

  -- ═══ Store layout constants for dynamic repositioning ═══
  WuxiaGUI3._sceneTopY = sceneTopY  -- absolute Y where scene content starts
  WuxiaGUI3._battleH   = battleH
  WuxiaGUI3._hotkeyH   = hotkeyH
  WuxiaGUI3._bannerH   = bannerH

  -- ─── Section 2: 場景 (all direct children of p, top-down flow) ───
  local sceneHdr = Geyser.Label:new({
    name = "W3.left.sceneHdr", x = 4, y = sceneTopY, width = w, height = 18,
  }, p)
  sceneHdr:setStyleSheet("background-color:transparent; qproperty-alignment: AlignCenter;")
  sceneHdr:setFontSize(9)
  sceneHdr:echo('<div style="' .. SHADOW .. '">' .. span(GOLD, "── 場景 ──") .. '</div>')
  WuxiaGUI3._sceneHdr = sceneHdr

  -- Sub-section 1: Room name + long description (scales to fit)
  WuxiaGUI3.sceneRoomDesc = Geyser.Label:new({
    name = "W3.left.roomDesc",
    x = 4, y = sceneTopY + 18, width = w, height = 40,
  }, p)
  WuxiaGUI3.sceneRoomDesc:setStyleSheet(CARD_CSS .. " qproperty-wordWrap: true;")
  WuxiaGUI3.sceneRoomDesc:setFontSize(8)
  WuxiaGUI3.sceneRoomDesc:echo(span(TEXT_DIM, "未知位置"))

  -- Sub-section 2: Exits (scales to fit)
  WuxiaGUI3.sceneExits = Geyser.Label:new({
    name = "W3.left.exits",
    x = 4, y = sceneTopY + 60, width = w, height = 24,
  }, p)
  WuxiaGUI3.sceneExits:setStyleSheet(CARD_CSS)
  WuxiaGUI3.sceneExits:setFontSize(8)
  WuxiaGUI3.sceneExits:echo(span(TEXT_DIM, "無出口"))

  -- Sub-section 3: Entities (fills remaining, scrollable)
  WuxiaGUI3.sceneEntities = Geyser.Label:new({
    name = "W3.left.entities",
    x = 4, y = sceneTopY + 86, width = w, height = 60,
  }, p)
  WuxiaGUI3.sceneEntities:setStyleSheet(CARD_CSS)
  WuxiaGUI3.sceneEntities:setFontSize(8)
  WuxiaGUI3.sceneEntities:echo("")

  -- Entity scroll: inner label (child of sceneEntities, clipped by parent)
  WuxiaGUI3._entInner = Geyser.Label:new({
    name = "W3.left.entInner",
    x = 0, y = 0, width = "100%", height = "100%",
  }, WuxiaGUI3.sceneEntities)
  WuxiaGUI3._entInner:setStyleSheet(
    "background-color:transparent; padding:4px; qproperty-wordWrap:true; qproperty-alignment:'AlignLeft | AlignTop';")
  WuxiaGUI3._entInner:setFontSize(8)
  WuxiaGUI3._entInner:echo(span(TEXT_DIM, "空無一物"))

  -- Entity scrollbar track
  WuxiaGUI3._entSbTrack = Geyser.Label:new({
    name = "W3.left.entSbTrack",
    x = w - 12, y = 2, width = 6, height = 56,
  }, WuxiaGUI3.sceneEntities)
  WuxiaGUI3._entSbTrack:setStyleSheet(
    "background-color:rgba(30,15,8,0.6); border:1px solid #3a2a1a; border-radius:3px;")
  WuxiaGUI3._entSbTrack:hide()

  -- Entity scrollbar thumb
  WuxiaGUI3._entSbThumb = Geyser.Label:new({
    name = "W3.left.entSbThumb",
    x = 0, y = 0, width = "100%", height = 20,
  }, WuxiaGUI3._entSbTrack)
  WuxiaGUI3._entSbThumb:setStyleSheet(
    "background-color:rgba(180,140,80,0.7); border-radius:3px;")

  -- Entity scroll state
  WuxiaGUI3._entScrollPx = 0

  -- Wheel callback on entity inner label
  WuxiaGUI3._entInner:setWheelCallback(function(event)
    if not event then return end
    local delta = event.angleDeltaY or 0
    local step = 8
    local ent = WuxiaGUI3.sceneEntities
    if not ent then return end
    local visH = ent:get_height()
    if visH <= 0 then visH = 60 end
    local contentH = WuxiaGUI3._entContentH or 0
    local maxPx = math.max(0, contentH - visH)
    if delta > 0 then
      WuxiaGUI3._entScrollPx = math.max(0, (WuxiaGUI3._entScrollPx or 0) - step)
    elseif delta < 0 then
      WuxiaGUI3._entScrollPx = math.min(maxPx, (WuxiaGUI3._entScrollPx or 0) + step)
    end
    WuxiaGUI3._renderEntScroll()
  end)

  -- ─── Scene preview highlight overlay (covers entire scene section) ───
  WuxiaGUI3._sceneHighlight = Geyser.Label:new({
    name = "W3.left.sceneHL",
    x = 2, y = sceneTopY, width = LPW - 4, height = 100,
  }, p)
  WuxiaGUI3._sceneHighlight:setStyleSheet(
    "background-color:transparent; border:2px solid rgba(68,170,255,0.7); border-radius:4px;")
  WuxiaGUI3._sceneHighlight:echo("")
  WuxiaGUI3._sceneHighlight:hide()
  if WuxiaGUI3._sceneHighlight.enableClickthrough then WuxiaGUI3._sceneHighlight:enableClickthrough() end

  -- ─── Banner divider 2 (between scene and combat) — placeholder Y ───
  WuxiaGUI3._banner2 = Geyser.Label:new({
    name = "W3.left.banner2", x = 0, y = 500, width = LPW, height = bannerH,
  }, p)
  WuxiaGUI3._banner2:setStyleSheet(bannerCSS)

  -- ─── Section 3: 戰鬥 (fixed 200px, positioned by layout) ───
  local battleListH = battleH - 36  -- header(18) + target(18) = 36

  WuxiaGUI3._battleHdr = Geyser.Label:new({
    name = "W3.left.battleHdr", x = 4, y = 520, width = w, height = 18,
  }, p)
  WuxiaGUI3._battleHdr:setStyleSheet("background-color:transparent; qproperty-alignment: AlignCenter;")
  WuxiaGUI3._battleHdr:setFontSize(9)
  WuxiaGUI3._battleHdr:echo('<div style="' .. SHADOW .. '">' .. span(GOLD, "── 戰鬥 ──") .. '</div>')

  WuxiaGUI3.battleTargetInfo = Geyser.Label:new({
    name = "W3.left.target",
    x = 4, y = 538, width = w, height = 18,
  }, p)
  WuxiaGUI3.battleTargetInfo:setStyleSheet("background-color: transparent; padding-left: 2px;")
  WuxiaGUI3.battleTargetInfo:setFontSize(8)
  WuxiaGUI3.battleTargetInfo:echo(span(TEXT_DIM, "目前無目標"))

  WuxiaGUI3.battleEnemyList = Geyser.Label:new({
    name = "W3.left.enemies",
    x = 4, y = 556, width = w, height = battleListH,
  }, p)
  WuxiaGUI3.battleEnemyList:setStyleSheet(CARD_CSS .. " qproperty-wordWrap: true;")
  WuxiaGUI3.battleEnemyList:setFontSize(8)
  WuxiaGUI3.battleEnemyList:echo(
    span(TEXT_DIM, "需要 GMCP 封包") .. "<br>" ..
    span(TEXT_DIM, "戰鬥系統開發中"))

  -- ─── Section 4: Hotkey Bar (fixed height, positioned by layout) ───
  local btnSize = 28
  local navW = 18
  local gap = 2
  local totalBtnsW = 8 * btnSize + 7 * gap  -- 238
  local barW = navW + gap + totalBtnsW + gap + navW  -- 278
  local barX = math.floor((LPW - barW) / 2)
  local btnPath = imgDir .. "wuxia_left_hotkey_button.png"
  local btnFh = io.open(btnPath, "r")
  local BTN_CSS
  if btnFh then btnFh:close()
    BTN_CSS = "border-image:url(" .. btnPath .. ") 0 0 0 0 stretch stretch; qproperty-alignment:AlignCenter;"
  else
    BTN_CSS = "background-color:rgba(25,25,45,0.5); border:1px solid rgba(80,80,100,0.4); border-radius:3px; qproperty-alignment:AlignCenter;"
  end

  WuxiaGUI3._hotkeyPrev = Geyser.Label:new({
    name = "W3.left.hkPrev", x = barX, y = 760, width = navW, height = btnSize,
  }, p)
  WuxiaGUI3._hotkeyPrev:setStyleSheet("background-color:transparent; qproperty-alignment:AlignCenter;")
  WuxiaGUI3._hotkeyPrev:setFontSize(8)
  WuxiaGUI3._hotkeyPrev:echo('<div style="' .. SHADOW .. '">' .. span("#555555", "◀") .. '</div>')

  WuxiaGUI3._hotkeyBtns = {}
  local btnStartX = barX + navW + gap
  for i = 1, 8 do
    local bx = btnStartX + (i - 1) * (btnSize + gap)
    local btn = Geyser.Label:new({
      name = "W3.left.hkBtn" .. i,
      x = bx, y = 760, width = btnSize, height = btnSize,
    }, p)
    btn:setStyleSheet(BTN_CSS)
    btn:setFontSize(7)
    btn:echo(span("#444444", tostring(i)))
    WuxiaGUI3._hotkeyBtns[i] = btn
  end

  WuxiaGUI3._hotkeyNext = Geyser.Label:new({
    name = "W3.left.hkNext",
    x = btnStartX + 8 * (btnSize + gap), y = 760, width = navW, height = btnSize,
  }, p)
  WuxiaGUI3._hotkeyNext:setStyleSheet("background-color:transparent; qproperty-alignment:AlignCenter;")
  WuxiaGUI3._hotkeyNext:setFontSize(8)
  WuxiaGUI3._hotkeyNext:echo('<div style="' .. SHADOW .. '">' .. span("#555555", "▶") .. '</div>')

  WuxiaGUI3._hotkeyPageLbl = Geyser.Label:new({
    name = "W3.left.hkPage",
    x = 0, y = 790, width = LPW, height = 8,
  }, p)
  WuxiaGUI3._hotkeyPageLbl:setStyleSheet("background-color:transparent; qproperty-alignment:AlignCenter;")
  WuxiaGUI3._hotkeyPageLbl:setFontSize(5)
  WuxiaGUI3._hotkeyPageLbl:echo(span("#555555", "● ○ ○"))

  WuxiaGUI3._hotkeyState = { page = 1, totalPages = 3 }

  -- ─── Z-order: raise all content above bg/overlay ───
  mapHdr:raiseAll()
  WuxiaGUI3.mapArea:raiseAll()
  if WuxiaGUI3._mapFrame then WuxiaGUI3._mapFrame:raiseAll() end
  banner1:raiseAll()
  sceneHdr:raiseAll()
  WuxiaGUI3.sceneRoomDesc:raiseAll()
  WuxiaGUI3.sceneExits:raiseAll()
  WuxiaGUI3.sceneEntities:raiseAll()
  WuxiaGUI3._entSbTrack:raiseAll()
  WuxiaGUI3._entSbThumb:raiseAll()
  WuxiaGUI3._banner2:raiseAll()
  WuxiaGUI3._battleHdr:raiseAll()
  WuxiaGUI3.battleTargetInfo:raiseAll()
  WuxiaGUI3.battleEnemyList:raiseAll()
  WuxiaGUI3._hotkeyPrev:raiseAll()
  for i = 1, 8 do WuxiaGUI3._hotkeyBtns[i]:raiseAll() end
  WuxiaGUI3._hotkeyNext:raiseAll()
  WuxiaGUI3._hotkeyPageLbl:raiseAll()

  -- ─── Initial layout pass ───
  WuxiaGUI3._layoutLeftPanel()
end

-- Render entity scroll (inner label position + scrollbar)
function WuxiaGUI3._renderEntScroll()
  local ent = WuxiaGUI3.sceneEntities
  local inner = WuxiaGUI3._entInner
  if not ent or not inner then return end

  local visH = ent:get_height()
  if visH <= 0 then visH = 60 end
  local contentH = WuxiaGUI3._entContentH or 0
  local maxPx = math.max(0, contentH - visH)
  local scrollPx = math.max(0, math.min(WuxiaGUI3._entScrollPx or 0, maxPx))
  WuxiaGUI3._entScrollPx = scrollPx

  -- Position inner label (scroll pattern: y = -visH - scrollPx)
  inner:move(0, -visH - scrollPx)
  inner:resize(nil, math.max(visH, contentH))

  -- Scrollbar
  local track = WuxiaGUI3._entSbTrack
  local thumb = WuxiaGUI3._entSbThumb
  if not track or not thumb then return end
  if contentH <= visH then
    track:hide()
  else
    track:show()
    track:resize(nil, visH - 4)
    local trackH = visH - 4
    local tH = math.max(16, math.floor(trackH * visH / contentH))
    local tY = maxPx > 0 and math.floor((trackH - tH) * scrollPx / maxPx) or 0
    thumb:resize(nil, tH)
    thumb:move(0, tY)
  end
end

-- ─── Scene panel updater ───
local SCENE_DIR_NAMES = {
  north="北", south="南", east="東", west="西",
  northeast="東北", northwest="西北", southeast="東南", southwest="西南",
  up="上", down="下",
  northup="北上", southup="南上", eastup="東上", westup="西上",
  northdown="北下", southdown="南下", eastdown="東下", westdown="西下",
}
local SCENE_TYPE_NAMES = {
  shop="商店", bank="銀行", inn="客棧", water="渡口",
  outdoor="戶外", indoor="室內", dungeon="地下城", chat="聊天室",
}

local function _stripAnsi(s)
  if not s then return "" end
  return (s:gsub("\27%[[%d;]*m", ""))
end

-- Count UTF-8 characters (not bytes) in a string.
local function _utf8len(s)
  local n = 0
  for _ in s:gmatch("[%z\1-\127\194-\244]") do n = n + 1 end
  return n
end

-- Estimate pixel width of a UTF-8 string at font size 8.
-- CJK chars (~14px fullwidth), ASCII chars (~7px).
local function _estimateTextW(s)
  local w = 0
  local i = 1
  local len = #s
  while i <= len do
    local b = s:byte(i)
    if b >= 0xE0 then
      w = w + 14  -- 3/4-byte CJK character (fullwidth in Qt)
      if b >= 0xF0 then i = i + 4 else i = i + 3 end
    elseif b >= 0xC0 then
      w = w + 9   -- 2-byte character (accented, etc.)
      i = i + 2
    else
      w = w + 7   -- ASCII
      i = i + 1
    end
  end
  return w
end

-- Estimate pixel height for rich-text content inside a label.
-- lineH = approximate line height in px, labelW = usable pixel width.
local function _estimateTextH(htmlStr, labelW, lineH)
  lineH = lineH or 18
  -- Replace <br> with marker, then strip HTML, then collapse embedded \n to spaces
  local marked = htmlStr:gsub("<br ?/?>", "\1")
  local plain = marked:gsub("<[^>]+>", "")
  plain = plain:gsub("[\r\n]+", " ")  -- embedded newlines are just whitespace in Qt rich text
  local total = 0
  for seg in (plain .. "\1"):gmatch("([^\1]*)\1") do
    seg = seg:gsub("^%s+", ""):gsub("%s+$", "")
    if #seg == 0 then
      total = total + 1  -- empty line from consecutive <br>
    else
      local segW = _estimateTextW(seg)
      total = total + math.max(1, math.ceil(segW / labelW))
    end
  end
  return total * lineH
end

-- ─── Layout engine: positions all left-panel elements top-down ───
function WuxiaGUI3._layoutLeftPanel()
  local p = WuxiaGUI3.leftMain
  if not p then return end
  local parentH = p:get_height()
  if parentH <= 0 then parentH = 800 end
  local w = LPW - 8
  local gap = 2

  local sceneTopY = WuxiaGUI3._sceneTopY or 316
  local battleH   = WuxiaGUI3._battleH or 200
  local hotkeyH   = WuxiaGUI3._hotkeyH or 42
  local bannerH   = WuxiaGUI3._bannerH or 20

  -- Use cached content heights from _updateScenePanel, or defaults
  local descH = WuxiaGUI3._descH or 40
  local exitH = WuxiaGUI3._exitH or 24

  -- Scene header
  local y = sceneTopY + 18  -- after sceneHdr (sceneHdr is at sceneTopY, fixed)

  -- Room description
  if WuxiaGUI3.sceneRoomDesc then
    WuxiaGUI3.sceneRoomDesc:move(4, y)
    WuxiaGUI3.sceneRoomDesc:resize(w, descH)
  end
  y = y + descH + gap

  -- Exits
  if WuxiaGUI3.sceneExits then
    WuxiaGUI3.sceneExits:move(4, y)
    WuxiaGUI3.sceneExits:resize(w, exitH)
  end
  y = y + exitH + gap

  -- Entities: fills remaining space before banner2
  -- Bottom stack: banner2(bannerH) + combat(battleH) + hotkey(hotkeyH)
  local bottomFixedH = bannerH + battleH + hotkeyH
  local entH = math.max(200, parentH - y - bottomFixedH)
  if WuxiaGUI3.sceneEntities then
    WuxiaGUI3.sceneEntities:move(4, y)
    WuxiaGUI3.sceneEntities:resize(w, entH)
  end
  y = y + entH

  -- Scene preview highlight overlay: spans from sceneHdr to bottom of entities
  if WuxiaGUI3._sceneHighlight then
    WuxiaGUI3._sceneHighlight:move(2, sceneTopY)
    WuxiaGUI3._sceneHighlight:resize(LPW - 4, y - sceneTopY)
  end

  -- Banner 2 (between entities and combat)
  if WuxiaGUI3._banner2 then
    WuxiaGUI3._banner2:move(0, y)
  end
  y = y + bannerH

  -- Combat header
  if WuxiaGUI3._battleHdr then
    WuxiaGUI3._battleHdr:move(4, y)
  end
  -- Combat target info
  if WuxiaGUI3.battleTargetInfo then
    WuxiaGUI3.battleTargetInfo:move(4, y + 18)
  end
  -- Combat enemy list
  local battleListH = battleH - 36
  if WuxiaGUI3.battleEnemyList then
    WuxiaGUI3.battleEnemyList:move(4, y + 36)
    WuxiaGUI3.battleEnemyList:resize(w, battleListH)
  end
  y = y + battleH

  -- Hotkey bar
  local btnSize = 28
  local navW = 18
  local totalBtnsW = 8 * btnSize + 7 * gap
  local barW = navW + gap + totalBtnsW + gap + navW
  local barX = math.floor((LPW - barW) / 2)
  local btnY = y + 4  -- 4px padding from hotkey top

  if WuxiaGUI3._hotkeyPrev then
    WuxiaGUI3._hotkeyPrev:move(barX, btnY)
  end
  local btnStartX = barX + navW + gap
  if WuxiaGUI3._hotkeyBtns then
    for i = 1, 8 do
      local bx = btnStartX + (i - 1) * (btnSize + gap)
      if WuxiaGUI3._hotkeyBtns[i] then
        WuxiaGUI3._hotkeyBtns[i]:move(bx, btnY)
      end
    end
  end
  if WuxiaGUI3._hotkeyNext then
    WuxiaGUI3._hotkeyNext:move(btnStartX + 8 * (btnSize + gap), btnY)
  end
  if WuxiaGUI3._hotkeyPageLbl then
    WuxiaGUI3._hotkeyPageLbl:move(0, y + hotkeyH - 10)
  end

  -- Update entity scroll after resize
  WuxiaGUI3._renderEntScroll()
end

function WuxiaGUI3._updateScenePanel(overrideRid)
  local gm = WuxiaGUI3.graphMap
  if not gm or not gm.currentRoom then return end

  local rid = overrideRid or gm.currentRoom
  local isPreview = (overrideRid ~= nil and overrideRid ~= gm.currentRoom)
  local room = gm.rooms[rid]
  local roomName = (room and room.name) or "未知位置"
  local w = LPW - 8
  local pad = 12  -- vertical padding (CSS padding:4px top+bottom + extra breathing room)

  -- ═══ Header: show (預覽) indicator when previewing another room ═══
  local shadow = "text-shadow:1px 1px 3px #000, 0px 0px 6px #000;"
  if isPreview then
    WuxiaGUI3._sceneHdr:echo('<div style="' .. shadow .. '">'
      .. span(GOLD, "── 場景 ──") .. " " .. span(TEXT_DIM, "(預覽)") .. '</div>')
  else
    WuxiaGUI3._sceneHdr:echo('<div style="' .. shadow .. '">'
      .. span(GOLD, "── 場景 ──") .. '</div>')
  end

  -- ═══ Scene panel highlight overlay ═══
  if WuxiaGUI3._sceneHighlight then
    if isPreview then
      WuxiaGUI3._sceneHighlight:show()
      WuxiaGUI3._sceneHighlight:raiseAll()
    else
      WuxiaGUI3._sceneHighlight:hide()
    end
  end

  -- ═══ Section 1: Room name + description ═══
  local descLines = {}
  local typeTag = ""
  if room and room.room_type then
    local tn = SCENE_TYPE_NAMES[room.room_type]
    if tn then typeTag = " " .. span("#888888", "(" .. tn .. ")") end
  end
  descLines[#descLines + 1] = span(WHITE, roomName) .. typeTag

  -- Long description only available for current room (from gmcp.Room.Info)
  if not isPreview then
    local ri = WuxiaGUI3.room
    if ri and ri.long and ri.long ~= "" then
      local desc = _stripAnsi(ri.long)
      desc = desc:gsub("^%s+", ""):gsub("%s+$", "")
      if desc ~= "" then
        descLines[#descLines + 1] = span("#bbbbbb", desc)
      end
    end
  end

  local descHtml = table.concat(descLines, "<br>")
  if WuxiaGUI3.sceneRoomDesc then
    WuxiaGUI3.sceneRoomDesc:echo(descHtml)
  end
  WuxiaGUI3._descH = _estimateTextH(descHtml, w - 8, 14) + pad

  -- ═══ Section 2: Exits ═══
  local exitDirs = {}
  for _, edge in pairs(gm.edges) do
    if edge.from == rid then
      local dir = edge.cmd or "?"
      local cdir = SCENE_DIR_NAMES[dir] or dir
      exitDirs[#exitDirs + 1] = cdir
    end
  end
  local exitHtml
  if #exitDirs > 0 then
    table.sort(exitDirs)
    exitHtml = span(GOLD_DIM, "出口：") .. span("#cccccc", table.concat(exitDirs, " "))
  else
    exitHtml = span(TEXT_DIM, "無出口")
  end
  if WuxiaGUI3.sceneExits then
    WuxiaGUI3.sceneExits:echo(exitHtml)
  end
  WuxiaGUI3._exitH = _estimateTextH(exitHtml, w - 8, 14) + pad

  -- ═══ Section 3: Entities ═══
  local entLines = {}
  local npcs, players, items = {}, {}, {}
  for _, edata in pairs(gm.entities) do
    if edata.room == rid then
      local lbl = ansiToHtml(edata.label or edata.id or "")
      if edata.type == "npc" then
        local clr = "#FFFF44"
        local flags = edata.flags
        if flags then
          for _, f in ipairs(flags) do
            if f == "hostile"  then clr = "#FF4444" end
            if f == "vendor"   then clr = "#FFAA22" end
            if f == "quest"    then clr = "#44AAFF" end
            if f == "trainer"  then clr = "#AA44FF" end
          end
        end
        npcs[#npcs + 1] = span(clr, lbl)
      elseif edata.type == "player" then
        players[#players + 1] = span("#44FF44", lbl)
      elseif edata.type == "item" then
        items[#items + 1] = span("#AAAAAA", lbl)
      end
    end
  end
  if #npcs > 0 then
    entLines[#entLines + 1] = span(GOLD_DIM, "NPC：") .. table.concat(npcs, "、")
  end
  if #players > 0 then
    entLines[#entLines + 1] = span(GOLD_DIM, "玩家：") .. table.concat(players, "、")
  end
  if #items > 0 then
    entLines[#entLines + 1] = span(GOLD_DIM, "物品：") .. table.concat(items, "、")
  end

  local entHtml
  if #entLines > 0 then
    entHtml = table.concat(entLines, "<br>")
  else
    entHtml = span(TEXT_DIM, "空無一物")
  end

  -- Update entity inner label content
  if WuxiaGUI3._entInner then
    WuxiaGUI3._entInner:echo(entHtml)
  end
  WuxiaGUI3._entContentH = _estimateTextH(entHtml, w - 16, 14) + pad
  if not isPreview then
    WuxiaGUI3._entScrollPx = 0  -- reset scroll on room change (not on hover preview)
  end

  -- ═══ Re-layout everything ═══
  WuxiaGUI3._layoutLeftPanel()
end

-- ═══════════════════════════════════════════════
-- § 4g  Graph Map System
-- ═══════════════════════════════════════════════

-- Constants
local MAP_GRID_PX    = 20
local MAP_MIN_ZOOM   = 0.3
local MAP_MAX_ZOOM   = 3.0
local MAP_ZOOM_FACTOR = 1.15
local MAP_INSET      = 2
local MAP_POOL_SIZE  = 120
local MAP_EDGE_POOL  = 200
local MAP_EDGE_THICK = 3
local MAP_EDGE_COLOR     = "rgba(200,200,200,0.55)"
local MAP_EDGE_COLOR_DIM = "rgba(120,120,120,0.30)"
local MAP_ENTITY_POOL    = 30
local MAP_ENTITY_SIZE    = 10     -- dot diameter at zoom=1.0
local MAP_HOVER_COLOR    = "rgba(68,170,255,0.7)"  -- hover highlight border

-- Entity type → dot color
local MAP_ENTITY_COLORS = {
  player      = "#44FF44",  -- bright green
  npc_normal  = "#FFFF44",  -- yellow
  npc_hostile = "#FF4444",  -- red
  npc_vendor  = "#FFAA22",  -- orange
  npc_quest   = "#44AAFF",  -- cyan-blue
  npc_trainer = "#AA44FF",  -- purple
  item        = "#AAAAAA",  -- grey
}

-- Room type → fill color
local MAP_ROOM_COLORS = {
  outdoor = "#C8B89A", shop    = "#D4A017", inn     = "#5B8DBE",
  bank    = "#B8860B", indoor  = "#8B7355", water   = "#4A90D9",
  dungeon = "#7B4F9D", chat    = "#2CA58D", default = "#9E9E9E",
}
-- Room type → explored (dimmed) color
local MAP_ROOM_COLORS_DIM = {
  outdoor = "#6E6358", shop    = "#7A5E10", inn     = "#3A5A75",
  bank    = "#6B5008", indoor  = "#5A4A38", water   = "#2E5A85",
  dungeon = "#4A3060", chat    = "#1B6B5A", default = "#5E5E5E",
}
-- Zone → terrain fill color (background)
local MAP_ZONE_TERRAIN = {
  city = "#3A3A3A", wilderness = "#2A3A2A", mountain = "#333333",
  desert = "#3A352A", water = "#1A2A3A", cave = "#1A1A1A",
  default = "#2A2A2A",
}
local MAP_ZONE_TO_TERRAIN = {
  beijing = "city", changan = "city", yangzhou = "city", chengdu = "city",
  luoyang = "city", suzhou = "city", hangzhou = "city", dali = "city",
  city = "city", city2 = "city", foshan = "city", fuzhou = "city",
  hangzhou = "city", kaifeng = "city", kunming = "city", lanzhou = "city",
  lingzhou = "city", quanzhou = "city", xiangyang = "city", jiaxing = "city",
  jingzhou = "city", nanyang = "city", hanzhong = "city", yueyang = "city",
  zhongzhou = "city", wuxi = "city", yanping = "city", yongdeng = "city",
  village = "city", register = "city", newbie = "city",
  huanghe = "water", beihai = "water",
  huashan = "mountain", taishan = "mountain", songshan = "mountain",
  hengshan = "mountain", henshan = "mountain", kunlun = "mountain",
  qilian = "mountain", xueshan = "mountain", changcheng = "mountain",
  gaochang = "desert", mobei = "desert",
}

-- Client-side map state (shared across all map views)
WuxiaGUI3.graphMap = {
  config = {},
  rooms = {},           -- [room_id] = { name, zone, x, y, z, len, wid, hgt, room_type, flags }
  edges = {},           -- [edge_id] = { from, to, cmd, type }
  currentRoom = nil,
  visibleRooms = {},    -- set: [room_id] = true
  exploredRooms = {},   -- set: [room_id] = true
  -- Entity / POI state
  entities = {},        -- [entity_id] = { id, type, room, label, flags }
  pois = {},            -- [poi_id] = { id, room, category, label }
  -- Filter toggles (shared across views)
  filterNPCs    = true,
  initialized = false,
}

-- ─── Map View Context Factory ───
-- Creates a map view context with its own pools, toolbar, and callbacks.
-- id: "mini" or "big" (used for label naming)
-- container: Geyser.Label to render into
-- helpTipParent: parent for help tooltip (leftMain for mini, container for big)
-- poolSizes: { room=N, edge=N, entity=N }
function WuxiaGUI3._createMapCtx(id, container, helpTipParent, poolSizes)
  local gm = WuxiaGUI3.graphMap
  if not container then return nil end

  local mapCtx = {
    id            = id,
    container     = container,
    -- Per-view state
    zoom          = 1.0,
    panX          = 0,
    panY          = 0,
    currentZ      = 0,
    dragging      = false,
    dragStartX    = 0,
    dragStartY    = 0,
    hoveredRoom   = nil,
    -- Pool sizes
    roomPoolSize   = poolSizes.room or MAP_POOL_SIZE,
    edgePoolSize   = poolSizes.edge or MAP_EDGE_POOL,
    entityPoolSize = poolSizes.entity or MAP_ENTITY_POOL,
    -- Pools
    roomPool      = {},
    roomPoolMap   = {},
    nextRoomPool  = 1,
    edgePool      = {},
    nextEdgePool  = 1,
    entityPool    = {},
    nextEntityPool = 1,
    -- Toolbar widgets
    zUp = nil, zDown = nil, zDisp = nil,
    centerBtn = nil, npcToggle = nil,
    helpBtn = nil, btnTip = nil, helpTip = nil,
    -- Behavior
    drivesScenePanel = false,
    followPlayer     = true,
  }

  local prefix = "W3.map." .. id .. "."

  -- Edge pool (created first → lower z-order, behind rooms)
  for i = 1, mapCtx.edgePoolSize do
    local lbl = Geyser.Label:new({
      name = prefix .. "edge." .. i,
      x = 0, y = 0, width = 1, height = 1,
    }, container)
    lbl:setStyleSheet("background-color:transparent;")
    lbl:echo("")
    lbl:hide()
    if lbl.enableClickthrough then lbl:enableClickthrough() end
    mapCtx.edgePool[i] = lbl
  end

  -- Room pool (created after edges → higher z-order, on top)
  for i = 1, mapCtx.roomPoolSize do
    local lbl = Geyser.Label:new({
      name = prefix .. "room." .. i,
      x = 0, y = 0, width = 1, height = 1,
    }, container)
    lbl:setStyleSheet("background-color:transparent;")
    lbl:setFontSize(6)
    lbl:echo("")
    lbl:hide()
    if lbl.enableClickthrough then lbl:enableClickthrough() end
    mapCtx.roomPool[i] = lbl
  end

  -- Entity pool (above room pool)
  for i = 1, mapCtx.entityPoolSize do
    local lbl = Geyser.Label:new({
      name = prefix .. "entity." .. i,
      x = 0, y = 0, width = MAP_ENTITY_SIZE, height = MAP_ENTITY_SIZE,
    }, container)
    lbl:setStyleSheet("background-color:transparent; border-radius:5px;")
    lbl:echo("")
    lbl:hide()
    if lbl.enableClickthrough then lbl:enableClickthrough() end
    mapCtx.entityPool[i] = lbl
  end

  -- ─── Toolbar ───
  local cw = container:get_width()
  if cw <= 0 then cw = 272 end
  -- Use negative x for right-edge anchoring (Geyser: negative = offset from opposite edge)
  local btnX = -24      -- left edge 24px from container right → right edge 4px from right
  local dispX = -46     -- Z display label offset
  local btnCSS     = "background-color:rgba(20,20,40,0.7); border:1px solid #555; border-radius:2px; qproperty-alignment:AlignCenter;"
  local btnHoverCSS = "background-color:rgba(40,40,80,0.9); border:1px solid #aaa; border-radius:2px; qproperty-alignment:AlignCenter;"
  local tipCSS = "background-color:rgba(10,10,20,0.92); border:1px solid #888; border-radius:3px; padding:2px 6px; qproperty-alignment:'AlignRight|AlignVCenter';"

  -- Shared instant tooltip
  mapCtx.btnTip = Geyser.Label:new({
    name = prefix .. "btnTip",
    x = 0, y = 0, width = 100, height = 18,
  }, container)
  mapCtx.btnTip:setStyleSheet(tipCSS)
  mapCtx.btnTip:setFontSize(7)
  mapCtx.btnTip:echo("")
  mapCtx.btnTip:hide()
  if mapCtx.btnTip.enableClickthrough then mapCtx.btnTip:enableClickthrough() end

  local function showBtnTip(btn, text)
    local tip = mapCtx.btnTip
    local bx = btn:get_x() - container:get_x()
    local by = btn:get_y() - container:get_y()
    local bh = btn:get_height()
    tip:move(bx - 104, by + math.floor((bh - 18) / 2))
    tip:echo("<font color='#cccccc'>" .. text .. "</font>")
    tip:show()
    tip:raiseAll()
  end
  local function hideBtnTip()
    mapCtx.btnTip:hide()
  end

  -- Z Up
  mapCtx.zUp = Geyser.Label:new({
    name = prefix .. "zUp",
    x = btnX, y = 40, width = 20, height = 14,
  }, container)
  mapCtx.zUp:setStyleSheet(btnCSS)
  mapCtx.zUp:setFontSize(7)
  mapCtx.zUp:echo("<font color='#cccccc'>&#9650;</font>")
  mapCtx.zUp:setClickCallback(function()
    mapCtx.currentZ = mapCtx.currentZ + 1
    WuxiaGUI3._renderMapCtx(mapCtx)
  end)
  mapCtx.zUp:setOnEnter(function()
    mapCtx.zUp:setStyleSheet(btnHoverCSS)
    mapCtx.zUp:echo("<font color='#ffffff'>&#9650;</font>")
    showBtnTip(mapCtx.zUp, "上一層")
  end, mapCtx.zUp)
  mapCtx.zUp:setOnLeave(function()
    mapCtx.zUp:setStyleSheet(btnCSS)
    mapCtx.zUp:echo("<font color='#cccccc'>&#9650;</font>")
    hideBtnTip()
  end, mapCtx.zUp)
  mapCtx.zUp:raiseAll()

  -- Z Down
  mapCtx.zDown = Geyser.Label:new({
    name = prefix .. "zDown",
    x = btnX, y = 56, width = 20, height = 14,
  }, container)
  mapCtx.zDown:setStyleSheet(btnCSS)
  mapCtx.zDown:setFontSize(7)
  mapCtx.zDown:echo("<font color='#cccccc'>&#9660;</font>")
  mapCtx.zDown:setClickCallback(function()
    mapCtx.currentZ = mapCtx.currentZ - 1
    WuxiaGUI3._renderMapCtx(mapCtx)
  end)
  mapCtx.zDown:setOnEnter(function()
    mapCtx.zDown:setStyleSheet(btnHoverCSS)
    mapCtx.zDown:echo("<font color='#ffffff'>&#9660;</font>")
    showBtnTip(mapCtx.zDown, "下一層")
  end, mapCtx.zDown)
  mapCtx.zDown:setOnLeave(function()
    mapCtx.zDown:setStyleSheet(btnCSS)
    mapCtx.zDown:echo("<font color='#cccccc'>&#9660;</font>")
    hideBtnTip()
  end, mapCtx.zDown)
  mapCtx.zDown:raiseAll()

  -- Z Display
  mapCtx.zDisp = Geyser.Label:new({
    name = prefix .. "zDisp",
    x = dispX, y = 40, width = 20, height = 30,
  }, container)
  mapCtx.zDisp:setStyleSheet("background-color:transparent; qproperty-alignment:AlignCenter;")
  mapCtx.zDisp:setFontSize(7)
  mapCtx.zDisp:echo("<font color='#666666'>Z0</font>")
  mapCtx.zDisp:raiseAll()

  -- Center button
  mapCtx.centerBtn = Geyser.Label:new({
    name = prefix .. "center",
    x = btnX, y = 74, width = 20, height = 18,
  }, container)
  mapCtx.centerBtn:setStyleSheet(btnCSS)
  mapCtx.centerBtn:setFontSize(8)
  mapCtx.centerBtn:echo("<font color='#cccccc'>⊕</font>")
  mapCtx.centerBtn:setClickCallback(function()
    mapCtx.panX = 0
    mapCtx.panY = 0
    local cur = gm.rooms[gm.currentRoom]
    if cur then mapCtx.currentZ = cur.z or 0 end
    WuxiaGUI3._renderMapCtx(mapCtx)
  end)
  mapCtx.centerBtn:setOnEnter(function()
    mapCtx.centerBtn:setStyleSheet(btnHoverCSS)
    mapCtx.centerBtn:echo("<font color='#ffffff'>⊕</font>")
    showBtnTip(mapCtx.centerBtn, "回到當前位置")
  end, mapCtx.centerBtn)
  mapCtx.centerBtn:setOnLeave(function()
    mapCtx.centerBtn:setStyleSheet(btnCSS)
    mapCtx.centerBtn:echo("<font color='#cccccc'>⊕</font>")
    hideBtnTip()
  end, mapCtx.centerBtn)
  mapCtx.centerBtn:raiseAll()

  -- NPC Toggle
  mapCtx.npcToggle = Geyser.Label:new({
    name = prefix .. "npcToggle",
    x = btnX, y = 94, width = 20, height = 18,
  }, container)
  mapCtx.npcToggle:setFontSize(8)
  mapCtx.npcToggle:setClickCallback(function()
    gm.filterNPCs = not gm.filterNPCs
    WuxiaGUI3._updateNpcToggle()
    WuxiaGUI3._renderGraphMap()
  end)
  mapCtx.npcToggle:setOnEnter(function()
    local state = gm.filterNPCs and "開" or "關"
    showBtnTip(mapCtx.npcToggle, "NPC 標記 (" .. state .. ")")
  end, mapCtx.npcToggle)
  mapCtx.npcToggle:setOnLeave(function()
    hideBtnTip()
  end, mapCtx.npcToggle)
  mapCtx.npcToggle:raiseAll()
  WuxiaGUI3._updateNpcToggleForCtx(mapCtx)

  -- Help button
  mapCtx.helpBtn = Geyser.Label:new({
    name = prefix .. "help",
    x = btnX, y = 114, width = 20, height = 18,
  }, container)
  mapCtx.helpBtn:setStyleSheet(btnCSS)
  mapCtx.helpBtn:setFontSize(8)
  mapCtx.helpBtn:echo("<font color='#cccccc'>?</font>")
  mapCtx.helpBtn:raiseAll()

  -- Help tooltip panel
  local helpContent =
    "<b>地圖說明</b><br><br>"
    .. "<b>操作：</b><br>"
    .. "滾輪 ─ 縮放<br>"
    .. "拖曳 ─ 平移<br>"
    .. "雙擊 ─ 回到當前位置<br>"
    .. (id == "mini" and "懸停房間 ─ 場景面板預覽<br>" or "")
    .. "<br><b>按鈕：</b><br>"
    .. "▲ ▼ ─ 切換樓層 (Z軸)<br>"
    .. "⊕ ─ 回到當前位置<br>"
    .. "👤 ─ 顯示/隱藏 NPC 標記<br>"
    .. (id == "mini"
       and "&#8862; ─ 開啟/關閉大地圖 (F9)<br>"
       or  "&#9673; ─ 跟隨玩家 開/關<br>")
    .. "<br><b>房間標記：</b><br>"
    .. '<font color="#44FF44">★N</font> ─ 玩家數量<br>'
    .. '<font color="#FFFF44">●N</font> ─ NPC 數量<br>'
    .. '<font color="#AAAAAA">◆N</font> ─ 物品數量<br>'
    .. "📍 ─ 當前位置<br>"
    .. "▲ ▼ ─ 有上/下出口<br>"
    .. "<br><b>房間顏色：</b><br>"
    .. '<font color="#C8B89A">■</font> 戶外　'
    .. '<font color="#D4A017">■</font> 商店　'
    .. '<font color="#5B8DBE">■</font> 客棧<br>'
    .. '<font color="#B8860B">■</font> 銀行　'
    .. '<font color="#8B7355">■</font> 室內　'
    .. '<font color="#4A90D9">■</font> 渡口<br>'
    .. '<font color="#7B4F9D">■</font> 地下城　'
    .. '<font color="#2CA58D">■</font> 聊天室<br>'
    .. "<br>亮色 ＝ 可見範圍　暗色 ＝ 已探索"

  local tipY = 0
  if helpTipParent ~= container then
    tipY = container:get_y() - (helpTipParent and helpTipParent:get_y() or 0)
  end
  mapCtx.helpTip = Geyser.Label:new({
    name = prefix .. "helpTip",
    x = 14, y = tipY, width = cw - 40, height = 440,
  }, helpTipParent)
  mapCtx.helpTip:setStyleSheet(
    "background-color:rgba(10,10,20,0.92); border:1px solid #888; border-radius:4px;"
    .. " padding:8px; qproperty-wordWrap:true; qproperty-alignment:'AlignLeft|AlignTop';")
  mapCtx.helpTip:setFontSize(8)
  mapCtx.helpTip:echo(helpContent)
  mapCtx.helpTip:hide()
  if mapCtx.helpTip.enableClickthrough then mapCtx.helpTip:enableClickthrough() end

  mapCtx.helpBtn:setOnEnter(function()
    mapCtx.helpBtn:setStyleSheet(btnHoverCSS)
    mapCtx.helpBtn:echo("<font color='#ffffff'>?</font>")
    mapCtx.helpTip:show()
    mapCtx.helpTip:raiseAll()
    mapCtx.helpBtn:raiseAll()
  end, mapCtx.helpBtn)
  mapCtx.helpBtn:setOnLeave(function()
    mapCtx.helpBtn:setStyleSheet(btnCSS)
    mapCtx.helpBtn:echo("<font color='#cccccc'>?</font>")
    mapCtx.helpTip:hide()
  end, mapCtx.helpBtn)

  -- ─── Context-specific button at y=134 ───
  if id == "mini" then
    -- Big map toggle button (minimap only)
    mapCtx.bigMapBtn = Geyser.Label:new({
      name = prefix .. "bigMapBtn",
      x = btnX, y = 134, width = 20, height = 18,
    }, container)
    mapCtx.bigMapBtn:setStyleSheet(btnCSS)
    mapCtx.bigMapBtn:setFontSize(8)
    mapCtx.bigMapBtn:echo("<font color='#cccccc'>&#8862;</font>")
    mapCtx.bigMapBtn:setClickCallback(function()
      WuxiaGUI3._toggleBigMap()
    end)
    mapCtx.bigMapBtn:setOnEnter(function()
      mapCtx.bigMapBtn:setStyleSheet(btnHoverCSS)
      mapCtx.bigMapBtn:echo("<font color='#ffffff'>&#8862;</font>")
      showBtnTip(mapCtx.bigMapBtn, "大地圖 (F9)")
    end, mapCtx.bigMapBtn)
    mapCtx.bigMapBtn:setOnLeave(function()
      mapCtx.bigMapBtn:setStyleSheet(btnCSS)
      mapCtx.bigMapBtn:echo("<font color='#cccccc'>&#8862;</font>")
      hideBtnTip()
    end, mapCtx.bigMapBtn)
    mapCtx.bigMapBtn:raiseAll()
  elseif id == "big" then
    -- Follow-player toggle button (big map only)
    mapCtx.followBtn = Geyser.Label:new({
      name = prefix .. "followBtn",
      x = btnX, y = 134, width = 20, height = 18,
    }, container)
    mapCtx.followBtn:setFontSize(8)
    mapCtx.followBtn:setClickCallback(function()
      mapCtx.followPlayer = not mapCtx.followPlayer
      WuxiaGUI3._updateFollowToggleForCtx(mapCtx)
      if mapCtx.followPlayer then
        mapCtx.panX = 0
        mapCtx.panY = 0
        local cur = gm.rooms[gm.currentRoom]
        if cur then mapCtx.currentZ = cur.z or 0 end
        WuxiaGUI3._renderMapCtx(mapCtx)
      end
    end)
    mapCtx.followBtn:setOnEnter(function()
      local state = mapCtx.followPlayer and "開" or "關"
      showBtnTip(mapCtx.followBtn, "跟隨玩家 (" .. state .. ")")
    end, mapCtx.followBtn)
    mapCtx.followBtn:setOnLeave(function()
      hideBtnTip()
    end, mapCtx.followBtn)
    mapCtx.followBtn:raiseAll()
    WuxiaGUI3._updateFollowToggleForCtx(mapCtx)
  end

  -- ─── Zoom: mouse wheel ───
  container:setWheelCallback(function(event)
    if not event then return end
    local delta = event.angleDeltaY or 0
    local oldZoom = mapCtx.zoom

    if delta > 0 then
      mapCtx.zoom = math.min(MAP_MAX_ZOOM, mapCtx.zoom * MAP_ZOOM_FACTOR)
    elseif delta < 0 then
      mapCtx.zoom = math.max(MAP_MIN_ZOOM, mapCtx.zoom / MAP_ZOOM_FACTOR)
    end

    local ratio = mapCtx.zoom / oldZoom
    local cw2 = container:get_width()
    local ch2 = container:get_height()
    local mx = event.x or (cw2 / 2)
    local my = event.y or (ch2 / 2)
    mapCtx.panX = mx - ratio * (mx - mapCtx.panX)
    mapCtx.panY = my - ratio * (my - mapCtx.panY)

    WuxiaGUI3._renderMapCtx(mapCtx)
  end)

  -- ─── Pan: click + drag ───
  container:setClickCallback(function(event)
    if not event then return end
    mapCtx.dragging = true
    mapCtx.dragStartX = event.x or 0
    mapCtx.dragStartY = event.y or 0
  end)

  container:setMoveCallback(function(event)
    if not event then return end

    if mapCtx.dragging then
      local dx = (event.x or 0) - mapCtx.dragStartX
      local dy = (event.y or 0) - mapCtx.dragStartY
      mapCtx.panX = mapCtx.panX + dx
      mapCtx.panY = mapCtx.panY + dy
      mapCtx.dragStartX = event.x or 0
      mapCtx.dragStartY = event.y or 0
      WuxiaGUI3._renderMapCtx(mapCtx)
      return
    end

    -- Hit-test rooms under cursor
    local mx = event.x or 0
    local my = event.y or 0
    local cAbsX = container:get_x()
    local cAbsY = container:get_y()
    local hitRid = nil
    for rid, pi in pairs(mapCtx.roomPoolMap) do
      local lbl = mapCtx.roomPool[pi]
      if lbl then
        local rx = lbl:get_x() - cAbsX
        local ry = lbl:get_y() - cAbsY
        local rw = lbl:get_width()
        local rh = lbl:get_height()
        if mx >= rx and mx < rx + rw and my >= ry and my < ry + rh then
          hitRid = rid
          break
        end
      end
    end

    if hitRid ~= mapCtx.hoveredRoom then
      mapCtx.hoveredRoom = hitRid
      WuxiaGUI3._renderMapCtx(mapCtx)
      if hitRid and hitRid ~= gm.currentRoom then
        if mapCtx.drivesScenePanel then
          WuxiaGUI3._updateScenePanel(hitRid)
        end
      else
        if mapCtx.drivesScenePanel then
          WuxiaGUI3._updateScenePanel()
        end
      end
    end
  end)

  container:setReleaseCallback(function(event)
    mapCtx.dragging = false
  end)

  -- ─── Leave: revert hover state ───
  container:setOnLeave(function()
    if mapCtx.hoveredRoom then
      mapCtx.hoveredRoom = nil
      WuxiaGUI3._renderMapCtx(mapCtx)
      if mapCtx.drivesScenePanel then
        WuxiaGUI3._updateScenePanel()
      end
    end
  end)

  -- ─── Double-click: re-center on player ───
  if container.setDoubleClickCallback then
    container:setDoubleClickCallback(function()
      mapCtx.panX = 0
      mapCtx.panY = 0
      local room = gm.rooms[gm.currentRoom]
      if room then mapCtx.currentZ = room.z or 0 end
      WuxiaGUI3._renderMapCtx(mapCtx)
    end)
  end

  return mapCtx
end

-- ─── NPC toggle style update (per-context) ───
function WuxiaGUI3._updateNpcToggleForCtx(mapCtx)
  if not mapCtx or not mapCtx.npcToggle then return end
  local btn = mapCtx.npcToggle
  if WuxiaGUI3.graphMap.filterNPCs then
    btn:setStyleSheet(
      "background-color:rgba(40,40,60,0.85); border:1px solid #C8A84E; border-radius:2px; qproperty-alignment:AlignCenter;")
    btn:echo("<font color='#C8A84E' size='2'>👥</font>")
  else
    btn:setStyleSheet(
      "background-color:rgba(20,20,40,0.7); border:1px solid #555; border-radius:2px; qproperty-alignment:AlignCenter;")
    btn:echo("<font color='#666666' size='2'>👥</font>")
  end
end

-- ─── NPC toggle wrapper (updates all contexts) ───
function WuxiaGUI3._updateNpcToggle()
  WuxiaGUI3._updateNpcToggleForCtx(WuxiaGUI3.miniMapCtx)
  WuxiaGUI3._updateNpcToggleForCtx(WuxiaGUI3.bigMapCtx)
end

-- ─── Render single edge (1 or 2 segments for diagonal; returns # pool labels used) ───
function WuxiaGUI3._mapTryRenderEdge(mapCtx, gm, edge, cx, cy, cw, ch)
  local roomA = gm.rooms[edge.from]
  local roomB = gm.rooms[edge.to]
  if not roomA or not roomB then return 0 end

  -- Both must be on current Z
  if (roomA.z or 0) ~= mapCtx.currentZ then return 0 end
  if (roomB.z or 0) ~= mapCtx.currentZ then return 0 end

  -- Both ends must be explored or visible
  local aKnown = gm.visibleRooms[edge.from] or gm.exploredRooms[edge.from]
  local bKnown = gm.visibleRooms[edge.to] or gm.exploredRooms[edge.to]
  if not aKnown or not bKnown then return 0 end

  -- Skip unreasonably long edges (stray connections to distant rooms)
  local wdx = (roomA.x or 0) - (roomB.x or 0)
  local wdy = (roomA.y or 0) - (roomB.y or 0)
  if wdx * wdx + wdy * wdy > 64 then return 0 end  -- >8 world units apart

  -- Smart attachment points: align Y for E-W gaps, X for N-S gaps
  local ayMin = roomA.y or 0
  local ayMax = ayMin + (roomA.wid or 1)
  local byMin = roomB.y or 0
  local byMax = byMin + (roomB.wid or 1)
  local axMin = roomA.x or 0
  local axMax = axMin + (roomA.len or 1)
  local bxMin = roomB.x or 0
  local bxMax = bxMin + (roomB.len or 1)
  local yOvMin = math.max(ayMin, byMin)
  local yOvMax = math.min(ayMax, byMax)
  local xOvMin = math.max(axMin, bxMin)
  local xOvMax = math.min(axMax, bxMax)

  local aCx, aCy, bCx, bCy
  if yOvMax > yOvMin and (axMax <= bxMin or bxMax <= axMin) then
    -- E-W separated with Y overlap: align at shared Y midpoint
    local sharedY = (yOvMin + yOvMax) / 2
    aCx = axMin + (roomA.len or 1) / 2
    aCy = sharedY
    bCx = bxMin + (roomB.len or 1) / 2
    bCy = sharedY
  elseif xOvMax > xOvMin and (ayMax <= byMin or byMax <= ayMin) then
    -- N-S separated with X overlap: align at shared X midpoint
    local sharedX = (xOvMin + xOvMax) / 2
    aCx = sharedX
    aCy = ayMin + (roomA.wid or 1) / 2
    bCx = sharedX
    bCy = byMin + (roomB.wid or 1) / 2
  else
    -- Default (diagonal or overlapping): use room centers
    aCx = axMin + (roomA.len or 1) / 2
    aCy = ayMin + (roomA.wid or 1) / 2
    bCx = bxMin + (roomB.len or 1) / 2
    bCy = byMin + (roomB.wid or 1) / 2
  end

  local ax = (aCx - cx) * MAP_GRID_PX * mapCtx.zoom + mapCtx.panX + cw / 2
  local ay = -((aCy - cy) * MAP_GRID_PX * mapCtx.zoom) + mapCtx.panY + ch / 2
  local bx = (bCx - cx) * MAP_GRID_PX * mapCtx.zoom + mapCtx.panX + cw / 2
  local by = -((bCy - cy) * MAP_GRID_PX * mapCtx.zoom) + mapCtx.panY + ch / 2

  -- Viewport cull: both points off same side → skip
  if (ax < 0 and bx < 0) or (ax > cw and bx > cw) then return 0 end
  if (ay < 0 and by < 0) or (ay > ch and by > ch) then return 0 end

  -- Room half-sizes in screen pixels (for boundary offset)
  local aHW = (roomA.len or 1) * MAP_GRID_PX * mapCtx.zoom / 2
  local aHH = (roomA.wid or 1) * MAP_GRID_PX * mapCtx.zoom / 2
  local bHW = (roomB.len or 1) * MAP_GRID_PX * mapCtx.zoom / 2
  local bHH = (roomB.wid or 1) * MAP_GRID_PX * mapCtx.zoom / 2

  -- Color: bright if both visible, dim otherwise
  local bothVis = gm.visibleRooms[edge.from] and gm.visibleRooms[edge.to]
  local color = bothVis and MAP_EDGE_COLOR or MAP_EDGE_COLOR_DIM
  local thick = MAP_EDGE_THICK
  local used = 0

  local dx = bx - ax
  local dy = by - ay

  if math.abs(dx) < 1 then
    -- Vertical line: offset endpoints to room boundaries
    local topY, botY
    if ay < by then
      topY = ay + aHH  -- bottom edge of top room
      botY = by - bHH  -- top edge of bottom room
    else
      topY = by + bHH
      botY = ay - aHH
    end
    if botY <= topY then return 0 end  -- rooms touch; handled by border removal

    local ex = math.floor(ax - thick / 2)
    local ey = math.floor(topY)
    local ew = thick
    local eh = math.max(1, math.floor(botY - topY))
    -- Clamp to drawing area
    if ex < 0 then ew = ew + ex; ex = 0 end
    if ey < 0 then eh = eh + ey; ey = 0 end
    if ex + ew > cw then ew = cw - ex end
    if ey + eh > ch then eh = ch - ey end
    if ew < 1 or eh < 1 then return 0 end

    local pi = mapCtx.nextEdgePool
    if pi > mapCtx.edgePoolSize then return used end
    mapCtx.nextEdgePool = pi + 1
    local lbl = mapCtx.edgePool[pi]
    lbl:move(ex + MAP_INSET, ey + MAP_INSET)
    lbl:resize(ew, eh)
    lbl:setStyleSheet(string.format("background-color: %s;", color))
    lbl:echo("")
    lbl:show()
    used = 1
  elseif math.abs(dy) < 1 then
    -- Horizontal line: offset endpoints to room boundaries
    local leftX, rightX
    if ax < bx then
      leftX = ax + aHW   -- right edge of left room
      rightX = bx - bHW  -- left edge of right room
    else
      leftX = bx + bHW
      rightX = ax - aHW
    end
    if rightX <= leftX then return 0 end  -- rooms touch; handled by border removal

    local ex = math.floor(leftX)
    local ey = math.floor(ay - thick / 2)
    local ew = math.max(1, math.floor(rightX - leftX))
    local eh = thick
    -- Clamp to drawing area
    if ex < 0 then ew = ew + ex; ex = 0 end
    if ey < 0 then eh = eh + ey; ey = 0 end
    if ex + ew > cw then ew = cw - ex end
    if ey + eh > ch then eh = ch - ey end
    if ew < 1 or eh < 1 then return 0 end

    local pi = mapCtx.nextEdgePool
    if pi > mapCtx.edgePoolSize then return used end
    mapCtx.nextEdgePool = pi + 1
    local lbl = mapCtx.edgePool[pi]
    lbl:move(ex + MAP_INSET, ey + MAP_INSET)
    lbl:resize(ew, eh)
    lbl:setStyleSheet(string.format("background-color: %s;", color))
    lbl:echo("")
    lbl:show()
    used = 1
  else
    -- Diagonal connection: offset endpoints to room boundaries
    local signX = (dx > 0) and 1 or -1
    local signY = (dy > 0) and 1 or -1
    local x1 = ax + signX * aHW
    local y1 = ay + signY * aHH
    local x2 = bx - signX * bHW
    local y2 = by - signY * bHH

    local adx = math.abs(x2 - x1)
    local ady = math.abs(y2 - y1)

    if adx < 2 and ady < 2 then return 0 end  -- rooms touch at corner; skip

    local lx = math.floor(math.min(x1, x2))
    local ly = math.floor(math.min(y1, y2))
    local lw = math.max(4, math.floor(adx))
    local lh = math.max(4, math.floor(ady))

    -- Clamp to drawing area
    if lx < 0 then lw = lw + lx; lx = 0 end
    if ly < 0 then lh = lh + ly; ly = 0 end
    if lx + lw > cw then lw = cw - lx end
    if ly + lh > ch then lh = ch - ly end
    if lw < 1 or lh < 1 then return 0 end

    -- Adaptive gradient: compute stops for constant-width diagonal line
    local diag = math.sqrt(adx * adx + ady * ady)
    local halfStop = thick / math.max(4, diag)
    halfStop = math.max(0.02, math.min(0.20, halfStop))

    local gx1, gy1, gx2, gy2
    if (dx > 0) == (dy > 0) then
      gx1, gy1, gx2, gy2 = 0, 0, 1, 1
    else
      gx1, gy1, gx2, gy2 = 1, 0, 0, 1
    end

    local pi = mapCtx.nextEdgePool
    if pi > mapCtx.edgePoolSize then return used end
    mapCtx.nextEdgePool = pi + 1
    local lbl = mapCtx.edgePool[pi]
    lbl:move(lx + MAP_INSET, ly + MAP_INSET)
    lbl:resize(lw, lh)
    lbl:setStyleSheet(string.format(
      "background-color: qlineargradient(x1:%d, y1:%d, x2:%d, y2:%d, " ..
      "stop:0 transparent, stop:%.4f transparent, " ..
      "stop:%.4f %s, stop:%.4f %s, " ..
      "stop:%.4f transparent, stop:1 transparent);",
      gx1, gy1, gx2, gy2,
      0.5 - halfStop,
      0.5 - halfStop * 0.3, color, 0.5 + halfStop * 0.3, color,
      0.5 + halfStop
    ))
    lbl:echo("")
    lbl:show()
    used = 1
  end

  return used
end

-- ─── Render single room (returns true if rendered, avoids goto/continue) ───
function WuxiaGUI3._mapTryRenderRoom(mapCtx, gm, rid, room, cx, cy, cw, ch, upDownInfo, openSidesInfo, poiCategory, roomEnts)
  -- Z-layer filter
  if (room.z or 0) ~= mapCtx.currentZ then return false end

  -- Must be explored or visible
  if not gm.exploredRooms[rid] and not gm.visibleRooms[rid] then return false end

  -- World → screen: compute each boundary edge directly (avoids rounding gaps)
  local rx = room.x or 0
  local ry = room.y or 0
  local rl = room.len or 1
  local rw = room.wid or 1
  local G = MAP_GRID_PX * mapCtx.zoom
  local screenL = (rx - cx) * G + mapCtx.panX + cw / 2
  local screenR = (rx + rl - cx) * G + mapCtx.panX + cw / 2
  local screenT = -((ry + rw - cy) * G) + mapCtx.panY + ch / 2
  local screenB = -((ry - cy) * G) + mapCtx.panY + ch / 2

  local lx = math.floor(screenL)
  local ly = math.floor(screenT)
  local lw = math.max(2, math.floor(screenR) - lx)
  local lh = math.max(2, math.floor(screenB) - ly)
  if lx + lw < 0 or lx > cw or ly + lh < 0 or ly > ch then return false end

  -- Save original size before clamping (for center calculation)
  local origLw, origLh = lw, lh
  local clipL, clipT = 0, 0

  -- Clamp to drawing area so labels never extend past the border
  if lx < 0 then clipL = -lx; lw = lw + lx; lx = 0 end
  if ly < 0 then clipT = -ly; lh = lh + ly; ly = 0 end
  if lx + lw > cw then lw = cw - lx end
  if ly + lh > ch then lh = ch - ly end
  if lw < 2 or lh < 2 then return false end

  -- Assign a pool label
  local pi = mapCtx.nextRoomPool
  if pi > mapCtx.roomPoolSize then return false end
  mapCtx.nextRoomPool = pi + 1
  mapCtx.roomPoolMap[rid] = pi

  local label = mapCtx.roomPool[pi]
  label:move(lx + MAP_INSET, ly + MAP_INSET)
  label:resize(lw, lh)

  -- Determine color + border based on visibility state
  local rtype = room.room_type or "default"
  local isHovered = (rid == mapCtx.hoveredRoom)
  local color, bWall, bPass
  if gm.visibleRooms[rid] or rid == gm.currentRoom then
    color = MAP_ROOM_COLORS[rtype] or MAP_ROOM_COLORS.default
    bWall = "2px solid rgba(0,0,0,0.85)"
    bPass = "1px solid rgba(255,255,255,0.25)"
  else
    color = MAP_ROOM_COLORS_DIM[rtype] or MAP_ROOM_COLORS_DIM.default
    bWall = "2px solid rgba(0,0,0,0.70)"
    bPass = "1px solid rgba(0,0,0,0.25)"
  end

  -- Hover: override all borders with highlight color
  if isHovered then
    local hb = "2px solid " .. MAP_HOVER_COLOR
    bWall = hb
    bPass = hb
  end

  -- Per-side borders: bold wall on non-connected sides, subtle divider on connected
  if openSidesInfo then
    local os = openSidesInfo
    local bT = os.top and bPass or bWall
    local bR = os.right and bPass or bWall
    local bB = os.bottom and bPass or bWall
    local bL = os.left and bPass or bWall
    label:setStyleSheet(string.format(
      "background-color: %s; border-top: %s; border-right: %s; border-bottom: %s; border-left: %s;",
      color, bT, bR, bB, bL
    ))
  else
    label:setStyleSheet(string.format(
      "background-color: %s; border: %s; border-radius: 2px;",
      color, bWall
    ))
  end

  -- Rich tooltip: room name + services + NPCs + players
  local tipLines = { "<b>" .. (room.name or rid) .. "</b>" }
  -- POI service tag
  local poiNames = { shop="商店", bank="銀行", inn="客棧", transport="傳送點" }
  if poiCategory and poiNames[poiCategory] then
    tipLines[#tipLines + 1] = '<font color="#FFD700">' .. poiNames[poiCategory] .. '</font>'
  end
  -- Entities in this room (from pre-built lookup)
  if roomEnts then
    for _, edata in ipairs(roomEnts) do
      local lbl = ansiToHtml(edata.label or edata.id or "")
      if edata.type == "npc" then
        local clr = "#FFFF44"
        local flags = edata.flags
        if flags then
          for _, f in ipairs(flags) do
            if f == "hostile"  then clr = "#FF4444" end
            if f == "vendor"   then clr = "#FFAA22" end
            if f == "quest"    then clr = "#44AAFF" end
            if f == "trainer"  then clr = "#AA44FF" end
          end
        end
        tipLines[#tipLines + 1] = '<font color="' .. clr .. '">' .. lbl .. '</font>'
      elseif edata.type == "player" then
        tipLines[#tipLines + 1] = '<font color="#44FF44">' .. lbl .. '</font>'
      elseif edata.type == "item" then
        tipLines[#tipLines + 1] = '<font color="#AAAAAA">' .. lbl .. '</font>'
      end
    end
  end
  label:setToolTip(table.concat(tipLines, "<br>"))

  -- Current room pin + up/down exit indicators (▲/▼) + entity count badges
  local txt = ""
  if rid == gm.currentRoom then
    txt = '<span style="font-size:8pt;">📍</span>'
  end
  if upDownInfo then
    if upDownInfo.up then txt = txt .. '<span style="color:#E0E0E0; font-size:6pt;">▲</span>' end
    if upDownInfo.down then txt = txt .. '<span style="color:#E0E0E0; font-size:6pt;">▼</span>' end
  end

  -- Entity count badges (only for visible rooms)
  if roomEnts and gm.visibleRooms[rid] then
    local npcCount, playerCount, itemCount = 0, 0, 0
    local npcPriColor = MAP_ENTITY_COLORS.npc_normal  -- default NPC color
    for _, edata in ipairs(roomEnts) do
      if edata.type == "npc" and gm.filterNPCs then
        npcCount = npcCount + 1
        local flags = edata.flags
        if flags then
          for _, f in ipairs(flags) do
            if f == "hostile"  then npcPriColor = MAP_ENTITY_COLORS.npc_hostile end
            if f == "vendor"   then npcPriColor = MAP_ENTITY_COLORS.npc_vendor end
            if f == "quest"    then npcPriColor = MAP_ENTITY_COLORS.npc_quest end
            if f == "trainer"  then npcPriColor = MAP_ENTITY_COLORS.npc_trainer end
          end
        end
      elseif edata.type == "player" and rid ~= gm.currentRoom then
        playerCount = playerCount + 1
      elseif edata.type == "item" then
        itemCount = itemCount + 1
      end
    end
    local badges = ""
    local bStyle = "font-size:6pt;"
    if playerCount > 0 then
      badges = badges .. '<span style="color:' .. MAP_ENTITY_COLORS.player .. '; ' .. bStyle .. '">★' .. playerCount .. '</span>'
    end
    if npcCount > 0 then
      if badges ~= "" then badges = badges .. " " end
      badges = badges .. '<span style="color:' .. npcPriColor .. '; ' .. bStyle .. '">●' .. npcCount .. '</span>'
    end
    if itemCount > 0 then
      if badges ~= "" then badges = badges .. " " end
      badges = badges .. '<span style="color:' .. MAP_ENTITY_COLORS.item .. '; ' .. bStyle .. '">◆' .. itemCount .. '</span>'
    end
    if badges ~= "" then
      if txt ~= "" then txt = txt .. "<br>" end
      txt = txt .. badges
    end
  end

  if txt ~= "" then
    -- Only show text if room's true center is within the visible (clamped) portion
    local trueCX = origLw / 2 - clipL
    local trueCY = origLh / 2 - clipT
    if trueCX > 2 and trueCX < lw - 2 and trueCY > 2 and trueCY < lh - 2 then
      label:echo('<center>' .. txt .. '</center>')
    else
      label:echo("")
    end
  else
    label:echo("")
  end

  label:show()
  return true
end


-- ─── Main render function ───
-- ─── Render a single map view context ───
function WuxiaGUI3._renderMapCtx(mapCtx)
  if not mapCtx or not mapCtx.container then return end
  local gm = WuxiaGUI3.graphMap
  if not gm then return end

  -- Container dimensions (reduced by inset to keep rooms inside border)
  local cw = mapCtx.container:get_width() - 2 * MAP_INSET
  local ch = mapCtx.container:get_height() - 2 * MAP_INSET
  if cw <= 0 then cw = 268 end
  if ch <= 0 then ch = 156 end

  -- Center on current room (x,y = SW corner; center = corner + size/2)
  local cx, cy = 0, 0
  local cur = gm.rooms[gm.currentRoom]
  if cur then
    cx = (cur.x or 0) + (cur.len or 1) / 2
    cy = (cur.y or 0) + (cur.wid or 1) / 2
  end

  -- Reset pools: hide all labels
  for i = 1, mapCtx.edgePoolSize do
    if mapCtx.edgePool[i] then mapCtx.edgePool[i]:hide() end
  end
  mapCtx.nextEdgePool = 1
  for i = 1, mapCtx.roomPoolSize do
    if mapCtx.roomPool[i] then mapCtx.roomPool[i]:hide() end
  end
  mapCtx.roomPoolMap = {}
  mapCtx.nextRoomPool = 1

  -- Render edges first (behind rooms in z-order)
  local drawnPairs = {}
  for eid, edge in pairs(gm.edges) do
    local pairKey
    if edge.from < edge.to then
      pairKey = edge.from .. "|" .. edge.to
    else
      pairKey = edge.to .. "|" .. edge.from
    end
    if not drawnPairs[pairKey] then
      drawnPairs[pairKey] = true
      WuxiaGUI3._mapTryRenderEdge(mapCtx, gm, edge, cx, cy, cw, ch)
    end
  end

  -- Pre-compute up/down indicators AND open-sides from edges
  local roomUpDown = {}
  local roomOpenSides = {}
  for eid, edge in pairs(gm.edges) do
    local cmd = edge.cmd
    if cmd == "up" or cmd == "down" then
      local rid = edge.from
      if not roomUpDown[rid] then roomUpDown[rid] = {} end
      roomUpDown[rid][cmd] = true
    end

    local rA = gm.rooms[edge.from]
    local rB = gm.rooms[edge.to]
    if rA and rB and (rA.z or 0) == mapCtx.currentZ and (rB.z or 0) == mapCtx.currentZ then
      local aKnown = gm.visibleRooms[edge.from] or gm.exploredRooms[edge.from]
      local bKnown = gm.visibleRooms[edge.to] or gm.exploredRooms[edge.to]
      if aKnown and bKnown then
        local ax2, ay2 = rA.x or 0, rA.y or 0
        local al, aw2 = rA.len or 1, rA.wid or 1
        local bx2, by2 = rB.x or 0, rB.y or 0
        local bl, bw2 = rB.len or 1, rB.wid or 1
        local yOverlap = math.max(ay2, by2) < math.min(ay2 + aw2, by2 + bw2)
        local xOverlap = math.max(ax2, bx2) < math.min(ax2 + al, bx2 + bl)
        if yOverlap then
          if ax2 + al == bx2 then
            if not roomOpenSides[edge.from] then roomOpenSides[edge.from] = {} end
            roomOpenSides[edge.from].right = true
            if not roomOpenSides[edge.to] then roomOpenSides[edge.to] = {} end
            roomOpenSides[edge.to].left = true
          elseif bx2 + bl == ax2 then
            if not roomOpenSides[edge.from] then roomOpenSides[edge.from] = {} end
            roomOpenSides[edge.from].left = true
            if not roomOpenSides[edge.to] then roomOpenSides[edge.to] = {} end
            roomOpenSides[edge.to].right = true
          end
        end
        if xOverlap then
          if ay2 + aw2 == by2 then
            if not roomOpenSides[edge.from] then roomOpenSides[edge.from] = {} end
            roomOpenSides[edge.from].top = true
            if not roomOpenSides[edge.to] then roomOpenSides[edge.to] = {} end
            roomOpenSides[edge.to].bottom = true
          elseif by2 + bw2 == ay2 then
            if not roomOpenSides[edge.from] then roomOpenSides[edge.from] = {} end
            roomOpenSides[edge.from].bottom = true
            if not roomOpenSides[edge.to] then roomOpenSides[edge.to] = {} end
            roomOpenSides[edge.to].top = true
          end
        end
      end
    end
  end

  -- Pre-compute POI categories per room
  local roomPOI = {}
  for _, pdata in pairs(gm.pois) do
    if pdata.room and pdata.category then
      roomPOI[pdata.room] = pdata.category
    end
  end

  -- Pre-compute entities per room
  local roomEnts = {}
  for _, edata in pairs(gm.entities) do
    if edata.room then
      if not roomEnts[edata.room] then roomEnts[edata.room] = {} end
      local t = roomEnts[edata.room]
      t[#t + 1] = edata
    end
  end

  -- Render rooms (on top of edges)
  for rid, room in pairs(gm.rooms) do
    WuxiaGUI3._mapTryRenderRoom(mapCtx, gm, rid, room, cx, cy, cw, ch,
      roomUpDown[rid], roomOpenSides[rid], roomPOI[rid], roomEnts[rid])
  end

  -- Update terrain background
  WuxiaGUI3._updateMapTerrainForCtx(mapCtx)

  -- Update Z display and raise toolbar
  if mapCtx.zDisp then
    mapCtx.zDisp:echo(
      string.format("<font color='#888888'>Z%d</font>", mapCtx.currentZ))
    mapCtx.zDisp:raiseAll()
  end
  if mapCtx.zUp then mapCtx.zUp:raiseAll() end
  if mapCtx.zDown then mapCtx.zDown:raiseAll() end
  if mapCtx.centerBtn then mapCtx.centerBtn:raiseAll() end
  if mapCtx.npcToggle then mapCtx.npcToggle:raiseAll() end
end

-- ─── Render all active map views (wrapper) ───
function WuxiaGUI3._renderGraphMap()
  if WuxiaGUI3.miniMapCtx then
    WuxiaGUI3._renderMapCtx(WuxiaGUI3.miniMapCtx)
  end
  if WuxiaGUI3.bigMapCtx and WuxiaGUI3._bigMapVisible then
    WuxiaGUI3._renderMapCtx(WuxiaGUI3.bigMapCtx)
  end
end

-- ─── Terrain background color (per-context) ───
function WuxiaGUI3._updateMapTerrainForCtx(mapCtx)
  if not mapCtx or not mapCtx.container then return end
  local gm = WuxiaGUI3.graphMap
  local room = gm.rooms[gm.currentRoom]
  if not room then return end

  local zone = room.zone or ""
  local terrain = MAP_ZONE_TO_TERRAIN[zone] or "default"
  local bgColor = MAP_ZONE_TERRAIN[terrain] or MAP_ZONE_TERRAIN.default

  mapCtx.container:setStyleSheet(string.format(
    "background-color: %s; border: 1px solid %s;",
    bgColor, BORDER
  ))
end

-- ─── Follow-player toggle visual update ───
function WuxiaGUI3._updateFollowToggleForCtx(mapCtx)
  if not mapCtx or not mapCtx.followBtn then return end
  local btnCSS_on  = "background-color:rgba(60,50,20,0.85); border:1px solid #B8860B; border-radius:2px; qproperty-alignment:AlignCenter;"
  local btnCSS_off = "background-color:rgba(20,20,40,0.7); border:1px solid #555; border-radius:2px; qproperty-alignment:AlignCenter;"
  if mapCtx.followPlayer then
    mapCtx.followBtn:setStyleSheet(btnCSS_on)
    mapCtx.followBtn:echo("<font color='#FFD700'>&#9673;</font>")
  else
    mapCtx.followBtn:setStyleSheet(btnCSS_off)
    mapCtx.followBtn:echo("<font color='#666666'>&#9673;</font>")
  end
end

-- ─── Big Map Window ───
function WuxiaGUI3._createBigMapWindow()
  WuxiaGUI3._bigMapWin = Geyser.UserWindow:new({
    name = "W3.bigMap.window",
    titleText = "地圖",
    x = 100, y = 100, width = 800, height = 600,
  })
  if WuxiaGUI3._bigMapWin.disableAutoDock then
    WuxiaGUI3._bigMapWin:disableAutoDock()
  end
  -- Enforce minimum size (1.5x minimap = 408x408)
  if setUserWindowMinSize then
    setUserWindowMinSize("W3.bigMap.window", 408, 408)
  end
  local bmContainer = Geyser.Label:new({
    name = "W3.bigMap.area",
    x = 0, y = 0, width = "100%", height = "100%",
  }, WuxiaGUI3._bigMapWin)
  bmContainer:setStyleSheet("background-color: #2A2A2A;")
  bmContainer:echo("")

  WuxiaGUI3.bigMapCtx = WuxiaGUI3._createMapCtx(
    "big", bmContainer, bmContainer,
    { room = 300, edge = 500, entity = 60 }
  )
  WuxiaGUI3.bigMapCtx.drivesScenePanel = false
  WuxiaGUI3.bigMapCtx.followPlayer = true

  -- 9-slice frame overlay (same as minimap)
  local framePath = getMudletHomeDir() .. "/WuxiaGUI3/wuxia_left_map_frame.png"
  local fh = io.open(framePath, "r")
  if fh then
    fh:close()
    WuxiaGUI3._bigMapFrame = Geyser.Label:new({
      name = "W3.bigMap.frame",
      x = 0, y = 0, width = "100%", height = "100%",
    }, WuxiaGUI3._bigMapWin)
    WuxiaGUI3._bigMapFrame:setStyleSheet(
      "background-color:transparent;"
      .. " border-width: 35px 60px 38px 60px;"
      .. " border-image:url(" .. framePath .. ") 135 200 155 200 stretch stretch;")
    if WuxiaGUI3._bigMapFrame.enableClickthrough then
      WuxiaGUI3._bigMapFrame:enableClickthrough()
    end
  end

  -- Sync Z to current room
  local gm = WuxiaGUI3.graphMap
  local cur = gm.rooms[gm.currentRoom]
  if cur then WuxiaGUI3.bigMapCtx.currentZ = cur.z or 0 end

  -- Restore window position from previous session
  loadWindowLayout()

  WuxiaGUI3._bigMapVisible = false
  WuxiaGUI3._bigMapWin:hide()
end

function WuxiaGUI3._toggleBigMap()
  if not WuxiaGUI3._bigMapWin then
    WuxiaGUI3._createBigMapWindow()
  end
  WuxiaGUI3._bigMapVisible = not WuxiaGUI3._bigMapVisible
  if WuxiaGUI3._bigMapVisible then
    WuxiaGUI3._bigMapWin:show()
    if WuxiaGUI3.bigMapCtx.followPlayer then
      WuxiaGUI3.bigMapCtx.panX = 0
      WuxiaGUI3.bigMapCtx.panY = 0
      local gm = WuxiaGUI3.graphMap
      local cur = gm.rooms[gm.currentRoom]
      if cur then WuxiaGUI3.bigMapCtx.currentZ = cur.z or 0 end
    end
    WuxiaGUI3._renderMapCtx(WuxiaGUI3.bigMapCtx)
  else
    WuxiaGUI3._bigMapWin:hide()
  end
  -- Persist open/closed state
  saveWindowLayout()
  WuxiaGUI3._saveSettings()
end

-- ═══════════════════════════════════════════════
-- § 5  Chat Panel
-- ═══════════════════════════════════════════════

-- Lookup: channel display name → server command
function WuxiaGUI3._buildChat()
  local chatH = WuxiaGUI3._currentChatH or CHAT_H
  setBorderTop(chatH)

  -- Calculate chat panel width (between left and right panels)
  local screenW, _ = getMainWindowSize()
  local chatPanelW = (screenW or 800) - PW - LPW
  if chatPanelW < 200 then chatPanelW = 400 end

  WuxiaGUI3.chatMain = Geyser.Container:new({
    name = "W3.chat.main",
    x = LPW, y = 0,
    width = chatPanelW, height = chatH,
  })

  -- Background
  WuxiaGUI3.chatBg = Geyser.Label:new({
    name = "W3.chat.bg", x = 0, y = 0,
    width = "100%", height = "100%",
  }, WuxiaGUI3.chatMain)
  WuxiaGUI3.chatBg:setStyleSheet(string.format(
    "background-color: %s; border-bottom: 1px solid %s;", BG, BORDER))

  -- ─── Tab bar — built by _rebuildTabBar (called here and on Chat.Channels) ───
  WuxiaGUI3.chatTabButtons = {}
  WuxiaGUI3._rebuildTabBar()

  -- ─── Chat input line (bottom of chat area) ───
  local inputH = 22
  local labelW = 60

  -- Separator line above input
  WuxiaGUI3._chatInputLine = Geyser.Label:new({
    name = "W3.chat.inputLine",
    x = 0, y = -inputH,
    width = "100%", height = 1,
  }, WuxiaGUI3.chatMain)
  WuxiaGUI3._chatInputLine:setStyleSheet(string.format(
    "background-color: %s;", BORDER))

  -- Input field — full width, borderless
  WuxiaGUI3._chatInput = Geyser.CommandLine:new({
    name = "W3.chat.input",
    x = 0, y = -(inputH - 1),
    width = "100%", height = inputH - 1,
    fontSize = 9,
  }, WuxiaGUI3.chatMain)
  WuxiaGUI3._chatInput:setFontSize(9)
  WuxiaGUI3._chatInput:setStyleSheet(string.format([[
    background-color: %s;
    color: %s;
    border-top: none; border-left: none; border-right: none; border-bottom: 1px solid %s;
    padding-left: %dpx;
  ]], BG, TEXT, BORDER, labelW))
  WuxiaGUI3._chatInput:setAction(function(text)
    WuxiaGUI3._onChatInputEnter(text)
    WuxiaGUI3._chatInput:clear()
  end)

  -- Channel label prefix — overlays left side of input
  WuxiaGUI3._chatInputLabel = Geyser.Label:new({
    name = "W3.chat.inputLabel",
    x = 0, y = -(inputH - 1),
    width = labelW, height = inputH - 1,
  }, WuxiaGUI3.chatMain)
  WuxiaGUI3._chatInputLabel:setFontSize(9)
  WuxiaGUI3._chatInputLabel:echo(span(GOLD, "閒聊"))

  -- Read-only overlay (hidden by default, shown for read-only channels)
  WuxiaGUI3._chatInputOverlay = Geyser.Label:new({
    name = "W3.chat.inputOverlay",
    x = 0, y = -(inputH - 1),
    width = "100%", height = inputH - 1,
  }, WuxiaGUI3.chatMain)
  WuxiaGUI3._chatInputOverlay:setStyleSheet(string.format([[
    background-color: %s;
    color: %s;
    border-top: none; border-left: none; border-right: none; border-bottom: 1px solid %s;
    padding-left: 4px;
    qproperty-alignment: AlignVCenter;
  ]], BG, TEXT_DIM, BORDER))
  WuxiaGUI3._chatInputOverlay:setFontSize(9)
  WuxiaGUI3._chatInputOverlay:echo(span(TEXT_DIM, "此頻道為唯讀"))
  WuxiaGUI3._chatInputOverlay:hide()

  -- Default selected channel for 全部 tab (preserve loaded setting)
  WuxiaGUI3._allTabSendChannel = WuxiaGUI3._allTabSendChannel or "閒聊"

  WuxiaGUI3._updateChatInputState()

  -- ─── MiniConsoles: one per channel ───
  WuxiaGUI3.chatConsoles = {}

  for _, name in ipairs(ALL_CHANNEL_NAMES) do
    local con = Geyser.MiniConsole:new({
      name = "W3.chat.con."..name,
      x = 0, y = 22,
      width = "100%", height = "-22px",
      fontSize = 9,
      autoWrap = true,
      scrollBar = true,
    }, WuxiaGUI3.chatMain)
    con:setColor(17, 17, 34)
    con:setFontSize(9)
    con:hide()
    WuxiaGUI3.chatConsoles[name] = con
  end

  WuxiaGUI3.switchChatTab("全部")

  -- ─── Resize drag handle at bottom of chat ───
  WuxiaGUI3._chatResizeHandle = Geyser.Label:new({
    name = "W3.chat.resize",
    x = 0, y = -3,
    width = "100%", height = 6,
  }, WuxiaGUI3.chatMain)
  WuxiaGUI3._chatResizeHandle:setStyleSheet([[
    background-color: transparent;
    border: none;
  ]])
  -- Change cursor to resize indicator on hover
  WuxiaGUI3._chatResizeHandle:setOnEnter("WuxiaGUI3._onResizeEnter")
  WuxiaGUI3._chatResizeHandle:setOnLeave("WuxiaGUI3._onResizeLeave")
  WuxiaGUI3._chatResizeHandle:setClickCallback("WuxiaGUI3._onResizeClick")
end

-- ─── Chat resize logic ───
WuxiaGUI3._chatMinH = CHAT_H
WuxiaGUI3._currentChatH = CHAT_H
WuxiaGUI3._chatDragging = false

function WuxiaGUI3._getChatMaxH()
  local _, screenH = getMainWindowSize()
  return math.floor((screenH or 600) * 0.5)
end

function WuxiaGUI3._resizeChatTo(newH)
  local minH = WuxiaGUI3._chatMinH
  local maxH = WuxiaGUI3._getChatMaxH()
  newH = math.max(minH, math.min(newH, maxH))

  WuxiaGUI3._currentChatH = newH
  setBorderTop(newH)
  if WuxiaGUI3.chatMain then
    WuxiaGUI3.chatMain:resize(nil, newH)
  end

  -- Rebuild picker if open (position depends on chat height)
  if WuxiaGUI3._chatPicker then
    WuxiaGUI3._buildChatChannelPicker()
  end

  -- Reposition drawer if open
  if WuxiaGUI3._drawerOpen and WuxiaGUI3._drawer then
    -- Recalculate drawer height and rebuild
    WuxiaGUI3._destroyDrawer()
    WuxiaGUI3._buildChannelDrawer()
    if WuxiaGUI3._drawer then
      WuxiaGUI3._repositionDrawer()
      WuxiaGUI3._refreshDrawerState()
      WuxiaGUI3._renderDrawerPage()
      WuxiaGUI3._drawer:show()
      WuxiaGUI3._drawer:raise()
      if WuxiaGUI3._drawerBgLbl then WuxiaGUI3._drawerBgLbl:raise() end
      for _, cmd in ipairs(WuxiaGUI3._drawerChannelOrder or {}) do
        local btns = WuxiaGUI3._drawerBtns[cmd]
        if btns then
          btns.nameBtn:raise()
          btns.toggleBtn:raise()
        end
      end
      if WuxiaGUI3._drawerUpBtn then WuxiaGUI3._drawerUpBtn:raise() end
      if WuxiaGUI3._drawerDownBtn then WuxiaGUI3._drawerDownBtn:raise() end
      WuxiaGUI3._drawerOpen = true
    end
  end
end

function WuxiaGUI3._onResizeEnter()
  -- Visual hint: highlight the border
  if WuxiaGUI3._chatResizeHandle then
    WuxiaGUI3._chatResizeHandle:setStyleSheet(string.format([[
      background-color: %s;
      border: none;
    ]], GOLD_DIM))
  end
end

function WuxiaGUI3._onResizeLeave()
  if WuxiaGUI3._chatDragging then return end
  if WuxiaGUI3._chatResizeHandle then
    WuxiaGUI3._chatResizeHandle:setStyleSheet([[
      background-color: transparent;
      border: none;
    ]])
  end
end

function WuxiaGUI3._onResizeClick()
  -- Start drag: record initial mouse Y and chat height
  local _, mouseY = getMousePosition()
  WuxiaGUI3._chatDragging = true
  WuxiaGUI3._chatDragStartMouseY = mouseY
  WuxiaGUI3._chatDragStartH = WuxiaGUI3._currentChatH or CHAT_H

  -- Start a timer to track mouse movement
  if WuxiaGUI3._resizeTimerId then
    killTimer(WuxiaGUI3._resizeTimerId)
  end
  WuxiaGUI3._resizeTimerId = tempTimer(0.02, function()
    WuxiaGUI3._onResizeDragTick()
  end, true)  -- repeating

  -- Register a global release handler
  if WuxiaGUI3._resizeReleaseHandler then
    killAnonymousEventHandler(WuxiaGUI3._resizeReleaseHandler)
  end
  WuxiaGUI3._resizeReleaseHandler = registerAnonymousEventHandler(
    "sysWindowMouseReleaseEvent", "WuxiaGUI3._onResizeDragEnd")
end

function WuxiaGUI3._onResizeDragTick()
  if not WuxiaGUI3._chatDragging then
    if WuxiaGUI3._resizeTimerId then
      killTimer(WuxiaGUI3._resizeTimerId)
      WuxiaGUI3._resizeTimerId = nil
    end
    return
  end

  local _, mouseY = getMousePosition()
  if not mouseY then return end

  local deltaY = mouseY - WuxiaGUI3._chatDragStartMouseY
  local newH = WuxiaGUI3._chatDragStartH + deltaY
  WuxiaGUI3._resizeChatTo(newH)
end

function WuxiaGUI3._onResizeDragEnd()
  WuxiaGUI3._chatDragging = false

  if WuxiaGUI3._resizeTimerId then
    killTimer(WuxiaGUI3._resizeTimerId)
    WuxiaGUI3._resizeTimerId = nil
  end
  if WuxiaGUI3._resizeReleaseHandler then
    killAnonymousEventHandler(WuxiaGUI3._resizeReleaseHandler)
    WuxiaGUI3._resizeReleaseHandler = nil
  end

  -- Reset handle appearance
  if WuxiaGUI3._chatResizeHandle then
    WuxiaGUI3._chatResizeHandle:setStyleSheet([[
      background-color: transparent;
      border: none;
    ]])
  end

  -- Save new chat height
  WuxiaGUI3._saveSettings()
end

-- Handle Mudlet window resize: clamp chat height to 50% max
function WuxiaGUI3._onWindowResize()
  if not WuxiaGUI3._currentChatH then return end
  local maxH = WuxiaGUI3._getChatMaxH()
  if WuxiaGUI3._currentChatH > maxH then
    WuxiaGUI3._resizeChatTo(maxH)
  end

  -- Update chat panel and vitals bar width (pixel-based)
  local screenW, _ = getMainWindowSize()
  local newW = (screenW or 800) - PW - LPW
  if newW < 200 then newW = 400 end
  if WuxiaGUI3.chatMain then
    WuxiaGUI3.chatMain:resize(newW, nil)
  end
  if WuxiaGUI3._chatVitalsBar then
    WuxiaGUI3._chatVitalsBar:resize(newW, nil)
  end
end

-- ─── Channel Drawer (right side, scrollable) ───
-- A persistent vertical drawer on the right edge of the chat area.
-- Created once, shown/hidden by ⚙ button. Survives tab switches.
-- Scrollable with ▲/▼ buttons when channels exceed visible area.

WuxiaGUI3._drawerOpen = false
WuxiaGUI3._drawerScroll = 0  -- scroll offset (number of rows scrolled)

function WuxiaGUI3._buildChannelDrawer()
  WuxiaGUI3._destroyDrawer()

  if not WuxiaGUI3.channelList or #WuxiaGUI3.channelList == 0 then
    return
  end

  local drawerW = 120
  local itemH = 22
  local arrowH = 16

  -- Position: dropdown below the gear button
  local gearBtn = WuxiaGUI3.chatMoreBtn
  if not gearBtn then return end
  local gearX = WuxiaGUI3._gearRelX or 0
  local gearW = WuxiaGUI3._gearRelW or 22

  -- Anchor right edge of drawer to right edge of gear button
  local chatMainW = WuxiaGUI3.chatMain:get_width()
  local chatMainH = WuxiaGUI3._currentChatH or WuxiaGUI3.chatMain:get_height()
  local drawerRight = gearX + gearW
  local drawerX = drawerRight - drawerW
  if drawerX < 4 then drawerX = 4 end

  local maxH = chatMainH - 24 - 22 - 4
  local nChannels = #WuxiaGUI3.channelList
  local needsScroll = (nChannels * itemH) > maxH

  local contentH = maxH
  if needsScroll then
    contentH = contentH - arrowH * 2
  end
  local visibleRows = math.floor(contentH / itemH)
  visibleRows = math.min(visibleRows, nChannels)
  local drawerH = visibleRows * itemH + (needsScroll and arrowH * 2 or 0) + 4

  WuxiaGUI3._drawer = Geyser.Container:new({
    name = "W3.drawer",
    x = drawerX, y = 22,
    width = drawerW, height = drawerH,
  }, WuxiaGUI3.chatMain)

  -- Background
  WuxiaGUI3._drawerBgLbl = Geyser.Label:new({
    name = "W3.drawer.bg",
    x = 0, y = 0, width = "100%", height = "100%",
  }, WuxiaGUI3._drawer)
  WuxiaGUI3._drawerBgLbl:setStyleSheet(string.format([[
    background-color: %s;
    border: 1px solid %s;
  ]], BG2, GOLD_DIM))

  local yPos = 2

  -- Up arrow
  if needsScroll then
    WuxiaGUI3._drawerUpBtn = Geyser.Label:new({
      name = "W3.drawer.up",
      x = 2, y = yPos,
      width = drawerW - 4, height = arrowH,
    }, WuxiaGUI3._drawer)
    local upColor = (WuxiaGUI3._drawerScroll or 0) > 0 and GOLD or TEXT_DIM
    WuxiaGUI3._drawerUpBtn:setStyleSheet(string.format([[
      background-color: %s;
      border-bottom: 1px solid %s;
      qproperty-alignment: AlignCenter;
    ]], BG2, BORDER))
    WuxiaGUI3._drawerUpBtn:setFontSize(9)
    WuxiaGUI3._drawerUpBtn:echo(span(upColor, "▲"))
    WuxiaGUI3._drawerUpBtn:setClickCallback("WuxiaGUI3._drawerScrollUp")
    WuxiaGUI3._drawerUpBtn:setWheelCallback("WuxiaGUI3._onDrawerWheel")
    yPos = yPos + arrowH
  end

  -- Channel rows
  WuxiaGUI3._drawerBtns = {}
  WuxiaGUI3._drawerChannelOrder = {}
  WuxiaGUI3._drawerVisRows = visibleRows
  WuxiaGUI3._drawerNeedsScroll = needsScroll

  for i, ch in ipairs(WuxiaGUI3.channelList) do
    local dispName = WuxiaGUI3._cmdToTab(ch.cmd) or ch.cmd

    local nameBtn = Geyser.Label:new({
      name = "W3.drawer.n." .. ch.cmd,
      x = 4, y = 0, width = drawerW - 32, height = itemH,
    }, WuxiaGUI3._drawer)
    nameBtn:setFontSize(8)
    nameBtn:setClickCallback("WuxiaGUI3._viewChannel", ch.cmd)
    nameBtn:setWheelCallback("WuxiaGUI3._onDrawerWheel")

    local toggleBtn = Geyser.Label:new({
      name = "W3.drawer.g." .. ch.cmd,
      x = drawerW - 28, y = 0, width = 24, height = itemH,
    }, WuxiaGUI3._drawer)
    toggleBtn:setFontSize(9)
    toggleBtn:setClickCallback("WuxiaGUI3._toggleChannel", ch.cmd)
    toggleBtn:setWheelCallback("WuxiaGUI3._onDrawerWheel")

    WuxiaGUI3._drawerBtns[ch.cmd] = {
      nameBtn = nameBtn,
      toggleBtn = toggleBtn,
      dispName = dispName,
    }
    WuxiaGUI3._drawerChannelOrder[i] = ch.cmd
  end

  -- Down arrow
  if needsScroll then
    -- Will be positioned by _renderDrawerPage
    WuxiaGUI3._drawerDownBtn = Geyser.Label:new({
      name = "W3.drawer.down",
      x = 2, y = 0,
      width = drawerW - 4, height = arrowH,
    }, WuxiaGUI3._drawer)
    WuxiaGUI3._drawerDownBtn:setStyleSheet(string.format([[
      background-color: %s;
      border-top: 1px solid %s;
      qproperty-alignment: AlignCenter;
    ]], BG2, BORDER))
    WuxiaGUI3._drawerDownBtn:setFontSize(9)
    WuxiaGUI3._drawerDownBtn:echo(span(TEXT_DIM, "▼"))
    WuxiaGUI3._drawerDownBtn:setClickCallback("WuxiaGUI3._drawerScrollDown")
    WuxiaGUI3._drawerDownBtn:setWheelCallback("WuxiaGUI3._onDrawerWheel")
  end

  WuxiaGUI3._drawerScroll = 0
  WuxiaGUI3._refreshDrawerState()
  WuxiaGUI3._renderDrawerPage()

  WuxiaGUI3._drawer:hide()
  WuxiaGUI3._drawerOpen = false
end

-- Calculate how many rows fit in the visible area
function WuxiaGUI3._drawerVisibleRows()
  return WuxiaGUI3._drawerVisRows or 6
end

-- Position visible channel buttons based on scroll offset
function WuxiaGUI3._renderDrawerPage()
  if not WuxiaGUI3._drawerBtns or not WuxiaGUI3._drawerChannelOrder then return end

  local visRows = WuxiaGUI3._drawerVisibleRows()
  local total = #WuxiaGUI3._drawerChannelOrder
  local maxScroll = math.max(0, total - visRows)
  WuxiaGUI3._drawerScroll = math.max(0, math.min(WuxiaGUI3._drawerScroll, maxScroll))

  local arrowH = 16
  local itemH = 22
  local drawerW = 120
  local needsScroll = WuxiaGUI3._drawerNeedsScroll

  local startY = 2 + (needsScroll and arrowH or 0)

  for i, cmd in ipairs(WuxiaGUI3._drawerChannelOrder) do
    local btns = WuxiaGUI3._drawerBtns[cmd]
    local visIndex = i - WuxiaGUI3._drawerScroll
    if visIndex >= 1 and visIndex <= visRows then
      local by = startY + (visIndex - 1) * itemH
      btns.nameBtn:move(4, by)
      btns.toggleBtn:move(drawerW - 28, by)
      btns.nameBtn:show()
      btns.toggleBtn:show()
    else
      btns.nameBtn:hide()
      btns.toggleBtn:hide()
    end
  end

  -- Position down arrow after last visible row
  if needsScroll and WuxiaGUI3._drawerDownBtn then
    local dnY = startY + visRows * itemH
    WuxiaGUI3._drawerDownBtn:move(2, dnY)
  end

  -- Update scroll button states
  if WuxiaGUI3._drawerUpBtn then
    if WuxiaGUI3._drawerScroll > 0 then
      WuxiaGUI3._drawerUpBtn:echo(span(GOLD_DIM, "▲"))
    else
      WuxiaGUI3._drawerUpBtn:echo(span(TEXT_DIM, "▲"))
    end
  end
  if WuxiaGUI3._drawerDownBtn then
    if WuxiaGUI3._drawerScroll < maxScroll then
      WuxiaGUI3._drawerDownBtn:echo(span(GOLD_DIM, "▼"))
    else
      WuxiaGUI3._drawerDownBtn:echo(span(TEXT_DIM, "▼"))
    end
  end
end

function WuxiaGUI3._drawerScrollUp()
  WuxiaGUI3._drawerScroll = math.max(0, WuxiaGUI3._drawerScroll - 1)
  WuxiaGUI3._renderDrawerPage()
end

function WuxiaGUI3._drawerScrollDown()
  WuxiaGUI3._drawerScroll = WuxiaGUI3._drawerScroll + 1
  WuxiaGUI3._renderDrawerPage()
end

-- Refresh drawer button colors based on channelEnabled state
function WuxiaGUI3._refreshDrawerState()
  if not WuxiaGUI3._drawerBtns then return end

  for cmd, btns in pairs(WuxiaGUI3._drawerBtns) do
    local enabled = WuxiaGUI3.channelEnabled[cmd]
    local dispName = btns.dispName

    if enabled then
      btns.nameBtn:setStyleSheet([[
        background-color: #1a2a1a;
        border: 1px solid #336633;
        qproperty-alignment: AlignCenter;
      ]])
      btns.nameBtn:echo(span("#ccddcc", dispName))
      btns.toggleBtn:setStyleSheet([[
        background-color: #1a3a1a;
        border: 1px solid #33aa44;
        qproperty-alignment: AlignCenter;
      ]])
      btns.toggleBtn:echo(span("#33aa44", "●"))
    else
      btns.nameBtn:setStyleSheet([[
        background-color: #2a1a1a;
        border: 1px solid #663333;
        qproperty-alignment: AlignCenter;
      ]])
      btns.nameBtn:echo(span("#887777", dispName))
      btns.toggleBtn:setStyleSheet([[
        background-color: #3a1a1a;
        border: 1px solid #aa3333;
        qproperty-alignment: AlignCenter;
      ]])
      btns.toggleBtn:echo(span("#aa3333", "○"))
    end
  end
end

-- Toggle drawer open/close
function WuxiaGUI3._toggleDrawer()
  if WuxiaGUI3._drawerOpen then
    if WuxiaGUI3._drawer then WuxiaGUI3._drawer:hide() end
    WuxiaGUI3._drawerOpen = false
    return
  end

  -- Always rebuild to use current chat height
  WuxiaGUI3._destroyDrawer()
  WuxiaGUI3._buildChannelDrawer()
  if not WuxiaGUI3._drawer then return end

  -- Reposition to current gear button location
  WuxiaGUI3._repositionDrawer()
  WuxiaGUI3._refreshDrawerState()
  WuxiaGUI3._renderDrawerPage()
  WuxiaGUI3._drawer:show()
  WuxiaGUI3._drawer:raise()
  -- Raise all children
  if WuxiaGUI3._drawerBgLbl then WuxiaGUI3._drawerBgLbl:raise() end
  for _, cmd in ipairs(WuxiaGUI3._drawerChannelOrder or {}) do
    local btns = WuxiaGUI3._drawerBtns[cmd]
    if btns then
      btns.nameBtn:raise()
      btns.toggleBtn:raise()
    end
  end
  if WuxiaGUI3._drawerUpBtn then WuxiaGUI3._drawerUpBtn:raise() end
  if WuxiaGUI3._drawerDownBtn then WuxiaGUI3._drawerDownBtn:raise() end
  WuxiaGUI3._drawerOpen = true
end

-- Reposition drawer to anchor below the gear button
function WuxiaGUI3._repositionDrawer()
  if not WuxiaGUI3._drawer or not WuxiaGUI3.chatMoreBtn then return end

  local gearX = WuxiaGUI3._gearRelX or 0
  local gearW = WuxiaGUI3._gearRelW or 22
  local drawerW = WuxiaGUI3._drawer:get_width()
  local chatMainW = WuxiaGUI3.chatMain:get_width()

  -- Default: anchor top-left of drawer to bottom-left of gear
  local drawerX = gearX

  -- If drawer would go off right edge, anchor top-right to bottom-right of gear
  if drawerX + drawerW > chatMainW - 4 then
    drawerX = gearX + gearW - drawerW
  end

  -- Clamp to not go off left edge
  if drawerX < 4 then drawerX = 4 end

  WuxiaGUI3._drawer:move(drawerX, 22)
end

-- Resize all chat consoles to accommodate drawer
function WuxiaGUI3._resizeConsoles()
  for name, con in pairs(WuxiaGUI3.chatConsoles or {}) do
    con:resize("100%", "-22px")
  end
end

function WuxiaGUI3._destroyDrawer()
  WuxiaGUI3._drawerBtns = nil
  WuxiaGUI3._drawerChannelOrder = nil
  if WuxiaGUI3._drawer then
    WuxiaGUI3._drawer:hide()
    WuxiaGUI3._drawer = nil
  end
  WuxiaGUI3._drawerOpen = false
end

-- Aliases for old function names
function WuxiaGUI3._showChannelPanel() WuxiaGUI3._toggleDrawer() end
function WuxiaGUI3._hideChannelPanel() end  -- no-op, drawer is persistent
function WuxiaGUI3._toggleMoreChannels() WuxiaGUI3._toggleDrawer() end

-- Click channel name → switch to view that channel (add temp tab if needed)
function WuxiaGUI3._viewChannel(cmd)
  local dispName = WuxiaGUI3._cmdToTab(cmd)
  if not dispName then return end

  -- Create console if it doesn't exist
  if not WuxiaGUI3.chatConsoles[dispName] then
    local con = Geyser.MiniConsole:new({
      name = "W3.chat.con." .. dispName,
      x = 0, y = 22,
      width = "100%", height = "-22px",
      fontSize = 9,
      autoWrap = true,
      scrollBar = true,
    }, WuxiaGUI3.chatMain)
    con:setColor(17, 17, 34)
    con:setFontSize(9)
    con:hide()
    WuxiaGUI3.chatConsoles[dispName] = con
  end

  -- Add as temp tab if not already visible
  if not WuxiaGUI3.chatTabButtons[dispName] then
    WuxiaGUI3.tempTabs = WuxiaGUI3.tempTabs or {}
    local alreadyTemp = false
    for _, t in ipairs(WuxiaGUI3.tempTabs) do
      if t == dispName then alreadyTemp = true break end
    end
    if not alreadyTemp then
      WuxiaGUI3.tempTabs[#WuxiaGUI3.tempTabs + 1] = dispName
      WuxiaGUI3._ensureTabOrder(dispName)
    end
    WuxiaGUI3._rebuildTabBar()
  end

  -- Switch to that tab (drawer stays open)
  WuxiaGUI3.switchChatTab(dispName)
end

-- Click toggle icon → enable/disable channel
function WuxiaGUI3._toggleChannel(cmd)
  WuxiaGUI3.tuneChannel(cmd)
  -- Drawer state refreshes when Chat.Channels arrives from server
end

-- Right-click tab → remove temp tab
function WuxiaGUI3._onTabRightClick(tabName)
  if WuxiaGUI3.tempTabs then
    for i, t in ipairs(WuxiaGUI3.tempTabs) do
      if t == tabName then
        table.remove(WuxiaGUI3.tempTabs, i)
        WuxiaGUI3._rebuildTabBar()
        return
      end
    end
  end
end

-- ─── Switch chat tab ───
function WuxiaGUI3.switchChatTab(tabName)
  local prevTab = WuxiaGUI3.activeChatTab
  local needsRebuild = false

  -- Auto-close previous tab if it was a temp (unpinned) tab
  if prevTab and prevTab ~= tabName and prevTab ~= "全部"
     and not WuxiaGUI3._inRebuild then
    if not WuxiaGUI3._isTabPinned(prevTab) then
      for i, t in ipairs(WuxiaGUI3.tempTabs) do
        if t == prevTab then
          table.remove(WuxiaGUI3.tempTabs, i)
          needsRebuild = true
          break
        end
      end
    end
  end

  WuxiaGUI3.activeChatTab = tabName

  -- Clear unread for this tab
  WuxiaGUI3.unreadTabs[tabName] = nil
  -- Switching to 全部 clears all unread
  if tabName == "全部" then
    WuxiaGUI3.unreadTabs = {}
  end

  -- Show/hide consoles — only one visible at a time
  for name, con in pairs(WuxiaGUI3.chatConsoles) do
    if name == tabName then
      con:show()
    else
      con:hide()
    end
  end

  -- Update tab bar: rebuild if a temp tab was closed, otherwise just restyle
  if needsRebuild and not WuxiaGUI3._inRebuild then
    WuxiaGUI3._rebuildTabBar()
  else
    -- Auto-scroll to make active tab visible
    WuxiaGUI3._scrollToTab(tabName)
    WuxiaGUI3._updateTabStates()
  end
  WuxiaGUI3._hideBellDropdown()
  WuxiaGUI3._updateBellState()
  WuxiaGUI3._updateChatInputState()
end

-- ─── Public API: echo text to a chat tab (cecho format) ───
function WuxiaGUI3.chat(tabName, text, mirror)
  if not WuxiaGUI3.chatConsoles then return end
  local con = WuxiaGUI3.chatConsoles[tabName]
  if con then con:cecho(text.."\n") end
  if mirror ~= false and tabName ~= "全部" then
    local all = WuxiaGUI3.chatConsoles["全部"]
    if all then all:cecho(text.."\n") end
  end
  -- Mark tab as unread if not currently active
  WuxiaGUI3._markUnread(tabName)
end

-- ─── Public API: echo raw ANSI text to a chat tab ───
function WuxiaGUI3.chatAnsi(tabName, ansiText, mirror)
  if not WuxiaGUI3.chatConsoles then return end

  -- Strip trailing newlines (server send_msg already appends \n)
  ansiText = ansiText:gsub("[\r\n]+$", "")

  -- Convert ANSI escape sequences to decho format
  local dtext = WuxiaGUI3._ansiToDecho(ansiText)

  local con = WuxiaGUI3.chatConsoles[tabName]
  if con then con:decho(dtext .. "\n") end
  if mirror ~= false and tabName ~= "全部" then
    local all = WuxiaGUI3.chatConsoles["全部"]
    if all then all:decho(dtext .. "\n") end
  end
  -- Mark tab as unread if not currently active
  WuxiaGUI3._markUnread(tabName)
end

-- Mark a tab as having unread messages (if not currently viewing it)
-- unreadTabs stores counts: tabName → number
function WuxiaGUI3._markUnread(tabName)
  if tabName == "全部" then return end
  if tabName == WuxiaGUI3.activeChatTab then return end
  -- If viewing 全部, all messages are visible — don't mark unread
  if WuxiaGUI3.activeChatTab == "全部" then return end

  WuxiaGUI3.unreadTabs[tabName] = (WuxiaGUI3.unreadTabs[tabName] or 0) + 1
  WuxiaGUI3._updateTabStates()
  WuxiaGUI3._updateBellState()
end

-- ─── Bell notification button 🔔 ───
-- Appears between last tab and ⚙ when there are hidden unread messages.
-- Click to show dropdown of unread channels with counts.

function WuxiaGUI3._updateBellState()
  -- Collect hidden unread channels
  local hiddenUnreads = {}
  for tab, count in pairs(WuxiaGUI3.unreadTabs) do
    if tab ~= "全部" and count and count > 0 then
      -- Check if this tab is NOT visible in the tab bar
      if not WuxiaGUI3.chatTabButtons[tab] then
        hiddenUnreads[#hiddenUnreads + 1] = { name = tab, count = count }
      end
    end
  end

  if #hiddenUnreads > 0 then
    -- Show bell with count
    if WuxiaGUI3._bellBtn then
      local total = 0
      for _, u in ipairs(hiddenUnreads) do total = total + u.count end
      WuxiaGUI3._bellBtn:setStyleSheet(string.format([[
        background-color: %s;
        border-bottom: 2px solid #ff4444;
        qproperty-alignment: AlignCenter;
      ]], BG))
      local label = total > 99 and "🔔99+" or ("🔔" .. total)
      WuxiaGUI3._bellBtn:echo(span("#ff4444", label))
      WuxiaGUI3._bellBtn:show()
    end
  else
    -- Hide bell
    if WuxiaGUI3._bellBtn then
      WuxiaGUI3._bellBtn:hide()
    end
    -- Also hide dropdown
    WuxiaGUI3._hideBellDropdown()
  end

  -- Also update gear back to normal (bell handles the notification now)
  if WuxiaGUI3.chatMoreBtn then
    WuxiaGUI3.chatMoreBtn:setStyleSheet(string.format([[
      background-color: %s;
      border-bottom: 1px solid %s;
      qproperty-alignment: AlignCenter;
    ]], BG, BORDER))
    WuxiaGUI3.chatMoreBtn:echo(span(GOLD, "⚙"))
  end
end

-- Show bell dropdown: list of hidden unread channels with counts
function WuxiaGUI3._showBellDropdown()
  WuxiaGUI3._hideBellDropdown()

  -- Collect hidden unreads
  local items = {}
  for tab, count in pairs(WuxiaGUI3.unreadTabs) do
    if tab ~= "全部" and count and count > 0 and not WuxiaGUI3.chatTabButtons[tab] then
      items[#items + 1] = { name = tab, count = count }
    end
  end

  if #items == 0 then return end

  -- Sort by count descending
  table.sort(items, function(a, b) return a.count > b.count end)

  WuxiaGUI3._bellDropSeq = (WuxiaGUI3._bellDropSeq or 0) + 1
  local seq = WuxiaGUI3._bellDropSeq

  local rowH = 22
  local dropW = 140
  local dropH = #items * rowH + 4
  -- Position above bell button (dropdown goes upward from tab bar)
  local bellX = WuxiaGUI3._bellBtn and WuxiaGUI3._bellBtn:get_x() or 0

  WuxiaGUI3._bellDrop = Geyser.Label:new({
    name = "W3.bell.drop." .. seq,
    x = bellX, y = 24,
    width = dropW, height = dropH,
  }, WuxiaGUI3.chatMain)
  WuxiaGUI3._bellDrop:setStyleSheet(string.format([[
    background-color: %s;
    border: 1px solid %s;
  ]], BG2, GOLD))
  WuxiaGUI3._bellDrop:raise()

  WuxiaGUI3._bellDropBtns = {}
  for i, item in ipairs(items) do
    local by = 2 + (i - 1) * rowH
    local btn = Geyser.Label:new({
      name = "W3.bell.drop." .. seq .. "." .. item.name,
      x = 2, y = by,
      width = dropW - 4, height = rowH - 2,
    }, WuxiaGUI3._bellDrop)
    btn:setFontSize(8)
    btn:setStyleSheet(string.format([[
      background-color: %s;
      border-bottom: 1px solid %s;
      qproperty-alignment: AlignLeft;
    ]], BG, BORDER))

    local countStr = item.count > 99 and "99+" or tostring(item.count)
    btn:echo(span("#ffffff", " " .. item.name) .. span("#ff4444", " - " .. countStr .. " 條未讀"))
    -- Find the cmd for this tab name
    local cmd = WuxiaGUI3._tabToCmd(item.name)
    if cmd then
      btn:setClickCallback("WuxiaGUI3._bellClickChannel", cmd)
    end
    WuxiaGUI3._bellDropBtns[#WuxiaGUI3._bellDropBtns + 1] = btn
  end

  WuxiaGUI3._bellDropVisible = true
end

function WuxiaGUI3._hideBellDropdown()
  if WuxiaGUI3._bellDropBtns then
    for _, btn in ipairs(WuxiaGUI3._bellDropBtns) do btn:hide() end
    WuxiaGUI3._bellDropBtns = nil
  end
  if WuxiaGUI3._bellDrop then
    WuxiaGUI3._bellDrop:hide()
    WuxiaGUI3._bellDrop = nil
  end
  WuxiaGUI3._bellDropVisible = false
end

-- Click a channel in the bell dropdown → view it
function WuxiaGUI3._bellClickChannel(cmd)
  WuxiaGUI3._hideBellDropdown()
  WuxiaGUI3._viewChannel(cmd)
end

-- Toggle bell dropdown
function WuxiaGUI3._onBellClick()
  if WuxiaGUI3._bellDropVisible then
    WuxiaGUI3._hideBellDropdown()
  else
    WuxiaGUI3._showBellDropdown()
  end
end

-- ─── ANSI escape code to Mudlet decho converter ───
-- Maps SGR codes (e.g. \27[1;36m) to decho color tags (<r,g,b>)
function WuxiaGUI3._ansiToDecho(s)
  if not s then return "" end

  -- ANSI SGR color table: code → {r, g, b}
  local colors = {
    ["30"]  = {0,0,0},       ["31"]  = {170,0,0},
    ["32"]  = {0,170,0},     ["33"]  = {170,170,0},
    ["34"]  = {0,0,170},     ["35"]  = {170,0,170},
    ["36"]  = {0,170,170},   ["37"]  = {192,192,192},
    -- bright (bold+color)
    ["1;30"] = {85,85,85},   ["1;31"] = {255,85,85},
    ["1;32"] = {85,255,85},  ["1;33"] = {255,255,85},
    ["1;34"] = {85,85,255},  ["1;35"] = {255,85,255},
    ["1;36"] = {85,255,255}, ["1;37"] = {255,255,255},
  }

  local bold = false
  local result = ""
  local i = 1
  local len = #s

  while i <= len do
    -- Match ESC[ ... m  (ANSI escape sequence)
    local esc_start, esc_end, codes = s:find("\27%[([%d;]*)m", i)
    if esc_start then
      -- Append text before this escape
      if esc_start > i then
        result = result .. s:sub(i, esc_start - 1)
      end

      -- Parse the SGR codes
      if codes == "0" or codes == "" then
        -- Reset
        bold = false
        result = result .. "<r>"
      elseif codes == "1" then
        -- Bold only (apply on next color)
        bold = true
      else
        -- Try combined "bold;color" first
        local rgb = colors[codes]
        if not rgb and bold then
          -- Try bold variant
          rgb = colors["1;" .. codes]
        end
        if not rgb then
          rgb = colors[codes]
        end
        if rgb then
          result = result .. string.format("<%d,%d,%d>", rgb[1], rgb[2], rgb[3])
          -- Reset bold after applying
          if codes:find("^1;") then bold = false end
        end
      end

      i = esc_end + 1
    else
      -- No more escapes, append the rest
      result = result .. s:sub(i)
      break
    end
  end

  return result
end

-- ─── Public API: append current MUD line (with colors) to a chat tab ───
function WuxiaGUI3.chatAppend(tabName, mirror)
  if not WuxiaGUI3.chatConsoles then return end
  local con = WuxiaGUI3.chatConsoles[tabName]
  if con then
    selectCurrentLine()
    copy()
    appendBuffer("W3.chat.con."..tabName)
    if mirror ~= false and tabName ~= "全部" then
      appendBuffer("W3.chat.con.全部")
    end
    deselect()
    resetFormat()
  end
end

-- ═══════════════════════════════════════════════
-- § 4g  Chat via GMCP (no text triggers needed)
--
-- gmcp.Chat.Line       → route message to tab
-- gmcp.Chat.Channels   → receive channel list + enabled state
--
-- Client sends:
--   Chat.Channels.Tune  {"channel":"chat"}     → toggle on/off
--   Chat.Channels.Send  {"channel":"chat","message":"hi"} → send msg
-- ═══════════════════════════════════════════════

-- Channel state received from server
WuxiaGUI3.channelList = {}   -- { {cmd="chat", enabled=1}, ... }
WuxiaGUI3.channelEnabled = {} -- cmd → true/false

function WuxiaGUI3._registerChatGMCP()
  local h = WuxiaGUI3._handlers

  -- gmcp.Chat.Line — a chat message arrived
  h[#h+1] = registerAnonymousEventHandler("gmcp.Chat.Line", function()
    local gc = gmcp and gmcp.Chat and gmcp.Chat.Line
    if not gc then return end

    local channel = gc.channel or "sys"
    local raw = gc.raw  -- full ANSI-colored text from server

    -- Map server cmd → display tab name
    local tabName = WuxiaGUI3._cmdToTab(channel)

    if raw and raw ~= "" then
      -- Display the raw ANSI text with full color (same as tell() output)
      WuxiaGUI3.chatAnsi(tabName, raw)
    else
      -- Fallback: structured fields (no raw available)
      local speaker = gc.speaker or ""
      local message = gc.message or ""
      local line = "<gold>" .. speaker .. "<reset>：" .. message
      WuxiaGUI3.chat(tabName, line)
    end
  end)

  -- gmcp.Chat.Channels — full channel list with enabled state
  -- Dynamically creates tabs and consoles for channels from server.
  h[#h+1] = registerAnonymousEventHandler("gmcp.Chat.Channels", function()
    local gc = gmcp and gmcp.Chat and gmcp.Chat.Channels
    if not gc or not gc.channels then return end

    WuxiaGUI3.channelList = gc.channels
    WuxiaGUI3.channelEnabled = {}

    for _, ch in ipairs(gc.channels) do
      WuxiaGUI3.channelEnabled[ch.cmd] = (tonumber(ch.enabled) == 1)

      -- Ensure a MiniConsole exists for this channel
      local dispName = WuxiaGUI3._cmdToTab(ch.cmd)
      if dispName and not WuxiaGUI3.chatConsoles[dispName] then
        local con = Geyser.MiniConsole:new({
          name = "W3.chat.con." .. dispName,
          x = 0, y = 22,
          width = "100%", height = "-22px",
          fontSize = 9,
          autoWrap = true,
          scrollBar = true,
        }, WuxiaGUI3.chatMain)
        con:setColor(17, 17, 34)
        con:setFontSize(9)
        con:hide()
        WuxiaGUI3.chatConsoles[dispName] = con
      end
    end

    -- Rebuild the tab bar dynamically
    WuxiaGUI3._rebuildTabBar()

    -- Rebuild or refresh the channel drawer
    if not WuxiaGUI3._drawer then
      WuxiaGUI3._buildChannelDrawer()
    else
      WuxiaGUI3._refreshDrawerState()
    end
  end)

  -- Request channel list on startup
  sendGMCP("Chat.Channels.Request")

  -- Rebuild tab bar on window resize (scroll arrows may need to appear/disappear)
  h[#h+1] = registerAnonymousEventHandler("sysWindowResizeEvent", function()
    if WuxiaGUI3.chatMain then
      WuxiaGUI3._onWindowResize()
      WuxiaGUI3._rebuildTabBar()
    end
    if WuxiaGUI3._repositionInvBot then
      tempTimer(0.1, WuxiaGUI3._repositionInvBot)
    end
    if WuxiaGUI3._repositionTalent then
      tempTimer(0.1, WuxiaGUI3._repositionTalent)
    end
    if WuxiaGUI3._repositionSkills then
      tempTimer(0.1, WuxiaGUI3._repositionSkills)
    end
    if WuxiaGUI3._repositionAttributes then
      tempTimer(0.1, WuxiaGUI3._repositionAttributes)
    end
    if WuxiaGUI3._layoutLeftPanel then
      tempTimer(0.1, WuxiaGUI3._layoutLeftPanel)
    end
  end)
end

-- ─── Rebuild tab bar from server channel data ───
-- Shows pinned tabs + ⚙ gear button. Unread indicators on tabs.
-- Default pinned: only 全部 (always visible, cannot be removed)
-- Users pin/unpin other tabs via the pin icon.

WuxiaGUI3.pinnedTabs = WuxiaGUI3.pinnedTabs or {}
WuxiaGUI3.tempTabs = WuxiaGUI3.tempTabs or {}
WuxiaGUI3.unreadTabs = WuxiaGUI3.unreadTabs or {}
WuxiaGUI3._tabScroll = 0
WuxiaGUI3._allVisibleTabs = {}
-- Ordered list of all non-全部 tabs in the order they were added
WuxiaGUI3._tabOrder = WuxiaGUI3._tabOrder or {}

function WuxiaGUI3._rebuildTabBar()
  if not WuxiaGUI3.chatMain then return end

  WuxiaGUI3._inRebuild = true

  -- Increment sequence to get unique Geyser names
  WuxiaGUI3._tabSeq = (WuxiaGUI3._tabSeq or 0) + 1
  local seq = WuxiaGUI3._tabSeq

  -- Remove old tab buttons and scroll arrows
  if WuxiaGUI3.chatTabButtons then
    for name, btn in pairs(WuxiaGUI3.chatTabButtons) do
      btn:hide()
    end
  end
  WuxiaGUI3.chatTabButtons = {}
  if WuxiaGUI3._tabLeftBtn then WuxiaGUI3._tabLeftBtn:hide() end
  if WuxiaGUI3._tabRightBtn then WuxiaGUI3._tabRightBtn:hide() end
  if WuxiaGUI3.chatMoreBtn then WuxiaGUI3.chatMoreBtn:hide() end
  -- Clean up any drag ghost that might be lingering
  if WuxiaGUI3._dragGhost then
    WuxiaGUI3._dragGhost:hide()
    WuxiaGUI3._dragGhost = nil
  end
  WuxiaGUI3._dragActive = false
  WuxiaGUI3._dragLastGap = nil
  if WuxiaGUI3._stopDragScroll then WuxiaGUI3._stopDragScroll() end

  -- Tab bar bottom line — full width, created first so tabs render on top
  if WuxiaGUI3._tabBarLine then WuxiaGUI3._tabBarLine:hide() end
  WuxiaGUI3._tabBarLine = Geyser.Label:new({
    name = "W3.tb." .. seq .. ".line",
    x = 0, y = 0,
    width = "100%", height = 22,
  }, WuxiaGUI3.chatMain)
  WuxiaGUI3._tabBarLine:setStyleSheet(string.format([[
    background-color: %s;
    border-bottom: 1px solid %s;
  ]], BG, BORDER))

  -- Build tab list: 全部 first, then all pinned + temp in _tabOrder
  local allTabs = { "全部" }
  local addedSet = { ["全部"] = true }

  -- Collect which tabs should be visible (pinned or temp)
  local visibleSet = {}
  for _, name in ipairs(WuxiaGUI3.pinnedTabs) do visibleSet[name] = true end
  for _, name in ipairs(WuxiaGUI3.tempTabs) do visibleSet[name] = true end

  -- Add tabs in their original order
  for _, name in ipairs(WuxiaGUI3._tabOrder) do
    if visibleSet[name] and not addedSet[name] then
      allTabs[#allTabs + 1] = name
      addedSet[name] = true
    end
  end
  WuxiaGUI3._allVisibleTabs = allTabs

  -- Layout: use fixed tab width, add scroll arrows if needed
  local gearW = 28
  local arrowW = 22
  local nTabs = #allTabs
  local tabW = 64

  -- Get actual pixel width of chat area
  -- Use screen width minus right panel width for reliable measurement
  local screenW, _ = getMainWindowSize()
  local chatW = (screenW or 800) - PW - LPW
  if chatW < 200 then chatW = 600 end

  -- Check if we need scroll arrows
  local bellW = 40
  local spaceForTabs = chatW - gearW - bellW
  local needsScroll = (nTabs * tabW > spaceForTabs)
  if needsScroll then
    spaceForTabs = spaceForTabs - arrowW * 2
  end
  local maxVisible = math.max(1, math.floor(spaceForTabs / tabW))
  local maxScroll = math.max(0, nTabs - maxVisible)
  WuxiaGUI3._tabScroll = math.max(0, math.min(WuxiaGUI3._tabScroll, maxScroll))
  WuxiaGUI3._tabMaxVisible = maxVisible
  WuxiaGUI3._tabMaxScroll = maxScroll

  local xOffset = 0

  -- Left arrow ◀
  if needsScroll then
    WuxiaGUI3._tabLeftBtn = Geyser.Label:new({
      name = "W3.tb." .. seq .. ".L",
      x = 0, y = 0,
      width = arrowW, height = 22,
    }, WuxiaGUI3.chatMain)
    WuxiaGUI3._tabLeftBtn:setStyleSheet(string.format([[
      background-color: %s;
      border-bottom: 1px solid %s;
      qproperty-alignment: AlignCenter;
    ]], BG, BORDER))
    WuxiaGUI3._tabLeftBtn:setFontSize(9)
    local lColor = WuxiaGUI3._tabScroll > 0 and GOLD or TEXT_DIM
    WuxiaGUI3._tabLeftBtn:echo(span(lColor, "◀"))
    WuxiaGUI3._tabLeftBtn:setClickCallback("WuxiaGUI3._tabScrollLeft")
    WuxiaGUI3._tabLeftBtn:setWheelCallback("WuxiaGUI3._onTabWheel")
    xOffset = arrowW
  end

  -- Create visible tab buttons
  WuxiaGUI3._tabPinBtns = WuxiaGUI3._tabPinBtns or {}
  for _, pb in pairs(WuxiaGUI3._tabPinBtns) do pb:hide() end
  WuxiaGUI3._tabPinBtns = {}

  for vi = 1, maxVisible do
    local idx = WuxiaGUI3._tabScroll + vi
    local name = allTabs[idx]
    if not name then break end

    local tabX = xOffset + (vi - 1) * tabW
    local pinW = (name ~= "全部") and 16 or 0
    local btnW = tabW - pinW

    local btn = Geyser.Label:new({
      name = "W3.tb." .. seq .. "." .. name,
      x = tabX, y = 0,
      width = btnW, height = 22,
    }, WuxiaGUI3.chatMain)
    btn:setFontSize(9)
    btn:setClickCallback("WuxiaGUI3._onTabMouseDown", name)
    btn:setMoveCallback("WuxiaGUI3._onTabMouseMove", name)
    btn:setReleaseCallback("WuxiaGUI3._onTabMouseUp", name)
    btn:setOnEnter("WuxiaGUI3._onTabHoverEnter", name)
    btn:setWheelCallback("WuxiaGUI3._onTabWheel")
    WuxiaGUI3.chatTabButtons[name] = btn

    -- Store tab pixel position for drop-target calculation
    WuxiaGUI3._tabPositions = WuxiaGUI3._tabPositions or {}
    WuxiaGUI3._tabPositions[name] = {
      x = tabX, vi = vi, idx = idx,
    }

    -- Pin toggle icon for non-全部 tabs
    if name ~= "全部" then
      local isPinned = WuxiaGUI3._isTabPinned(name)

      local iconBtn = Geyser.Label:new({
        name = "W3.tb." .. seq .. ".pin." .. name,
        x = tabX + btnW, y = 0,
        width = pinW, height = 22,
      }, WuxiaGUI3.chatMain)
      iconBtn:setFontSize(7)
      iconBtn:setClickCallback("WuxiaGUI3._togglePin", name)
      iconBtn:setWheelCallback("WuxiaGUI3._onTabWheel")

      if isPinned then
        iconBtn:setStyleSheet(string.format([[
          background-color: %s;
          border-bottom: 2px solid %s;
          qproperty-alignment: AlignCenter;
        ]], BG, GOLD))
        iconBtn:echo(PIN_CHAR)
      else
        iconBtn:setStyleSheet(string.format([[
          background-color: %s;
          border-bottom: 1px solid %s;
          qproperty-alignment: AlignCenter;
        ]], BG, BORDER))
        iconBtn:echo(span(TEXT_DIM, "○"))
      end
      WuxiaGUI3._tabPinBtns[name] = iconBtn
    end
  end

  local tabEndX = xOffset + math.min(maxVisible, nTabs) * tabW

  -- Store layout info for drag-and-drop
  -- Left bound: if 全部 is visible (scroll=0), can't go before it.
  -- Otherwise, start of tab area (xOffset).
  local firstIsAll = (allTabs[WuxiaGUI3._tabScroll + 1] == "全部")
  local dragMinX = firstIsAll and (xOffset + tabW) or xOffset
  local dragMaxX = tabEndX - tabW  -- rightmost position for a dragged tab
  WuxiaGUI3._dragLayout = {
    xOffset = xOffset,
    tabW = tabW,
    maxVisible = maxVisible,
    dragMinX = dragMinX,
    dragMaxX = math.max(dragMinX, dragMaxX),
    tabEndX = tabEndX,
  }

  -- Right arrow ▶
  if needsScroll then
    WuxiaGUI3._tabRightBtn = Geyser.Label:new({
      name = "W3.tb." .. seq .. ".R",
      x = tabEndX, y = 0,
      width = arrowW, height = 22,
    }, WuxiaGUI3.chatMain)
    WuxiaGUI3._tabRightBtn:setStyleSheet(string.format([[
      background-color: %s;
      border-bottom: 1px solid %s;
      qproperty-alignment: AlignCenter;
    ]], BG, BORDER))
    WuxiaGUI3._tabRightBtn:setFontSize(9)
    local rColor = WuxiaGUI3._tabScroll < maxScroll and GOLD or TEXT_DIM
    WuxiaGUI3._tabRightBtn:echo(span(rColor, "▶"))
    WuxiaGUI3._tabRightBtn:setClickCallback("WuxiaGUI3._tabScrollRight")
    WuxiaGUI3._tabRightBtn:setWheelCallback("WuxiaGUI3._onTabWheel")
    tabEndX = tabEndX + arrowW
  end

  -- Gear button
  if WuxiaGUI3.chatMoreBtn then WuxiaGUI3.chatMoreBtn:hide() end
  WuxiaGUI3.chatMoreBtn = Geyser.Label:new({
    name = "W3.tb." .. seq .. ".gear",
    x = tabEndX, y = 0,
    width = gearW, height = 22,
  }, WuxiaGUI3.chatMain)
  WuxiaGUI3.chatMoreBtn:setStyleSheet(string.format([[
    background-color: %s;
    border-bottom: 1px solid %s;
    qproperty-alignment: AlignCenter;
  ]], BG, BORDER))
  WuxiaGUI3.chatMoreBtn:setFontSize(10)
  WuxiaGUI3.chatMoreBtn:echo(span(GOLD, "⚙"))
  WuxiaGUI3.chatMoreBtn:setClickCallback("WuxiaGUI3._showChannelPanel")
  WuxiaGUI3._gearRelX = tabEndX
  WuxiaGUI3._gearRelW = gearW

  -- Bell button 🔔 (for hidden unread notifications)
  if WuxiaGUI3._bellBtn then WuxiaGUI3._bellBtn:hide() end
  WuxiaGUI3._bellBtn = Geyser.Label:new({
    name = "W3.tb." .. seq .. ".bell",
    x = tabEndX + gearW, y = 0,
    width = bellW, height = 22,
  }, WuxiaGUI3.chatMain)
  WuxiaGUI3._bellBtn:setStyleSheet(string.format([[
    background-color: %s;
    border-bottom: 1px solid %s;
    qproperty-alignment: AlignCenter;
  ]], BG, BORDER))
  WuxiaGUI3._bellBtn:setFontSize(9)
  WuxiaGUI3._bellBtn:setClickCallback("WuxiaGUI3._onBellClick")
  WuxiaGUI3._bellBtn:hide()  -- hidden by default, shown by _updateBellState

  -- Style active tab + unread indicators
  WuxiaGUI3._updateTabStates()
  WuxiaGUI3._updateBellState()

  -- Show correct console for active tab (even if tab is scrolled out of view)
  if WuxiaGUI3.chatConsoles then
    -- Check if active tab still exists as a console (pinned or temp)
    local activeExists = WuxiaGUI3.chatConsoles[WuxiaGUI3.activeChatTab]
    if not activeExists then
      -- Tab was removed entirely (e.g. temp tab closed) → switch to 全部
      WuxiaGUI3.switchChatTab("全部")
    else
      -- Just ensure correct console is visible (no tab switch needed)
      for name, con in pairs(WuxiaGUI3.chatConsoles) do
        if name == WuxiaGUI3.activeChatTab then
          con:show()
        else
          con:hide()
        end
      end
    end
  end

  WuxiaGUI3._inRebuild = false

  -- Reposition drawer if it's open (gear button may have moved)
  if WuxiaGUI3._drawerOpen and WuxiaGUI3._drawer then
    WuxiaGUI3._repositionDrawer()
    WuxiaGUI3._drawer:raise()
    if WuxiaGUI3._drawerBgLbl then WuxiaGUI3._drawerBgLbl:raise() end
    for _, cmd in ipairs(WuxiaGUI3._drawerChannelOrder or {}) do
      local btns = WuxiaGUI3._drawerBtns[cmd]
      if btns then
        btns.nameBtn:raise()
        btns.toggleBtn:raise()
      end
    end
    if WuxiaGUI3._drawerUpBtn then WuxiaGUI3._drawerUpBtn:raise() end
    if WuxiaGUI3._drawerDownBtn then WuxiaGUI3._drawerDownBtn:raise() end
  end
end

-- Tab bar scroll functions
function WuxiaGUI3._tabScrollLeft()
  WuxiaGUI3._tabScroll = math.max(0, WuxiaGUI3._tabScroll - 1)
  WuxiaGUI3._rebuildTabBar()
end

function WuxiaGUI3._tabScrollRight()
  WuxiaGUI3._tabScroll = (WuxiaGUI3._tabScroll or 0) + 1
  WuxiaGUI3._rebuildTabBar()
end

-- Auto-scroll tab bar so that the given tab is visible
function WuxiaGUI3._scrollToTab(tabName)
  local allTabs = WuxiaGUI3._allVisibleTabs
  local layout = WuxiaGUI3._dragLayout
  if not allTabs or not layout then return end

  -- Find tab's index in allTabs
  local tabIdx
  for i, name in ipairs(allTabs) do
    if name == tabName then tabIdx = i break end
  end
  if not tabIdx then return end

  local scroll = WuxiaGUI3._tabScroll or 0
  local maxVis = layout.maxVisible or 4
  local firstVis = scroll + 1
  local lastVis = scroll + maxVis

  if tabIdx < firstVis then
    -- Tab is to the left of visible range: scroll left
    WuxiaGUI3._tabScroll = tabIdx - 1
    WuxiaGUI3._rebuildTabBar()
  elseif tabIdx > lastVis then
    -- Tab is to the right of visible range: scroll right
    WuxiaGUI3._tabScroll = tabIdx - maxVis
    WuxiaGUI3._rebuildTabBar()
  end
  -- else: already visible, do nothing
end

-- Track tab insertion order (for stable positioning)
function WuxiaGUI3._ensureTabOrder(tabName)
  if tabName == "全部" then return end
  for _, t in ipairs(WuxiaGUI3._tabOrder) do
    if t == tabName then return end  -- already tracked
  end
  WuxiaGUI3._tabOrder[#WuxiaGUI3._tabOrder + 1] = tabName
end

-- Check if a tab is pinned
function WuxiaGUI3._isTabPinned(tabName)
  for _, p in ipairs(WuxiaGUI3.pinnedTabs) do
    if p == tabName then return true end
  end
  return false
end

-- Toggle pin state of a tab
function WuxiaGUI3._togglePin(tabName)
  if tabName == "全部" then return end

  if WuxiaGUI3._isTabPinned(tabName) then
    -- Unpin: remove from pinnedTabs
    for i, p in ipairs(WuxiaGUI3.pinnedTabs) do
      if p == tabName then
        table.remove(WuxiaGUI3.pinnedTabs, i)
        break
      end
    end
    -- Only keep as temp if currently viewing it; otherwise remove immediately
    if tabName == WuxiaGUI3.activeChatTab then
      local alreadyTemp = false
      for _, t in ipairs(WuxiaGUI3.tempTabs) do
        if t == tabName then alreadyTemp = true break end
      end
      if not alreadyTemp then
        WuxiaGUI3.tempTabs[#WuxiaGUI3.tempTabs + 1] = tabName
      end
    end
  else
    -- Pin: remove from tempTabs, add to pinnedTabs
    for i, t in ipairs(WuxiaGUI3.tempTabs) do
      if t == tabName then
        table.remove(WuxiaGUI3.tempTabs, i)
        break
      end
    end
    local alreadyPinned = false
    for _, p in ipairs(WuxiaGUI3.pinnedTabs) do
      if p == tabName then alreadyPinned = true break end
    end
    if not alreadyPinned then
      WuxiaGUI3.pinnedTabs[#WuxiaGUI3.pinnedTabs + 1] = tabName
      WuxiaGUI3._ensureTabOrder(tabName)
    end
  end
  WuxiaGUI3._rebuildTabBar()
  WuxiaGUI3._saveSettings()
end

-- Mouse wheel on tab bar: scroll up = left, scroll down = right
-- setWheelCallback passes event table as last arg with angleDeltaY
function WuxiaGUI3._onTabWheel(event)
  if event and event.angleDeltaY and event.angleDeltaY > 0 then
    WuxiaGUI3._tabScrollLeft()
  else
    WuxiaGUI3._tabScrollRight()
  end
end

-- ─── Tab drag-and-drop reorder (visual) ───
-- Mouse down: record drag source and start position
function WuxiaGUI3._onTabMouseDown(srcTab, event)
  local mx, my = getMousePosition()
  WuxiaGUI3._dragSrc = srcTab
  WuxiaGUI3._dragStartX = mx
  WuxiaGUI3._dragStartY = my
  WuxiaGUI3._dragActive = false
end

-- Mouse move on source tab: activate drag after threshold
function WuxiaGUI3._onTabMouseMove(srcTab, event)
  if not WuxiaGUI3._dragSrc then return end
  if WuxiaGUI3._dragSrc ~= srcTab then return end
  local mx, my = getMousePosition()
  local dx = math.abs(mx - (WuxiaGUI3._dragStartX or mx))

  if not WuxiaGUI3._dragActive and dx >= 8 then
    if WuxiaGUI3._dragSrc == "全部" then return end
    WuxiaGUI3._dragActive = true
    WuxiaGUI3._dragLastGap = nil

    -- Style source tab as "picked up" (dim with dashed border)
    local srcBtn = WuxiaGUI3.chatTabButtons[WuxiaGUI3._dragSrc]
    if srcBtn then
      srcBtn:setStyleSheet(string.format([[
        background-color: %s;
        border-bottom: 2px dashed %s;
        qproperty-alignment: AlignCenter;
      ]], BG, BORDER))
      srcBtn:echo(span(TEXT_DIM, WuxiaGUI3._dragSrc))
    end
    -- Hide pin icon of source
    local srcPin = WuxiaGUI3._tabPinBtns and WuxiaGUI3._tabPinBtns[WuxiaGUI3._dragSrc]
    if srcPin then srcPin:hide() end

    WuxiaGUI3._updateDragGap(mx)
  end

  if WuxiaGUI3._dragActive then
    -- Move source tab to follow cursor, clamped between 全部 and ⚙
    local srcBtn = WuxiaGUI3.chatTabButtons[WuxiaGUI3._dragSrc]
    local layout2 = WuxiaGUI3._dragLayout or {}
    local tabW2 = layout2.tabW or 64
    local chatX2 = WuxiaGUI3.chatMain:get_x()

    if srcBtn then
      local relMx = mx - chatX2 - tabW2 / 2
      relMx = math.max(layout2.dragMinX or tabW2, math.min(relMx, layout2.dragMaxX or 400))
      srcBtn:move(relMx, 0)
      srcBtn:raise()
    end

    -- Auto-scroll when cursor is over the scroll arrow areas (not the tab area)
    local relCursor = mx - chatX2
    local xOff = layout2.xOffset or 0
    local tEndX = layout2.tabEndX or 400
    local scrollDir = nil

    if relCursor < xOff and WuxiaGUI3._tabScroll > 0 then
      scrollDir = -1  -- over left arrow area
    elseif relCursor > tEndX and WuxiaGUI3._tabScroll < (WuxiaGUI3._tabMaxScroll or 0) then
      scrollDir = 1   -- over right arrow / gear area
    end

    if scrollDir then
      -- Start or continue auto-scroll timer
      if not WuxiaGUI3._dragScrollTimer then
        -- Do first scroll immediately
        WuxiaGUI3._tabScroll = WuxiaGUI3._tabScroll + scrollDir
        WuxiaGUI3._dragLastGap = nil
        WuxiaGUI3._dragRelayout()
        -- Then repeat every 350ms
        WuxiaGUI3._dragScrollDir = scrollDir
        WuxiaGUI3._dragScrollTimer = tempTimer(0.35, function()
          WuxiaGUI3._dragScrollTick()
        end)
      end
    else
      -- Cursor left scroll zone — stop auto-scroll
      WuxiaGUI3._stopDragScroll()
    end

    -- Use raw mouse position for gap calculation (not clamped)
    -- The button visual is clamped, but the gap should respond to actual cursor
    WuxiaGUI3._updateDragGap(mx)
  end
end

-- Hover enter on any tab: update gap position during drag
function WuxiaGUI3._onTabHoverEnter(tabName, event)
  if not WuxiaGUI3._dragActive then return end
  local mx, my = getMousePosition()
  WuxiaGUI3._updateDragGap(mx)
end

-- Drag scroll timer: scroll one step and re-arm
function WuxiaGUI3._dragScrollTick()
  WuxiaGUI3._dragScrollTimer = nil
  if not WuxiaGUI3._dragActive then return end

  local dir = WuxiaGUI3._dragScrollDir or 0
  local newScroll = WuxiaGUI3._tabScroll + dir

  if dir < 0 and newScroll < 0 then return end
  if dir > 0 and newScroll > (WuxiaGUI3._tabMaxScroll or 0) then return end

  WuxiaGUI3._tabScroll = newScroll
  WuxiaGUI3._dragLastGap = nil
  WuxiaGUI3._dragRelayout()

  -- Re-arm for continuous scrolling (accelerate slightly)
  WuxiaGUI3._dragScrollTimer = tempTimer(0.3, function()
    WuxiaGUI3._dragScrollTick()
  end)
end

-- Stop drag auto-scroll timer
function WuxiaGUI3._stopDragScroll()
  if WuxiaGUI3._dragScrollTimer then
    killTimer(WuxiaGUI3._dragScrollTimer)
    WuxiaGUI3._dragScrollTimer = nil
  end
  WuxiaGUI3._dragScrollDir = nil
end

-- Repurpose existing tab buttons for new scroll position during drag
-- No widget creation/destruction — just re-echo and remap
function WuxiaGUI3._dragRelayout()
  local layout = WuxiaGUI3._dragLayout
  if not layout then return end

  local allTabs = WuxiaGUI3._allVisibleTabs
  if not allTabs then return end
  local tabW = layout.tabW
  local dragSrc = WuxiaGUI3._dragSrc

  -- Collect all non-source button widgets into a reuse pool
  local pool = {}
  for name, btn in pairs(WuxiaGUI3.chatTabButtons) do
    if name ~= dragSrc then
      pool[#pool + 1] = { btn = btn, pin = WuxiaGUI3._tabPinBtns and WuxiaGUI3._tabPinBtns[name], oldName = name }
    end
  end

  -- Determine which tabs should be visible (excluding drag source)
  local needed = {}
  for vi = 1, layout.maxVisible do
    local idx = WuxiaGUI3._tabScroll + vi
    local name = allTabs[idx]
    if name and name ~= dragSrc then
      needed[#needed + 1] = name
    end
  end

  -- Update dragMinX based on whether 全部 is now visible
  local firstTab = allTabs[WuxiaGUI3._tabScroll + 1]
  local xOffset = layout.xOffset or 0
  if firstTab == "全部" then
    layout.dragMinX = xOffset + tabW
  else
    layout.dragMinX = xOffset
  end
  layout.dragMaxX = math.max(layout.dragMinX, (layout.tabEndX or 400) - tabW)

  -- Reassign pool buttons to needed tabs
  local newBtns = {}
  local newPins = {}
  newBtns[dragSrc] = WuxiaGUI3.chatTabButtons[dragSrc]
  if WuxiaGUI3._tabPinBtns then
    newPins[dragSrc] = WuxiaGUI3._tabPinBtns[dragSrc]
  end

  for i, name in ipairs(needed) do
    local p = pool[i]
    if p then
      local btn = p.btn
      local pinBtn = p.pin

      -- Restyle as normal tab
      local isActive = (name == WuxiaGUI3.activeChatTab)
      local hasUnread = WuxiaGUI3.unreadTabs[name]
      local bgColor = isActive and BG2 or BG
      local borderCSS = isActive and string.format("border-bottom: 2px solid %s;", GOLD)
                        or string.format("border-bottom: 1px solid %s;", BORDER)
      btn:setStyleSheet(string.format([[
        background-color: %s;
        %s
        qproperty-alignment: AlignCenter;
      ]], bgColor, borderCSS))

      -- Echo tab name with unread count
      local displayName = name
      if hasUnread and type(hasUnread) == "number" and hasUnread > 0 then
        displayName = name .. "(" .. hasUnread .. ")"
      end
      local textColor = isActive and GOLD or (hasUnread and "#ff4444" or TEXT)
      btn:echo(span(textColor, displayName))
      btn:show()

      -- Update pin
      if pinBtn and name ~= "全部" then
        local pinned = WuxiaGUI3._isTabPinned(name)
        local pinChar = pinned and "📌︎" or "○"
        pinBtn:echo(span(isActive and GOLD or TEXT_DIM, pinChar))
        pinBtn:setClickCallback("WuxiaGUI3._togglePin", name)
        pinBtn:show()
      elseif pinBtn then
        pinBtn:hide()  -- 全部 has no pin
      end

      newBtns[name] = btn
      newPins[name] = pinBtn
    end
  end

  -- Hide any excess pool buttons
  for i = #needed + 1, #pool do
    local p = pool[i]
    if p then
      p.btn:hide()
      if p.pin then p.pin:hide() end
    end
  end

  WuxiaGUI3.chatTabButtons = newBtns
  WuxiaGUI3._tabPinBtns = newPins or WuxiaGUI3._tabPinBtns
end

-- Shift visible tabs to create a gap at the insertion point
function WuxiaGUI3._updateDragGap(mx)
  local layout = WuxiaGUI3._dragLayout
  if not layout then return end

  local allTabs = WuxiaGUI3._allVisibleTabs
  if not allTabs then return end

  local chatX = WuxiaGUI3.chatMain:get_x()
  local relX = mx - chatX - layout.xOffset
  local tabW = layout.tabW

  -- Build the "others" list: visible tabs excluding drag source
  -- Also find the source's original visual slot index
  local others = {}
  local srcSlot = nil  -- 1-based slot of drag source in visible tabs
  for vi = 1, layout.maxVisible do
    local idx = WuxiaGUI3._tabScroll + vi
    local name = allTabs[idx]
    if name then
      if name == WuxiaGUI3._dragSrc then
        srcSlot = vi
      else
        others[#others + 1] = name
      end
    end
  end

  if #others == 0 then return end

  -- Adjust cursor position to account for the source's removed slot.
  -- In the original layout, cursor is at relX. But the source tab at
  -- srcSlot has been removed, so for positions past the source,
  -- we need to subtract one tab width to get the "others" position.
  local adjustedRelX = relX
  if srcSlot then
    local srcStartX = (srcSlot - 1) * tabW
    local srcEndX = srcSlot * tabW
    if relX > srcEndX then
      -- Cursor is past the source's original slot: shift left by tabW
      adjustedRelX = relX - tabW
    elseif relX > srcStartX then
      -- Cursor is over the source's original slot: collapse to boundary
      adjustedRelX = srcStartX
    end
  end

  local cursorInOthers = adjustedRelX / tabW  -- fractional position in others space

  local gapSlot = math.floor(cursorInOthers + 0.5) + 1
  gapSlot = math.max(1, math.min(gapSlot, #others + 1))

  -- Don't allow gap before 全部 if it's the first in others
  if others[1] == "全部" and gapSlot <= 1 then
    gapSlot = 2
  end

  if gapSlot == WuxiaGUI3._dragLastGap then return end
  WuxiaGUI3._dragLastGap = gapSlot

  -- Place others with a gap at gapSlot
  local slotIdx = 1
  for _, name in ipairs(others) do
    if slotIdx == gapSlot then
      slotIdx = slotIdx + 1
    end
    local newX = layout.xOffset + (slotIdx - 1) * tabW
    local btn = WuxiaGUI3.chatTabButtons[name]
    if btn then
      btn:move(newX, 0)
      btn:show()
    end
    local pinBtn = WuxiaGUI3._tabPinBtns and WuxiaGUI3._tabPinBtns[name]
    if pinBtn then
      pinBtn:move(newX + tabW - 16, 0)
      pinBtn:show()
    end
    slotIdx = slotIdx + 1
  end

  -- Source tab position is handled by _onTabMouseMove (follows cursor)
  -- Ensure source stays visible and pin stays hidden
  local srcBtn = WuxiaGUI3.chatTabButtons[WuxiaGUI3._dragSrc]
  if srcBtn then srcBtn:show() end
  local srcPin = WuxiaGUI3._tabPinBtns and WuxiaGUI3._tabPinBtns[WuxiaGUI3._dragSrc]
  if srcPin then srcPin:hide() end
end

-- Mouse up on any tab: finalize drop or cancel
function WuxiaGUI3._onTabMouseUp(srcTab, event)
  local dragSrc = WuxiaGUI3._dragSrc
  local wasActive = WuxiaGUI3._dragActive
  local lastGap = WuxiaGUI3._dragLastGap
  local startX = WuxiaGUI3._dragStartX

  WuxiaGUI3._dragSrc = nil
  WuxiaGUI3._dragActive = false
  WuxiaGUI3._dragLastGap = nil
  WuxiaGUI3._dragStartX = nil
  WuxiaGUI3._stopDragScroll()

  if not wasActive or not dragSrc then
    WuxiaGUI3.switchChatTab(srcTab)
    return
  end

  local layout = WuxiaGUI3._dragLayout
  local allTabs = WuxiaGUI3._allVisibleTabs
  if not layout or not allTabs or not lastGap then
    WuxiaGUI3._rebuildTabBar()
    return
  end

  -- Find srcOrderIdx in _tabOrder
  local srcOrderIdx
  for i, t in ipairs(WuxiaGUI3._tabOrder) do
    if t == dragSrc then srcOrderIdx = i break end
  end
  if not srcOrderIdx then
    WuxiaGUI3._rebuildTabBar()
    return
  end

  -- Build the "others" list (visible tabs excluding drag source), same as _updateDragGap
  local others = {}
  for vi = 1, layout.maxVisible do
    local idx = WuxiaGUI3._tabScroll + vi
    local name = allTabs[idx]
    if name and name ~= dragSrc then
      others[#others + 1] = name
    end
  end

  -- The gap was at slot `lastGap`. Tabs in `others` fill slots skipping the gap.
  -- So the tab just BEFORE the gap (slot lastGap-1) is others[lastGap-1],
  -- and the tab just AFTER the gap (slot lastGap+1) is others[lastGap].
  -- Insert dragSrc between those two in _tabOrder.

  local tabBefore = others[lastGap - 1]  -- nil if gap is at slot 1
  local tabAfter  = others[lastGap]      -- nil if gap is past the last tab

  -- 全部 is never in _tabOrder, so treat it as nil
  if tabBefore == "全部" then tabBefore = nil end
  if tabAfter == "全部" then tabAfter = nil end

  -- Remove dragSrc from _tabOrder first
  table.remove(WuxiaGUI3._tabOrder, srcOrderIdx)

  if not tabBefore and not tabAfter then
    -- Edge case: no other tabs in _tabOrder visible, put at start
    table.insert(WuxiaGUI3._tabOrder, 1, dragSrc)
  elseif not tabBefore then
    -- Gap is at the very start (or right after 全部): insert before tabAfter
    for i, t in ipairs(WuxiaGUI3._tabOrder) do
      if t == tabAfter then
        table.insert(WuxiaGUI3._tabOrder, i, dragSrc)
        break
      end
    end
  elseif not tabAfter then
    -- Gap is past the last tab: insert after tabBefore
    for i, t in ipairs(WuxiaGUI3._tabOrder) do
      if t == tabBefore then
        table.insert(WuxiaGUI3._tabOrder, i + 1, dragSrc)
        break
      end
    end
  else
    -- Normal: insert after tabBefore (= before tabAfter)
    for i, t in ipairs(WuxiaGUI3._tabOrder) do
      if t == tabBefore then
        table.insert(WuxiaGUI3._tabOrder, i + 1, dragSrc)
        break
      end
    end
  end

  WuxiaGUI3._rebuildTabBar()
  -- Use _inRebuild to prevent auto-close of previous tab during drop
  WuxiaGUI3._inRebuild = true
  WuxiaGUI3.switchChatTab(dragSrc)
  WuxiaGUI3._inRebuild = false
  WuxiaGUI3._saveSettings()
end

-- Mouse wheel on drawer: scroll up/down through channel list
function WuxiaGUI3._onDrawerWheel(event)
  if event and event.angleDeltaY and event.angleDeltaY > 0 then
    WuxiaGUI3._drawerScrollUp()
  else
    WuxiaGUI3._drawerScrollDown()
  end
end
function WuxiaGUI3._cmdToTab(cmd)
  local map = {
    chat    = "閒聊",
    rumor   = "謠言",
    mess    = "江湖",
    wiz     = "巫師",
    sys     = "系統",
    nch     = "監測",
    news    = "新聞",
    gwiz    = "國際",
    other   = "未知",
    ad      = "廣告",
    family  = "門派",
    party   = "幫派",
    stock   = "股票",
    auc     = "拍賣",
    combat  = "戰鬥",
    gt      = "隊伍",
    dt      = "洞天",
    war     = "戰場",
    debug   = "調試",
  }
  return map[cmd] or cmd
end

-- Map display tab name back to server command
function WuxiaGUI3._tabToCmd(tabName)
  local map = {
    ["閒聊"] = "chat",
    ["謠言"] = "rumor",
    ["江湖"] = "mess",
    ["巫師"] = "wiz",
    ["系統"] = "sys",
    ["監測"] = "nch",
    ["新聞"] = "news",
    ["國際"] = "gwiz",
    ["未知"] = "other",
    ["廣告"] = "ad",
    ["門派"] = "family",
    ["幫派"] = "party",
    ["股票"] = "stock",
    ["拍賣"] = "auc",
    ["戰鬥"] = "combat",
    ["隊伍"] = "gt",
    ["洞天"] = "dt",
    ["戰場"] = "war",
    ["調試"] = "debug",
  }
  return map[tabName]
end

-- Update tab buttons: active state, unread indicators, enabled/disabled
function WuxiaGUI3._updateTabStates()
  if not WuxiaGUI3.chatTabButtons then return end

  for tabName, btn in pairs(WuxiaGUI3.chatTabButtons) do
    local isActive = (tabName == WuxiaGUI3.activeChatTab)
    local hasUnread = WuxiaGUI3.unreadTabs[tabName]

    if tabName == "全部" then
      if isActive then
        btn:setStyleSheet(string.format([[
          background-color: %s;
          border-bottom: 2px solid %s;
          qproperty-alignment: AlignCenter;
        ]], BG2, GOLD))
        btn:echo(span(GOLD, "<b>全部</b>"))
      else
        btn:setStyleSheet(string.format([[
          background-color: %s;
          border-bottom: 1px solid %s;
          qproperty-alignment: AlignCenter;
        ]], BG, BORDER))
        btn:echo(span(GOLD_DIM, "全部"))
      end
    else
      local cmd = WuxiaGUI3._tabToCmd(tabName)
      local enabled = cmd and WuxiaGUI3.channelEnabled[cmd]
      local isPinned = WuxiaGUI3._isTabPinned(tabName)
      local pinBtn = WuxiaGUI3._tabPinBtns and WuxiaGUI3._tabPinBtns[tabName]

      if isActive then
        btn:setStyleSheet(string.format([[
          background-color: %s;
          border-bottom: 2px solid %s;
          qproperty-alignment: AlignCenter;
        ]], BG2, GOLD))
        if enabled == false then
          btn:echo(span(TEXT_DIM, "<b><s>" .. tabName .. "</s></b>"))
        else
          btn:echo(span(GOLD, "<b>" .. tabName .. "</b>"))
        end
        -- Pin icon: match active style
        if pinBtn then
          pinBtn:setStyleSheet(string.format([[
            background-color: %s;
            border-bottom: 2px solid %s;
            qproperty-alignment: AlignCenter;
          ]], BG2, GOLD))
          pinBtn:echo(isPinned and PIN_CHAR or span(TEXT_DIM, "○"))
        end
      elseif hasUnread then
        btn:setStyleSheet(string.format([[
          background-color: %s;
          border-bottom: 2px solid %s;
          qproperty-alignment: AlignCenter;
        ]], BG, GOLD))
        local countStr = ""
        if type(hasUnread) == "number" and hasUnread > 0 then
          countStr = hasUnread > 99 and "(99+)" or ("(" .. hasUnread .. ")")
        end
        btn:echo(span("#ffffff", tabName) .. span("#ff4444", countStr))
        -- Pin icon: match unread style
        if pinBtn then
          pinBtn:setStyleSheet(string.format([[
            background-color: %s;
            border-bottom: 2px solid %s;
            qproperty-alignment: AlignCenter;
          ]], BG, GOLD))
          pinBtn:echo(isPinned and PIN_CHAR or span(TEXT_DIM, "○"))
        end
      else
        btn:setStyleSheet(string.format([[
          background-color: %s;
          border-bottom: 1px solid %s;
          qproperty-alignment: AlignCenter;
        ]], BG, BORDER))
        if enabled == false then
          btn:echo(span(TEXT_DIM, "<s>" .. tabName .. "</s>"))
        else
          btn:echo(span(GOLD_DIM, tabName))
        end
        -- Pin icon: match inactive style
        if pinBtn then
          pinBtn:setStyleSheet(string.format([[
            background-color: %s;
            border-bottom: 1px solid %s;
            qproperty-alignment: AlignCenter;
          ]], BG, BORDER))
          pinBtn:echo(isPinned and PIN_CHAR or span(TEXT_DIM, "○"))
        end
      end
    end
  end
end

-- ─── Toggle a channel on/off via GMCP ───
function WuxiaGUI3.tuneChannel(channelCmd)
  if not channelCmd then return end
  sendGMCP('Chat.Channels.Tune {"channel":"' .. channelCmd .. '"}')
end

-- ─── Read-only channel check ───
local READ_ONLY_CMDS = {
  sys = true, nch = true, news = true,
  other = true, combat = true, stock = true,
}

function WuxiaGUI3._canSendToTab(tabName)
  if not tabName or tabName == "全部" then return true end
  local cmd = WuxiaGUI3._tabToCmd(tabName)
  if not cmd then return false end
  return not READ_ONLY_CMDS[cmd]
end

-- ─── Chat input handler: send message to active channel ───
function WuxiaGUI3._onChatInputEnter(text)
  if not text or text == "" then return end

  local tab = WuxiaGUI3.activeChatTab
  if not tab then return end

  local cmd
  if tab == "全部" then
    local sendTab = WuxiaGUI3._allTabSendChannel or "閒聊"
    cmd = WuxiaGUI3._tabToCmd(sendTab)
  else
    cmd = WuxiaGUI3._tabToCmd(tab)
  end

  if not cmd then return end
  WuxiaGUI3.sendToChannel(cmd, text)
end

-- ─── Update chat input state: label, enable/disable, dropdown ───
function WuxiaGUI3._updateChatInputState()
  if not WuxiaGUI3._chatInputLabel then return end

  local tab = WuxiaGUI3.activeChatTab or "全部"

  if tab == "全部" then
    -- Show channel selector button with ▼ indicator
    local sendCh = WuxiaGUI3._allTabSendChannel or "閒聊"
    WuxiaGUI3._chatInputLabel:echo(span(GOLD, sendCh .. " ▾"))
    WuxiaGUI3._chatInputLabel:setStyleSheet(string.format([[
      background-color: %s;
      border: 1px solid %s;
      qproperty-alignment: AlignCenter;
    ]], BG2, GOLD_DIM))
    WuxiaGUI3._chatInputLabel:setClickCallback("WuxiaGUI3._toggleChatChannelPicker")

    -- Show input, hide overlay
    WuxiaGUI3._chatInput:show()
    if WuxiaGUI3._chatInputOverlay then WuxiaGUI3._chatInputOverlay:hide() end
    WuxiaGUI3._chatInput:setStyleSheet(string.format([[
      background-color: %s;
      color: %s;
      border-top: none; border-left: none; border-right: none; border-bottom: 1px solid %s;
      padding-left: 60px;
    ]], BG, TEXT, BORDER))

  elseif WuxiaGUI3._canSendToTab(tab) then
    -- Sendable channel: show label + input
    WuxiaGUI3._chatInputLabel:echo(span(GOLD, tab))
    WuxiaGUI3._chatInputLabel:setStyleSheet(string.format([[
      background-color: %s;
      border: 1px solid %s;
      qproperty-alignment: AlignCenter;
    ]], BG2, BORDER))
    WuxiaGUI3._chatInputLabel:setClickCallback(function() end)

    WuxiaGUI3._chatInput:show()
    if WuxiaGUI3._chatInputOverlay then WuxiaGUI3._chatInputOverlay:hide() end
    WuxiaGUI3._chatInput:setStyleSheet(string.format([[
      background-color: %s;
      color: %s;
      border-top: none; border-left: none; border-right: none; border-bottom: 1px solid %s;
      padding-left: 60px;
    ]], BG, TEXT, BORDER))

  else
    -- Read-only channel: show label + overlay
    WuxiaGUI3._chatInputLabel:echo(span(TEXT_DIM, tab))
    WuxiaGUI3._chatInputLabel:setStyleSheet(string.format([[
      background-color: %s;
      border: 1px solid %s;
      qproperty-alignment: AlignCenter;
    ]], BG, BORDER))
    WuxiaGUI3._chatInputLabel:setClickCallback(function() end)

    WuxiaGUI3._chatInput:hide()
    if WuxiaGUI3._chatInputOverlay then
      WuxiaGUI3._chatInputOverlay:show()
      WuxiaGUI3._chatInputOverlay:raise()
    end
  end

  -- Always keep label on top
  if WuxiaGUI3._chatInputLabel then
    WuxiaGUI3._chatInputLabel:raise()
  end

  -- Close channel picker if open
  WuxiaGUI3._hideChatChannelPicker()
end

-- ─── Channel picker dropdown for 全部 tab ───
WuxiaGUI3._pickerScroll = 0

function WuxiaGUI3._getPickerChannels()
  -- Show all channels from server (or fallback), mark read-only
  local channels = {}
  if WuxiaGUI3.channelList and #WuxiaGUI3.channelList > 0 then
    for _, ch in ipairs(WuxiaGUI3.channelList) do
      if ch.cmd then
        local dispName = WuxiaGUI3._cmdToTab(ch.cmd)
        if dispName then
          channels[#channels + 1] = {
            name = dispName,
            cmd = ch.cmd,
            readOnly = READ_ONLY_CMDS[ch.cmd] or false,
          }
        end
      end
    end
  else
    for _, ch in ipairs(CHAT_CHANNELS) do
      if ch.cmd then
        channels[#channels + 1] = {
          name = ch.name,
          cmd = ch.cmd,
          readOnly = READ_ONLY_CMDS[ch.cmd] or false,
        }
      end
    end
  end
  return channels
end

function WuxiaGUI3._toggleChatChannelPicker()
  if WuxiaGUI3._chatPicker then
    WuxiaGUI3._hideChatChannelPicker()
    return
  end
  WuxiaGUI3._pickerScroll = 0
  WuxiaGUI3._buildChatChannelPicker()
end

function WuxiaGUI3._buildChatChannelPicker()
  -- Destroy previous picker widgets if any
  if WuxiaGUI3._chatPickerBtns then
    for _, item in ipairs(WuxiaGUI3._chatPickerBtns) do
      item.btn:hide()
    end
  end
  WuxiaGUI3._chatPickerBtns = nil
  WuxiaGUI3._pickerUpBtn = nil
  WuxiaGUI3._pickerDnBtn = nil
  WuxiaGUI3._chatPickerBg = nil
  if WuxiaGUI3._chatPicker then
    WuxiaGUI3._chatPicker:hide()
    WuxiaGUI3._chatPicker = nil
  end

  local sendable = WuxiaGUI3._getPickerChannels()
  if #sendable == 0 then return end

  local itemH = 20
  local pickerW = 80
  local inputH = 22
  local arrowH = 16

  -- Get actual chatMain height
  local chatMainH = WuxiaGUI3._currentChatH or WuxiaGUI3.chatMain:get_height()
  local maxPickerH = chatMainH - 24 - inputH - 4  -- between tab bar and input, with margin
  local needsScroll = (#sendable * itemH) > maxPickerH

  -- Reserve space for arrows if scrolling
  local contentH = maxPickerH
  if needsScroll then
    contentH = maxPickerH - arrowH * 2
  end
  local visibleCount = math.floor(contentH / itemH)
  visibleCount = math.min(visibleCount, #sendable)
  local pickerH = visibleCount * itemH + (needsScroll and arrowH * 2 or 0) + 4  -- +4 for border padding

  -- Clamp scroll
  local maxScroll = math.max(0, #sendable - visibleCount)
  WuxiaGUI3._pickerScroll = math.max(0, math.min(WuxiaGUI3._pickerScroll, maxScroll))

  local pickerY = chatMainH - inputH - pickerH

  WuxiaGUI3._chatPicker = Geyser.Container:new({
    name = "W3.chat.picker",
    x = 0, y = pickerY,
    width = pickerW, height = pickerH,
  }, WuxiaGUI3.chatMain)

  -- Picker background
  WuxiaGUI3._chatPickerBg = Geyser.Label:new({
    name = "W3.chat.picker.bg",
    x = 0, y = 0,
    width = "100%", height = "100%",
  }, WuxiaGUI3._chatPicker)
  WuxiaGUI3._chatPickerBg:setStyleSheet(string.format([[
    background-color: %s;
    border: 1px solid %s;
  ]], BG2, GOLD_DIM))
  WuxiaGUI3._chatPickerBg:setWheelCallback("WuxiaGUI3._onPickerWheel")

  WuxiaGUI3._chatPickerBtns = {}
  local yPos = 0

  -- Up arrow
  if needsScroll then
    local upBtn = Geyser.Label:new({
      name = "W3.chat.picker.up",
      x = 2, y = 2, width = pickerW - 4, height = arrowH,
    }, WuxiaGUI3._chatPicker)
    local upColor = WuxiaGUI3._pickerScroll > 0 and GOLD or TEXT_DIM
    upBtn:setStyleSheet(string.format([[
      background-color: %s;
      border-bottom: 1px solid %s;
      qproperty-alignment: AlignCenter;
    ]], BG2, BORDER))
    upBtn:setFontSize(9)
    upBtn:echo(span(upColor, "▲"))
    upBtn:setClickCallback("WuxiaGUI3._pickerScrollUp")
    upBtn:setWheelCallback("WuxiaGUI3._onPickerWheel")
    WuxiaGUI3._pickerUpBtn = upBtn
    yPos = arrowH + 2
  else
    yPos = 2
  end

  -- Channel items
  for i = 1, visibleCount do
    local idx = WuxiaGUI3._pickerScroll + i
    local entry = sendable[idx]
    if not entry then break end

    local name = entry.name
    local isReadOnly = entry.readOnly
    local isCurrent = (not isReadOnly and name == (WuxiaGUI3._allTabSendChannel or "閒聊"))
    local btn = Geyser.Label:new({
      name = "W3.chat.picker." .. i,
      x = 2, y = yPos,
      width = pickerW - 4, height = itemH,
    }, WuxiaGUI3._chatPicker)

    local normalBg, normalColor
    if isReadOnly then
      normalBg = BG
      normalColor = TEXT_DIM
    elseif isCurrent then
      normalBg = BG
      normalColor = GOLD
    else
      normalBg = BG2
      normalColor = TEXT
    end

    btn:setStyleSheet(string.format([[
      background-color: %s;
      border-bottom: 1px solid %s;
      qproperty-alignment: AlignCenter;
    ]], normalBg, BORDER))
    btn:setFontSize(9)
    btn:echo(span(normalColor, name))
    btn:setWheelCallback("WuxiaGUI3._onPickerWheel")

    if not isReadOnly then
      btn:setClickCallback("WuxiaGUI3._selectChatChannel", name)
      btn:setOnEnter("WuxiaGUI3._onPickerHoverEnter", name)
      btn:setOnLeave("WuxiaGUI3._onPickerHoverLeave", name)
    end

    WuxiaGUI3._chatPickerBtns[#WuxiaGUI3._chatPickerBtns + 1] = {
      btn = btn, name = name, isCurrent = isCurrent, readOnly = isReadOnly,
    }
    yPos = yPos + itemH
  end

  -- Down arrow
  if needsScroll then
    local dnBtn = Geyser.Label:new({
      name = "W3.chat.picker.dn",
      x = 2, y = yPos, width = pickerW - 4, height = arrowH,
    }, WuxiaGUI3._chatPicker)
    local dnColor = WuxiaGUI3._pickerScroll < maxScroll and GOLD or TEXT_DIM
    dnBtn:setStyleSheet(string.format([[
      background-color: %s;
      border-top: 1px solid %s;
      qproperty-alignment: AlignCenter;
    ]], BG2, BORDER))
    dnBtn:setFontSize(9)
    dnBtn:echo(span(dnColor, "▼"))
    dnBtn:setClickCallback("WuxiaGUI3._pickerScrollDown")
    dnBtn:setWheelCallback("WuxiaGUI3._onPickerWheel")
    WuxiaGUI3._pickerDnBtn = dnBtn
  end

  WuxiaGUI3._chatPicker:show()
  WuxiaGUI3._chatPicker:raise()
  if WuxiaGUI3._chatPickerBg then WuxiaGUI3._chatPickerBg:raise() end
  if WuxiaGUI3._pickerUpBtn then WuxiaGUI3._pickerUpBtn:raise() end
  for _, item in ipairs(WuxiaGUI3._chatPickerBtns) do
    item.btn:raise()
  end
  if WuxiaGUI3._pickerDnBtn then WuxiaGUI3._pickerDnBtn:raise() end

  -- Store for scroll calculations
  WuxiaGUI3._pickerMaxScroll = maxScroll
  WuxiaGUI3._pickerSendable = sendable
end

function WuxiaGUI3._pickerScrollUp()
  if WuxiaGUI3._pickerScroll > 0 then
    WuxiaGUI3._pickerScroll = WuxiaGUI3._pickerScroll - 1
    WuxiaGUI3._buildChatChannelPicker()
  end
end

function WuxiaGUI3._pickerScrollDown()
  local maxS = WuxiaGUI3._pickerMaxScroll or 0
  if WuxiaGUI3._pickerScroll < maxS then
    WuxiaGUI3._pickerScroll = WuxiaGUI3._pickerScroll + 1
    WuxiaGUI3._buildChatChannelPicker()
  end
end

function WuxiaGUI3._onPickerWheel(event)
  if event and event.angleDeltaY then
    if event.angleDeltaY > 0 then
      WuxiaGUI3._pickerScrollUp()
    else
      WuxiaGUI3._pickerScrollDown()
    end
  end
end

function WuxiaGUI3._onPickerHoverEnter(name)
  if not WuxiaGUI3._chatPickerBtns then return end
  for _, item in ipairs(WuxiaGUI3._chatPickerBtns) do
    if item.name == name then
      item.btn:setStyleSheet(string.format([[
        background-color: %s;
        border-bottom: 1px solid %s;
        qproperty-alignment: AlignCenter;
      ]], GOLD_DIM, BORDER))
      item.btn:echo(span(TEXT, name))
      break
    end
  end
end

function WuxiaGUI3._onPickerHoverLeave(name)
  if not WuxiaGUI3._chatPickerBtns then return end
  for _, item in ipairs(WuxiaGUI3._chatPickerBtns) do
    if item.name == name then
      local normalBg = item.isCurrent and BG or BG2
      local normalColor = item.isCurrent and GOLD or TEXT
      item.btn:setStyleSheet(string.format([[
        background-color: %s;
        border-bottom: 1px solid %s;
        qproperty-alignment: AlignCenter;
      ]], normalBg, BORDER))
      item.btn:echo(span(normalColor, name))
      break
    end
  end
end

function WuxiaGUI3._selectChatChannel(name)
  WuxiaGUI3._allTabSendChannel = name
  WuxiaGUI3._hideChatChannelPicker()
  WuxiaGUI3._updateChatInputState()
  WuxiaGUI3._saveSettings()
end

function WuxiaGUI3._hideChatChannelPicker()
  if WuxiaGUI3._chatPicker then
    WuxiaGUI3._chatPicker:hide()
    WuxiaGUI3._chatPicker = nil
    WuxiaGUI3._chatPickerBtns = nil
  end
end

-- ─── Send a message to a channel via GMCP ───
function WuxiaGUI3.sendToChannel(channelCmd, message)
  if not channelCmd or not message or message == "" then return end
  -- Escape quotes in message
  message = message:gsub('"', '\\"')
  sendGMCP('Chat.Channels.Send {"channel":"'
    .. channelCmd .. '","message":"' .. message .. '"}')
end

-- ─── Chat input routing aliases ───
function WuxiaGUI3._registerChatAlias()
  if WuxiaGUI3._chatAliasID then
    killAlias(WuxiaGUI3._chatAliasID)
    WuxiaGUI3._chatAliasID = nil
  end
  if WuxiaGUI3._chatDirectAliasID then
    killAlias(WuxiaGUI3._chatDirectAliasID)
    WuxiaGUI3._chatDirectAliasID = nil
  end
  if WuxiaGUI3._chatTuneAliasID then
    killAlias(WuxiaGUI3._chatTuneAliasID)
    WuxiaGUI3._chatTuneAliasID = nil
  end

  -- /say <message> → send to active tab's channel via GMCP
  WuxiaGUI3._chatAliasID = tempAlias(
    "^/say (.+)$",
    function()
      local msg = matches[2]
      local tab = WuxiaGUI3.activeChatTab
      local cmd = WuxiaGUI3._tabToCmd(tab)
      if cmd then
        WuxiaGUI3.sendToChannel(cmd, msg)
      else
        -- 全部 tab defaults to chat
        WuxiaGUI3.sendToChannel("chat", msg)
      end
    end
  )

  -- /ch <channel> <message> → send to specific channel via GMCP
  WuxiaGUI3._chatDirectAliasID = tempAlias(
    "^/ch (%S+) (.+)$",
    function()
      WuxiaGUI3.sendToChannel(matches[2], matches[3])
    end
  )

  -- /tune <channel> → toggle channel on/off via GMCP
  WuxiaGUI3._chatTuneAliasID = tempAlias(
    "^/tune (%S+)$",
    function()
      WuxiaGUI3.tuneChannel(matches[2])
    end
  )
end
-- ═══════════════════════════════════════════════
function WuxiaGUI3.switchTab(tabName)
  local prevTab = WuxiaGUI3.activeTab
  WuxiaGUI3.activeTab = tabName

  -- If leaving 技能 tab during animation, cancel and mark as seen
  if prevTab == "技能" and tabName ~= "技能" then
    WuxiaGUI3._killSkillAnims()
    WuxiaGUI3._pendingSkillUpgrades = nil
    WuxiaGUI3._prevSkillState = nil
    -- Re-render with final (non-animated) state
    if WuxiaGUI3._renderSkillScroll then
      WuxiaGUI3._renderSkillScroll()
    end
  end

  -- Style all tab buttons
  for name, btn in pairs(WuxiaGUI3.tabButtons) do
    if name == tabName then
      btn:setStyleSheet(string.format([[
        background-color: rgba(22,22,48,0.1);
        border-bottom: 2px solid %s;
        qproperty-alignment: AlignCenter;
      ]], GOLD))
      btn:echo(span(GOLD, "<b>"..name.."</b>"))
    else
      btn:setStyleSheet([[
        background-color: transparent;
        border-bottom: 1px solid ]] .. BORDER .. [[;
        qproperty-alignment: AlignCenter;
      ]])
      btn:echo(span(GOLD_DIM, name))
    end
  end

  -- Show/hide containers
  for name, container in pairs(WuxiaGUI3.tabContainers) do
    if name == tabName then
      container:show()
    else
      container:hide()
    end
  end

  -- Refresh the active tab content
  WuxiaGUI3.refresh()

  -- If arriving at 技能 tab with pending upgrades, refresh will detect and animate
  if tabName == "技能" and WuxiaGUI3._pendingSkillUpgrades then
    WuxiaGUI3._pendingSkillUpgrades = nil
    -- _refreshSkills() was already called by refresh() above;
    -- it will detect level-ups via _prevSkillState and start animation
  end
end

-- ═══════════════════════════════════════════════
-- § 6  Refresh — update all visible data
-- ═══════════════════════════════════════════════
function WuxiaGUI3.refresh()
  if not WuxiaGUI3.initialized then return end

  local tab = WuxiaGUI3.activeTab
  if tab == "總覽"  then WuxiaGUI3._refreshOverview() end
  if tab == "屬性"  then WuxiaGUI3._refreshAttributes() end
  if tab == "技能"  then WuxiaGUI3._refreshSkills() end
  if tab == "天賦"  then WuxiaGUI3._refreshTalents() end
  if tab == "裝備"  then WuxiaGUI3._refreshEquipment() end
end

-- ─── 總覽 refresh ───
function WuxiaGUI3._refreshOverview()
  local v = WuxiaGUI3.vitals
  local s = WuxiaGUI3.status

  -- Helper: update a gauge + its label
  local function ug(id, label, cur, max, suffix)
    local g = WuxiaGUI3[id.."Gauge"]
    local l = WuxiaGUI3[id.."Lbl"]
    if not g or not l then return end
    cur = tonumber(cur) or 0
    max = tonumber(max) or 1
    if max < 1 then max = 1 end
    local pct = cur / max
    local pctInt = math.floor(pct * 100)

    animateGauge(g, pct)

    local txt = string.format("%s %d/%d (%d%%)", label, cur, max, pctInt)
    if suffix and suffix ~= "" then txt = txt .. " " .. suffix end
    local sh = WuxiaGUI3._overviewShadow or ""
    l:echo('<div style="' .. sh .. '">' .. span(TEXT, txt) .. '</div>')
  end

  ug("jing",   "【精氣】", v.jing, v.max_jing)
  ug("qi",     "【氣血】", v.qi,   v.max_qi)
  ug("jingli", "【精力】", v.jingli, v.max_jingli,
     string.format("(+%d)", v.jiajing or 0))
  ug("neili",  "【內力】", v.neili, v.max_neili,
     string.format("(+%d)", v.jiali or 0))

  -- Food / Water
  if WuxiaGUI3.foodGauge then
    local fc, fm = v.food or 0, v.max_food or 300
    animateGeyserGauge(WuxiaGUI3.foodGauge, fc, fm)
    local sh = WuxiaGUI3._overviewShadow or ""
    WuxiaGUI3.foodLbl:echo('<div style="' .. sh .. '">' .. span(C_FOOD[1], string.format("食物 %d/%d", fc, fm)) .. '</div>')
  end
  if WuxiaGUI3.waterGauge then
    local wc, wm = v.water or 0, v.max_water or 300
    animateGeyserGauge(WuxiaGUI3.waterGauge, wc, wm)
    local sh = WuxiaGUI3._overviewShadow or ""
    WuxiaGUI3.waterLbl:echo('<div style="' .. sh .. '">' .. span(C_WATER[1], string.format("飲水 %d/%d", wc, wm)) .. '</div>')
  end

  -- Craze / Pinghe
  if WuxiaGUI3.crazeLbl then
    local sh = WuxiaGUI3._overviewShadow or ""
    local craze = tonumber(v.craze) or 0
    if craze > 0 then
      local maxc = tonumber(v.max_craze) or 1
      WuxiaGUI3.crazeLbl:echo(
        '<div style="' .. sh .. '">' .. span("#cc4444", string.format("【憤怒】%d/%d", craze, maxc)) .. '</div>')
    else
      WuxiaGUI3.crazeLbl:echo('<div style="' .. sh .. '">' .. span(TEXT_DIM, "【平和】————————————") .. '</div>')
    end
  end

  -- Experience block
  if WuxiaGUI3.expBlock then
    local sh = WuxiaGUI3._overviewShadow or ""
    WuxiaGUI3.expBlock:echo(
      '<div style="' .. sh .. '">' ..
      kv("潛能", fmtNum(v.potential)) .. "<br>" ..
      kv("體會", fmtNum(v.experience)) .. "<br>" ..
      kv("經驗", fmtNum(v.combat_exp)) ..
      '</div>'
    )
  end

  -- Identity block
  if WuxiaGUI3.identityBlock then
    local sh = WuxiaGUI3._overviewShadow or ""
    local name = s.name or ""
    local title = s.title or ""
    local lvl = s.level or 1
    local guild = s.guild or ""
    WuxiaGUI3.identityBlock:echo(
      '<div style="' .. sh .. '">' ..
      span(GOLD, "<b>" .. name .. "</b>") .. "<br>" ..
      span(TEXT_DIM, title) .. "<br>" ..
      kv("等級", lvl) .. " " .. kv("武功上限", s.wugong_level or 1) .. "<br>" ..
      kv("能力", s.ability or 0) .. " " .. kv("成就", s.achievement or 0) .. "<br>" ..
      kv("活躍", s.active or 0) ..
      '</div>'
    )
  end

  -- ─── Chat vitals bar (compact inline) ───
  WuxiaGUI3._refreshChatVitals()
end

function WuxiaGUI3._refreshChatVitals()
  if not WuxiaGUI3._chatVitalsBar then return end
  local v = WuxiaGUI3.vitals

  local function miniBar(label, cur, max, fg)
    cur = tonumber(cur) or 0
    max = tonumber(max) or 1
    if max < 1 then max = 1 end
    local pct = math.floor(cur / max * 100)
    -- Color: normal = fg, low (<30%) = warning
    local color = fg
    if pct < 30 then color = "#cc4444" end
    return string.format(
      '<span style="color:%s;">%s</span>' ..
      '<span style="color:%s;">%d</span>' ..
      '<span style="color:%s;">/%d</span>',
      TEXT_DIM, label, color, cur, TEXT_DIM, max)
  end

  local parts = {
    miniBar("精", v.jing, v.max_jing, C_JING[1]),
    miniBar("血", v.qi, v.max_qi, C_QI[1]),
    miniBar("力", v.jingli, v.max_jingli, C_JINGLI[1]),
    miniBar("內", v.neili, v.max_neili, C_NEILI[1]),
  }

  WuxiaGUI3._chatVitalsBar:echo(table.concat(parts, "  "))
end

-- ─── 屬性 refresh ───
function WuxiaGUI3._renderRadarChart()
  local label = WuxiaGUI3._attrRadarLabel
  if not label then return end

  -- ============================================================
  -- TUNING SECTION
  -- ============================================================
  -- Hexagon/polygon center within the 320x320 radar area.
  local cx = 160
  local cy = 148

  -- Perfect hexagon value: when an attribute equals this value,
  -- its vertex sits exactly at radius R from center.
  -- Values below this shrink inward proportionally.
  -- Values above this extend beyond R (no capping).
  local perfectVal = 40

  -- Radius at perfectVal (distance from center to vertex)
  local R = 97

  -- Label distance from center
  local labelR = R + 30

  -- Per-label fine-tune offsets {dx, dy}
  -- Order: 膂力(top), 悟性(upper-right), 根骨(lower-right),
  --        身法(bottom), 容貌(lower-left), 福緣(upper-left)
  local labelOffsets = {
    { dx = 0, dy = -5 },   -- 膂力 (top)
    { dx = 5, dy = 0 },    -- 悟性 (upper-right)
    { dx = 5, dy = 0 },    -- 根骨 (lower-right)
    { dx = 0, dy = 5 },    -- 身法 (bottom)
    { dx = -5, dy = 0 },   -- 容貌 (lower-left)
    { dx = -5, dy = 0 },   -- 福緣 (upper-left)
  }
  -- Per-vertex fine-tune offsets {dx, dy} for polygon points.
  -- Added ON TOP of the computed hexagon vertex position to
  -- align with the golden dots in the background image.
  -- Order: 膂力(top), 悟性(upper-right), 根骨(lower-right),
  --        身法(bottom), 容貌(lower-left), 福緣(upper-left)
  local vertexOffsets = {
    { dx = 0, dy = 5 },    -- 膂力 (top)
    { dx = 1, dy = 2 },    -- 悟性 (upper-right)
    { dx = 1, dy = -2 },   -- 根骨 (lower-right)
    { dx = 0, dy = -5 },   -- 身法 (bottom)
    { dx = -1, dy = -2 },  -- 容貌 (lower-left)
    { dx = -1, dy = 2 },   -- 福緣 (upper-left)
  }
  -- ============================================================

  local W, H = 320, 320

  local s = WuxiaGUI3.status
  local attrs = {
    { name = "膂力", val = tonumber(s.str) or 0,  angle = -90 },
    { name = "悟性", val = tonumber(s.int_) or 0, angle = -30 },
    { name = "根骨", val = tonumber(s.con) or 0,  angle = 30 },
    { name = "身法", val = tonumber(s.dex) or 0,  angle = 90 },
    { name = "容貌", val = tonumber(s.per) or 0,  angle = 150 },
    { name = "福緣", val = tonumber(s.kar) or 0,  angle = 210 },
  }

  local attrKeys = { "str", "int", "con", "dex", "per", "kar" }
  local dataPts = {}
  local labelPositions = {}
  local vertexPoints = {}  -- actual polygon vertex positions for hover zones

  for idx, a in ipairs(attrs) do
    local rad = math.rad(a.angle)
    -- ratio = val / perfectVal, no capping — can exceed 1.0
    local ratio = a.val / perfectVal
    local dr = R * ratio
    local voff = vertexOffsets[idx] or { dx = 0, dy = 0 }
    local vx = cx + dr * math.cos(rad) + voff.dx * ratio
    local vy = cy + dr * math.sin(rad) + voff.dy * ratio
    dataPts[#dataPts+1] = string.format("%.1f,%.1f", vx, vy)
    vertexPoints[#vertexPoints+1] = { x = vx, y = vy, key = attrKeys[idx] }

    local off = labelOffsets[idx] or { dx = 0, dy = 0 }
    labelPositions[#labelPositions+1] = {
      x = cx + labelR * math.cos(rad) + off.dx,
      y = cy + labelR * math.sin(rad) + off.dy,
      name = a.name, val = a.val, key = attrKeys[idx]
    }
  end

  -- SVG polygon
  local svgStr = '<svg xmlns="http://www.w3.org/2000/svg" width="' .. W .. '" height="' .. H .. '">' ..
    '<polygon points="' .. table.concat(dataPts, " ") .. '" ' ..
    'fill="#3cc850" fill-opacity="0.2" stroke="#64ff64" stroke-opacity="0.6" stroke-width="1.5"/>' ..
    '</svg>'

  local svgDataUri = "data:image/svg+xml;base64," .. _b64(svgStr)

  local polyLabel = WuxiaGUI3._attrRadarPoly
  if polyLabel then
    polyLabel:echo('<img src="' .. svgDataUri .. '" width="320" height="320">')
  end

  -- Text labels
  if not WuxiaGUI3._radarLabelWidgets then
    WuxiaGUI3._radarLabelWidgets = {}
  end
  local parent = label
  for i, lp in ipairs(labelPositions) do
    local wName = "W3.attr.rlbl" .. i
    local w = WuxiaGUI3._radarLabelWidgets[i]
    if not w then
      w = Geyser.Label:new({
        name = wName, x = 0, y = 0, width = 70, height = 30,
      }, parent)
      w:setStyleSheet("background-color:transparent;")
      w:setFontSize(9)
      WuxiaGUI3._radarLabelWidgets[i] = w
    end
    local lx = math.floor(lp.x - 35)
    local ly = math.floor(lp.y - 15)
    w:move(lx, ly)
    w:raiseAll()

    local vc = lp.val > 0 and "#55cc55" or "#777790"
    local SHADOW = "text-shadow:1px 1px 3px #000, 0 0 5px #000;"
    w:echo(string.format(
      '<div style="text-align:center;%s"><span style="color:#e8c170;font-size:12px;">%s</span><br>' ..
      '<span style="color:%s;font-size:11px;font-weight:bold;">%d</span></div>',
      SHADOW, lp.name, vc, lp.val))

    -- Invisible hover catch layer covers the full label area
    -- Prevents tooltip flickering when cursor falls between text lines
    if not WuxiaGUI3._radarHoverCatch then
      WuxiaGUI3._radarHoverCatch = {}
    end
    local hName = "W3.attr.rhov" .. i
    local hov = WuxiaGUI3._radarHoverCatch[i]
    if not hov then
      hov = Geyser.Label:new({
        name = hName, x = 0, y = 0, width = 70, height = 30,
      }, parent)
      hov:setStyleSheet("background-color:transparent;")
      WuxiaGUI3._radarHoverCatch[i] = hov
    end
    hov:move(lx, ly)
    hov:raiseAll()
    hov:setOnEnter("WuxiaGUI3._onAttrLabelEnter", lp.key)
    hov:setOnLeave("WuxiaGUI3._onAttrLabelLeave")
  end

  -- Store vertex points for highlight functions
  WuxiaGUI3._lastVertexPoints = vertexPoints

  -- Vertex hover zones (invisible 30x30 squares at each polygon vertex)
  if not WuxiaGUI3._radarVertexZones then
    WuxiaGUI3._radarVertexZones = {}
  end
  local vtxParent = label
  for i, dp in ipairs(vertexPoints) do
    local zName = "W3.attr.vtx" .. i
    local z = WuxiaGUI3._radarVertexZones[i]
    if not z then
      z = Geyser.Label:new({
        name = zName, x = 0, y = 0, width = 30, height = 30,
      }, vtxParent)
      z:setStyleSheet("background-color:transparent;")
      WuxiaGUI3._radarVertexZones[i] = z
    end
    z:move(math.floor(dp.x - 15), math.floor(dp.y - 15))
    z:raiseAll()
    z:setOnEnter("WuxiaGUI3._onAttrLabelEnter", dp.key)
    z:setOnLeave("WuxiaGUI3._onAttrLabelLeave")
  end

  label:setStyleSheet("background-color:transparent;")
  label:echo("")
end

-- ─── Attribute hover tooltip ───
-- Maps attribute key to its "故事" (story) gift key
WuxiaGUI3._attrStoryKey = {
  str = "sun",       -- gift/sun
  int = "water",     -- gift/water
  con = "lighting",  -- gift/lighting
  dex = "feng",      -- gift/feng
  per = "pergive",   -- gift/pergive
  kar = "kargive",   -- gift/kargive
}

WuxiaGUI3._attrKeyToCN = {
  str = "膂力", int = "悟性", con = "根骨",
  dex = "身法", per = "容貌", kar = "福緣",
}

function WuxiaGUI3._showAttrTooltip(attrKey)
  local s = WuxiaGUI3.status
  if not s then return end

  -- Create tooltip label if not exists (parented to main container, not radar)
  if not WuxiaGUI3._attrTooltip then
    WuxiaGUI3._attrTooltip = Geyser.Label:new({
      name = "W3.attr.tooltip",
      x = 0, y = 0, width = 200, height = 120,
    }, WuxiaGUI3._attrRadarLabel)
    WuxiaGUI3._attrTooltip:setStyleSheet([[
      background-color: rgba(10,8,16,0.92);
      border: 1px solid #8b7340;
      border-radius: 4px;
    ]])
    WuxiaGUI3._attrTooltip:setFontSize(9)
    WuxiaGUI3._attrTooltip:hide()
  end
  local tip = WuxiaGUI3._attrTooltip

  -- Get raw data from GMCP status
  local gift = s.gift or {}
  local jm   = s.jm or {}
  local ys   = s.ys or {}

  local cnName = WuxiaGUI3._attrKeyToCN[attrKey] or attrKey
  local storyKey = WuxiaGUI3._attrStoryKey[attrKey]

  local giftSub = gift[attrKey] or {}
  local succeed = tonumber(giftSub.succeed) or 0
  local fail    = tonumber(giftSub.fail) or 0
  local story   = 0
  if storyKey then
    story = tonumber(gift[storyKey]) or 0
  end
  local jmVal  = tonumber(jm[attrKey]) or 0
  local ysVal  = tonumber(ys[attrKey]) or 0

  local sKey = (attrKey == "int") and "int_" or attrKey
  local total = tonumber(s[sKey]) or 0
  local base = total - succeed - story - jmVal - ysVal

  local S = "text-shadow:1px 1px 2px #000;"
  local GOLD = "#e8c170"
  local DIM  = "#777"

  local function cv(val, color)
    local c2 = (val == 0) and DIM or color
    return string.format('<span style="color:%s;">%d</span>', c2, val)
  end

  local html = string.format(
    '<div style="padding:6px;%s">' ..
    '<div style="text-align:center;color:%s;font-size:13px;font-weight:bold;margin-bottom:3px;">%s</div>' ..
    '<table style="width:100%%;color:#ccc;font-size:10px;border-spacing:2px 1px;">' ..
    '<tr><td style="color:#999;">初始</td><td align="right">%s</td>' ..
        '<td width="12"></td>' ..
        '<td style="color:#999;">先天</td><td align="right">%s</td></tr>' ..
    '<tr><td style="color:#999;">成功</td><td align="right">%s</td>' ..
        '<td></td>' ..
        '<td style="color:#999;">失敗</td><td align="right">%s</td></tr>' ..
    '<tr><td style="color:#999;">故事</td><td align="right">%s</td>' ..
        '<td></td>' ..
        '<td style="color:#999;">經脈</td><td align="right">%s</td></tr>' ..
    '<tr><td style="color:#999;">元神</td><td align="right">%s</td>' ..
        '<td></td><td></td><td></td></tr>' ..
    '</table></div>',
    S, GOLD, cnName,
    cv(base, "#ddd"), cv(total, "#55cc55"),
    cv(succeed, "#ddd"), cv(fail, "#cc5555"),
    cv(story, "#cc88ee"), cv(jmVal, "#5599ee"),
    cv(ysVal, "#eedd55")
  )

  tip:echo(html)
  tip:show()
  tip:raiseAll()

  -- Position tooltip near mouse cursor
  local mx, my = getMousePosition()
  local radarLabel = WuxiaGUI3._attrRadarLabel
  if radarLabel and mx and my then
    -- Convert screen coords to radarLabel-relative coords
    local rx, ry = radarLabel:get_x(), radarLabel:get_y()
    local localX = mx - rx + 15
    local localY = my - ry + 15
    -- Keep within radar area
    if localX + 200 > 320 then localX = localX - 230 end
    if localX < 0 then localX = 0 end
    if localY + 120 > 320 then localY = localY - 150 end
    if localY < 0 then localY = 0 end
    tip:move(localX, localY)
  end

  -- Highlight the hovered attribute label
  WuxiaGUI3._highlightAttrLabel(attrKey)
end

function WuxiaGUI3._hideAttrTooltip()
  if WuxiaGUI3._attrTooltip then
    WuxiaGUI3._attrTooltip:hide()
  end
  WuxiaGUI3._unhighlightAttrLabels()
end

function WuxiaGUI3._highlightAttrLabel(attrKey)
  local attrOrder = { "str", "int", "con", "dex", "per", "kar" }
  local widgets = WuxiaGUI3._radarLabelWidgets
  if not widgets then return end

  -- Highlight text label
  for i, k in ipairs(attrOrder) do
    local w = widgets[i]
    if w then
      if k == attrKey then
        w:setStyleSheet("background-color:rgba(232,193,112,0.15); border:1px solid rgba(232,193,112,0.4); border-radius:3px;")
      else
        w:setStyleSheet("background-color:transparent;")
      end
    end
  end

  -- Radial glow on hovered vertex zone
  local zones = WuxiaGUI3._radarVertexZones
  if zones then
    for i, k in ipairs(attrOrder) do
      local z = zones[i]
      if z then
        if k == attrKey then
          z:setStyleSheet("background-color:transparent; border-radius:15px; border:2px solid rgba(100,255,100,0.6); background:qradialgradient(cx:0.5,cy:0.5,radius:0.5,fx:0.5,fy:0.5,stop:0 rgba(100,255,100,0.4),stop:1 rgba(100,255,100,0));")
        else
          z:setStyleSheet("background-color:transparent;")
        end
      end
    end
  end
end

function WuxiaGUI3._unhighlightAttrLabels()
  local widgets = WuxiaGUI3._radarLabelWidgets
  if not widgets then return end
  for i = 1, 6 do
    local w = widgets[i]
    if w then
      w:setStyleSheet("background-color:transparent;")
    end
  end
  local zones = WuxiaGUI3._radarVertexZones
  if zones then
    for i = 1, 6 do
      local z = zones[i]
      if z then z:setStyleSheet("background-color:transparent;") end
    end
  end
end

function WuxiaGUI3._onAttrLabelEnter(attrKey)
  WuxiaGUI3._showAttrTooltip(attrKey)
end

function WuxiaGUI3._onAttrLabelLeave()
  WuxiaGUI3._hideAttrTooltip()
end

-- ─── Level card tab system ───
function WuxiaGUI3._onLvlTabClick(tabName)
  WuxiaGUI3._lvlActiveTab = tabName
  WuxiaGUI3._refreshLvlCard()
end

function WuxiaGUI3._refreshLvlCard()
  local s = WuxiaGUI3.status
  if not s then return end
  local tab = WuxiaGUI3._lvlActiveTab or "等級"

  -- Update tab button styles
  local TAB_ACTIVE_CSS = "background-color:rgba(138,106,58,0.3); border:1px solid rgba(232,193,112,0.5); border-radius:2px; qproperty-alignment:AlignCenter;"
  local TAB_INACTIVE_CSS = "background-color:transparent; border:1px solid rgba(80,60,30,0.3); border-radius:2px; qproperty-alignment:AlignCenter;"
  for tname, btn in pairs(WuxiaGUI3._lvlTabBtns or {}) do
    if tname == tab then
      btn:setStyleSheet(TAB_ACTIVE_CSS)
      btn:echo(span(GOLD, "<b>" .. tname .. "</b>"))
    else
      btn:setStyleSheet(TAB_INACTIVE_CSS)
      btn:echo(span(TEXT_DIM, tname))
    end
  end

  local body = WuxiaGUI3.attrCard1Body
  local barFill = WuxiaGUI3._xpBarFill
  local barLbl = WuxiaGUI3._xpBarLbl
  if not body then return end

  local function kv2(l, val, c2)
    return span(TEXT_DIM, l .. " ") .. span(c2 or WHITE, tostring(val))
  end
  local S2 = "text-shadow:1px 1px 2px #000;"

  if tab == "等級" then
    local lvl = s.level or 1
    local wg = s.wugong_level or 1
    local exp = s.combat_exp or 0
    local nextExp = s.next_level or 1
    body:echo(kv2("等級", lvl) .. "  " .. kv2("武功上限", wg))

    -- Progress bar: XP to next level
    local curThresh = lvl * lvl * lvl * 10000
    local nextThresh = curThresh + nextExp
    local progInLevel = exp - curThresh
    if progInLevel < 0 then progInLevel = 0 end
    local levelRange = nextThresh - curThresh
    if levelRange < 1 then levelRange = 1 end
    local pct = math.floor(progInLevel / levelRange * 100)
    if pct > 100 then pct = 100 end
    if pct < 0 then pct = 0 end
    if barFill then
      barFill:setStyleSheet("background-color:#8b6914; border-radius:1px;")
      barFill:resize(pct .. "%", nil)
    end
    if barLbl then
      barLbl:echo(string.format(
        '<div style="text-align:center;%s">' ..
        '<span style="color:#ccc;font-size:8px;">經驗 %s  升級需 %s</span></div>',
        S2, fmtNum(exp), fmtNum(nextExp)))
    end

  elseif tab == "血脈" then
    local xm = s.xuemai_level or 0
    local xmProg = s.xuemai_progress or 100
    local pct = 100 - xmProg  -- xuemai_progress is remaining %, so done = 100 - remaining
    if pct < 0 then pct = 0 end
    if pct > 100 then pct = 100 end
    body:echo(kv2("血脈等級", xm) .. "  " .. kv2("進度", pct .. "%"))

    if barFill then
      barFill:setStyleSheet("background-color:#8b2020; border-radius:1px;")
      barFill:resize(pct .. "%", nil)
    end
    if barLbl then
      barLbl:echo(string.format(
        '<div style="text-align:center;%s">' ..
        '<span style="color:#ccc;font-size:8px;">升級進度 %d%%</span></div>',
        S2, pct))
    end

  elseif tab == "元神" then
    local ys2 = s.yuanshen_level or 0
    local ysNext = s.yuanshen_next or 0
    body:echo(kv2("元神等級", ys2) .. "  " .. kv2("升級需", fmtNum(ysNext)))

    -- Compute progress from yuanshen_next:
    -- total for next level = (lv+1)^3 * 10000
    -- yuanshen_next = total - current_exp, so progress = 1 - (next / total)
    local totalForNext = (ys2 + 1) * (ys2 + 1) * (ys2 + 1) * 10000
    local pct = 0
    if totalForNext > 0 and ysNext >= 0 then
      pct = math.floor((1 - ysNext / totalForNext) * 100)
    end
    if pct > 100 then pct = 100 end
    if pct < 0 then pct = 0 end
    if barFill then
      barFill:setStyleSheet("background-color:#8b8b14; border-radius:1px;")
      barFill:resize(pct .. "%", nil)
    end
    if barLbl then
      barLbl:echo(string.format(
        '<div style="text-align:center;%s">' ..
        '<span style="color:#ccc;font-size:8px;">升級需 %s</span></div>',
        S2, fmtNum(ysNext)))
    end
  end
end

function WuxiaGUI3._refreshAttributes()
  local s = WuxiaGUI3.status
  local v = WuxiaGUI3.vitals

  WuxiaGUI3._renderRadarChart()

  -- Card 1: 等級
  local function kv2(l, val, c)
    return span(TEXT_DIM, l .. " ") .. span(c or WHITE, tostring(val))
  end

  WuxiaGUI3._refreshLvlCard()

  -- Card 2: 點數
  if WuxiaGUI3.attrCard2Body then
    local dp = (s.death_protect or 0) == 1 and span("#55cc55", "護") or span("#cc5555", "無")
    local kp = (s.kill_protect or 0) == 1 and span("#55cc55", "護") or span("#cc5555", "無")
    WuxiaGUI3.attrCard2Body:echo(
      kv2("能力", s.ability or 0) .. "  " ..
      kv2("成就", s.achievement or 0) .. "  " ..
      kv2("活躍", s.active or 0) .. "<br>" ..
      kv2("最大加力", s.max_jiali or 0) .. "  " ..
      kv2("最大加怒", s.max_jianu or 0) .. "  " ..
      span(TEXT_DIM, "死亡") .. dp .. " " ..
      span(TEXT_DIM, "殺戮") .. kp)
  end

  -- Card 3: 上限
  if WuxiaGUI3.attrCard3Body then
    WuxiaGUI3.attrCard3Body:echo(
      kv2("精力上限", fmtNum(s.jingli_limit or 0)) .. "  " ..
      kv2("內力上限", fmtNum(s.neili_limit or 0)) .. "<br>" ..
      kv2("潛能上限", fmtNum(s.potential_limit or 0)) .. "  " ..
      kv2("體會上限", fmtNum(s.experience_limit or 0)))
  end

  WuxiaGUI3._refreshBonusStats()
end

function WuxiaGUI3._refreshBonusStats()
  local b = WuxiaGUI3.buffs
  if not b then return end
  local hasData = (b.skillmix ~= nil or b.jingmai ~= nil or b.talent ~= nil)
  if not hasData then
    if WuxiaGUI3.bonusStatsInfo then
      WuxiaGUI3.bonusStatsInfo:echo(span(TEXT_DIM, "等待資料..."))
    end
    WuxiaGUI3._bonusEntries = {}
    WuxiaGUI3._renderBonusScroll()
    return
  end

  local filter = WuxiaGUI3._buffsActiveFilter or "all"
  local lineH = WuxiaGUI3._bonusLineH or 18

  local function val(key)
    if filter == "all" then
      local sum = 0
      for _, src in ipairs({"skillmix","yuanshen","ability1","ability2","talent","jingmai","temp"}) do
        local m = b[src]
        if m then sum = sum + (m[key] or 0) end
      end
      local eq = b.equipment
      if eq then sum = sum + (eq[key] or 0) end
      return sum
    elseif filter == "ability" then
      return (b.ability1 and b.ability1[key] or 0) + (b.ability2 and b.ability2[key] or 0)
    elseif filter == "equipment" then
      -- Equipment buffs computed from inventory data
      return b.equipment and b.equipment[key] or 0
    else
      local m = b[filter]
      return m and m[key] or 0
    end
  end

  local function colorVal(v, maxV)
    if v > 0 then return span("#55cc55", tostring(v) .. "/" .. tostring(maxV)) end
    return span(TEXT_DIM, "0/" .. tostring(maxV))
  end
  local function colorPct(v, maxS)
    if v > 0 then return span("#55cc55", v .. "%/" .. maxS) end
    return span(TEXT_DIM, "0%/" .. maxS)
  end
  local function row2(l1, v1, l2, v2)
    return span(TEXT_DIM, l1 .. " ") .. v1 .. "&nbsp;&nbsp;" ..
           span(TEXT_DIM, l2 .. " ") .. v2
  end
  local function hdr(title, color)
    return span(color or GOLD, "── " .. title .. " ──")
  end

  local entries = {}
  local tileH = 22
  local tileGap = 2  -- px gap between bar rows
  local sectionGap = 6  -- px gap before section headers
  local function add(html, h) entries[#entries + 1] = { html = html, h = h or tileH } end
  local function addSpacer(h) add('', h) end

  local tileBuf = {}
  local _tileRowIdx = 0

  local function tile(label, v, maxV, isPct, color)
    local ratio = (maxV > 0) and math.min(v / maxV, 1) or 0
    local isZero = (v == 0)
    local dv
    if isPct then
      dv = v .. "%"
    else
      if v >= 1000000 then dv = string.format("%.1fM", v / 1000000)
      elseif v >= 10000 then dv = math.floor(v / 1000) .. "k"
      else dv = tostring(v) end
    end
    local dm
    if isPct then
      dm = maxV .. "%"
    else
      if maxV >= 1000000 then dm = math.floor(maxV / 1000000) .. "M"
      elseif maxV >= 10000 then dm = math.floor(maxV / 1000) .. "k"
      else dm = tostring(maxV) end
    end

    tileBuf[#tileBuf + 1] = {
      label = label, dv = dv, dm = dm,
      ratio = ratio, isZero = isZero, color = color,
    }

    if #tileBuf == 2 then
      _tileRowIdx = _tileRowIdx + 1
      local usableW = GW - 18
      local gap = 4
      local tw = math.floor((usableW - gap) / 2)
      local totalW = tw * 2 + gap
      local th = 22

      local svg = '<svg xmlns="http://www.w3.org/2000/svg" width="' .. totalW .. '" height="' .. th .. '">'

      for ti = 1, 2 do
        local t = tileBuf[ti]
        local ox = (ti - 1) * (tw + gap)

        -- Parse color
        local r2, g2, b2 = t.color:match("#(%x%x)(%x%x)(%x%x)")
        local cr = r2 and tonumber(r2, 16) or 180
        local cg = g2 and tonumber(g2, 16) or 140
        local cb = b2 and tonumber(b2, 16) or 80

        local borderC, fillOpacity, lblC, valC, valWeight
        if t.isZero then
          borderC = string.format("rgb(%d,%d,%d)", math.floor(cr*0.2), math.floor(cg*0.2), math.floor(cb*0.2))
          fillOpacity = "0"
          lblC = "#555"
          valC = "#555"
          valWeight = "normal"
        else
          borderC = t.color
          fillOpacity = "1"
          lblC = "#aaa"
          valC = "#ddd"
          valWeight = "bold"
        end

        -- Outer rounded rect (border)
        svg = svg .. '<rect x="' .. (ox + 0.5) .. '" y="0.5" width="' .. (tw - 1) .. '" height="' .. (th - 1) .. '" rx="3" ry="3" fill="#0a0806" fill-opacity="0.5" stroke="' .. borderC .. '" stroke-width="1"/>'

        -- Fill bar (gradient)
        if t.ratio > 0 then
          local fillW = math.max(2, math.floor((tw - 2) * t.ratio))
          local gradId = "g" .. _tileRowIdx .. "t" .. ti
          svg = svg .. '<defs><linearGradient id="' .. gradId .. '" x1="0" y1="0" x2="1" y2="0">'
          svg = svg .. '<stop offset="0%" stop-color="' .. t.color .. '" stop-opacity="0.08"/>'
          svg = svg .. '<stop offset="100%" stop-color="' .. t.color .. '" stop-opacity="0.35"/>'
          svg = svg .. '</linearGradient></defs>'
          svg = svg .. '<rect x="' .. (ox + 1) .. '" y="1" width="' .. fillW .. '" height="' .. (th - 2) .. '" rx="2" ry="2" fill="url(#' .. gradId .. ')" opacity="' .. fillOpacity .. '"/>'
        end

      end

      svg = svg .. '</svg>'

      local svgData = "data:image/svg+xml;base64," .. _b64(svg)

      -- SVG bar as inline <img>, then text table with negative margin to overlap
      local hp = {}
      local padT = math.floor((th - 12) / 2)
      hp[#hp+1] = '<div style="height:' .. th .. 'px; overflow:hidden;">'
      hp[#hp+1] = '<img src="' .. svgData .. '" width="' .. totalW .. '" height="' .. th .. '">'
      hp[#hp+1] = '<table width="' .. totalW .. '" height="' .. th .. '" cellspacing="0" cellpadding="0" style="margin-top:-' .. th .. 'px;"><tr>'
      for ti2 = 1, 2 do
        local t2 = tileBuf[ti2]
        local lC = t2.isZero and "#555" or "#aaa"
        local vC = t2.isZero and "#555" or "#ddd"
        local vW = t2.isZero and "normal" or "bold"
        local valText2 = t2.dv .. "/" .. t2.dm
        if ti2 == 2 then hp[#hp+1] = '<td width="' .. gap .. '"></td>' end
        hp[#hp+1] = '<td width="' .. tw .. '"><table width="' .. tw .. '" cellspacing="0" cellpadding="0"><tr>'
        hp[#hp+1] = '<td style="padding-left:5px; padding-top:' .. padT .. 'px; font-size:9px; color:' .. lC .. '; text-shadow:1px 1px 2px #000;">' .. t2.label .. '</td>'
        hp[#hp+1] = '<td align="right" style="padding-right:5px; padding-top:' .. padT .. 'px; font-size:9px; font-weight:' .. vW .. '; color:' .. vC .. '; text-shadow:1px 1px 2px #000; white-space:nowrap;">' .. valText2 .. '</td>'
        hp[#hp+1] = '</tr></table></td>'
      end
      hp[#hp+1] = '</tr></table></div>'
      add(table.concat(hp), tileH)
      addSpacer(tileGap)
      tileBuf = {}
    end
  end

  local function flushTiles()
    if #tileBuf == 1 then
      _tileRowIdx = _tileRowIdx + 1
      local tw = math.floor((GW - 18 - 4) / 2)
      local th = 22
      local t = tileBuf[1]

      local r2, g2, b2 = t.color:match("#(%x%x)(%x%x)(%x%x)")
      local cr = r2 and tonumber(r2, 16) or 180
      local cg = g2 and tonumber(g2, 16) or 180
      local cb = b2 and tonumber(b2, 16) or 80

      local borderC, fillOpacity, lblC, valC, valWeight
      if t.isZero then
        borderC = string.format("rgb(%d,%d,%d)", math.floor(cr*0.2), math.floor(cg*0.2), math.floor(cb*0.2))
        fillOpacity = "0"
        lblC = "#555"
        valC = "#555"
        valWeight = "normal"
      else
        borderC = t.color
        fillOpacity = "1"
        lblC = "#aaa"
        valC = "#ddd"
        valWeight = "bold"
      end

      local svg = '<svg xmlns="http://www.w3.org/2000/svg" width="' .. tw .. '" height="' .. th .. '">'
      svg = svg .. '<rect x="0.5" y="0.5" width="' .. (tw - 1) .. '" height="' .. (th - 1) .. '" rx="3" ry="3" fill="#0a0806" fill-opacity="0.5" stroke="' .. borderC .. '" stroke-width="1"/>'

      if t.ratio > 0 then
        local fillW = math.max(2, math.floor((tw - 2) * t.ratio))
        local gradId = "g" .. _tileRowIdx .. "t1"
        svg = svg .. '<defs><linearGradient id="' .. gradId .. '" x1="0" y1="0" x2="1" y2="0">'
        svg = svg .. '<stop offset="0%" stop-color="' .. t.color .. '" stop-opacity="0.08"/>'
        svg = svg .. '<stop offset="100%" stop-color="' .. t.color .. '" stop-opacity="0.35"/>'
        svg = svg .. '</linearGradient></defs>'
        svg = svg .. '<rect x="1" y="1" width="' .. fillW .. '" height="' .. (th - 2) .. '" rx="2" ry="2" fill="url(#' .. gradId .. ')" opacity="' .. fillOpacity .. '"/>'
      end

      svg = svg .. '</svg>'

      local svgData = "data:image/svg+xml;base64," .. _b64(svg)

      local valText = t.dv .. "/" .. t.dm
      local padT = math.floor((th - 12) / 2)
      local hp = {}
      hp[#hp+1] = '<div style="height:' .. th .. 'px; overflow:hidden;">'
      hp[#hp+1] = '<img src="' .. svgData .. '" width="' .. tw .. '" height="' .. th .. '">'
      hp[#hp+1] = '<table width="' .. tw .. '" height="' .. th .. '" cellspacing="0" cellpadding="0" style="margin-top:-' .. th .. 'px;"><tr>'
      hp[#hp+1] = '<td width="' .. tw .. '"><table width="' .. tw .. '" cellspacing="0" cellpadding="0"><tr>'
      hp[#hp+1] = '<td style="padding-left:5px; padding-top:' .. padT .. 'px; font-size:9px; color:' .. lblC .. '; text-shadow:1px 1px 2px #000;">' .. t.label .. '</td>'
      hp[#hp+1] = '<td align="right" style="padding-right:5px; padding-top:' .. padT .. 'px; font-size:9px; font-weight:' .. valWeight .. '; color:' .. valC .. '; text-shadow:1px 1px 2px #000; white-space:nowrap;">' .. valText .. '</td>'
      hp[#hp+1] = '</tr></table></td>'
      hp[#hp+1] = '</tr></table></div>'
      add(table.concat(hp), tileH)
      addSpacer(tileGap)
      tileBuf = {}
    end
  end

  local function catHdr(title, color2)
    flushTiles()
    local c2 = color2 or GOLD
    addSpacer(sectionGap)
    add('<div style="color:' .. c2 .. '; font-size:10px; font-weight:bold; ' ..
      'text-shadow:1px 1px 2px #000; border-bottom:1px solid ' .. c2 .. '30; ' ..
      'padding-bottom:1px;">── ' .. title .. ' ──</div>', 16)
  end

  -- ── 天賦加成 ──
  catHdr("天賦加成")
  tile("臂力附加", val("str"), 2000, false, "#e8c170")
  tile("悟性附加", val("int"), 2000, false, "#e8c170")
  tile("根骨附加", val("con"), 2000, false, "#e8c170")
  tile("身法附加", val("dex"), 2000, false, "#e8c170")
  flushTiles()

  catHdr("上限加成")
  tile("潛能上限", val("max_potential"), 10000000, false, "#e8c170")
  tile("體會上限", val("max_experience"), 10000000, false, "#e8c170")
  tile("內力上限", val("max_neili"), 2000000, false, "#e8c170")
  tile("精力上限", val("max_jingli"), 1000000, false, "#e8c170")
  tile("氣血上限", val("max_qi"), 2000000, false, "#e8c170")
  tile("精氣上限", val("max_jing"), 1000000, false, "#e8c170")
  flushTiles()

  catHdr("練功加成")
  tile("研究次數", val("research_times"), 2000, false, "#e8c170")
  tile("研究效果", val("research_effect"), 2000, true, "#e8c170")
  tile("練習次數", val("practice_times"), 2000, false, "#e8c170")
  tile("練習效果", val("practice_effect"), 2000, true, "#e8c170")
  tile("學習次數", val("learn_times"), 2000, false, "#e8c170")
  tile("學習效果", val("learn_effect"), 2000, true, "#e8c170")
  tile("汲取消耗", val("derive_times"), 2000, false, "#e8c170")
  tile("汲取效果", val("derive_effect"), 2000, true, "#e8c170")
  flushTiles()

  catHdr("五行加成", "#cc4444")
  for _, e in ipairs({
    {"毒傷害","add_poison","抗毒","reduce_poison"},
    {"魔傷害","add_magic","抗魔","reduce_magic"},
    {"金傷害","add_metal","抗金","reduce_metal"},
    {"木傷害","add_wood","抗木","reduce_wood"},
    {"水傷害","add_water","抗水","reduce_water"},
    {"火傷害","add_fire","抗火","reduce_fire"},
    {"土傷害","add_earth","抗土","reduce_earth"},
  }) do
    tile(e[1], val(e[2]), 100, true, "#cc4444")
    tile(e[3], val(e[4]), 100, true, "#cc4444")
  end
  flushTiles()

  catHdr("狀態恢復", "#5588cc")
  tile("偷取內力", val("leech_neili"), 90, true, "#5588cc")
  tile("偷取生命", val("leech_qi"), 90, true, "#5588cc")
  flushTiles()

  catHdr("戰鬥加成")
  tile("攻擊等級", val("attack"), 9000, false, "#e8c170")
  tile("防禦等級", val("defense"), 9000, false, "#e8c170")
  tile("躲閃等級", val("dodge"), 9000, false, "#e8c170")
  tile("招架等級", val("parry"), 9000, false, "#e8c170")
  tile("絕招命中", val("ap_power"), 120, true, "#e8c170")
  tile("絕招防禦", val("dp_power"), 120, true, "#e8c170")
  tile("兵器傷害", val("damage"), 200000, false, "#e8c170")
  tile("空手傷害", val("unarmed_damage"), 200000, false, "#e8c170")
  tile("絕招傷害", val("da_power"), 120, true, "#e8c170")
  tile("戰鬥保護", val("armor"), 200000, false, "#e8c170")
  tile("忽視招架", val("avoid_parry"), 90, true, "#e8c170")
  tile("忽視躲閃", val("avoid_dodge"), 90, true, "#e8c170")
  tile("忽視特攻", val("avoid_attack"), 90, true, "#e8c170")
  tile("忽視內防", val("avoid_force"), 90, true, "#e8c170")
  flushTiles()

  catHdr("高級屬性", "#aa55cc")
  tile("化解忙亂", val("reduce_busy"), 90, false, "#aa55cc")
  tile("尋寶率", val("magic_find"), 300, true, "#aa55cc")
  tile("雙倍傷害", val("double_damage"), 200, true, "#aa55cc")
  tile("傷轉內力", val("qi_abs_neili"), 90, true, "#aa55cc")
  tile("致盲", val("add_blind"), 90, true, "#aa55cc")
  tile("忽視致盲", val("avoid_blind"), 90, true, "#aa55cc")
  tile("穿透破甲", val("through_armor"), 90, true, "#aa55cc")
  tile("百毒不侵", val("avoid_poison"), 100, true, "#aa55cc")
  tile("戰神附體", val("full_self"), 90, true, "#aa55cc")
  flushTiles()

  catHdr("終極屬性", "#ccaa33")
  tile("冰凍", val("add_freeze"), 90, true, "#ccaa33")
  tile("忽視冰凍", val("avoid_freeze"), 90, true, "#ccaa33")
  tile("遺忘", val("add_forget"), 90, true, "#ccaa33")
  tile("忽視遺忘", val("avoid_forget"), 90, true, "#ccaa33")
  tile("忙亂", val("add_busy"), 90, false, "#ccaa33")
  tile("忽視忙亂", val("avoid_busy"), 90, true, "#ccaa33")
  tile("虛弱", val("add_weak"), 90, true, "#ccaa33")
  tile("忽視虛弱", val("avoid_weak"), 90, true, "#ccaa33")
  tile("追加傷害", val("add_damage"), 200, true, "#ccaa33")
  tile("化解傷害", val("reduce_damage"), 90, true, "#ccaa33")
  tile("傷害反噬", val("counter_damage"), 90, true, "#ccaa33")
  tile("浴血重生", val("avoid_die"), 90, true, "#ccaa33")
  tile("致命一擊", val("fatal_blow"), 90, true, "#ccaa33")
  tile("提升技能", val("add_skill"), 1200, false, "#ccaa33")
  flushTiles()

  WuxiaGUI3._bonusEntries = entries
  WuxiaGUI3._bonusRenderedHash = nil  -- force re-render on reload

  if WuxiaGUI3.bonusStatsInfo then
    WuxiaGUI3.bonusStatsInfo:echo("")
  end

  WuxiaGUI3._renderBonusScroll()
end

function WuxiaGUI3._renderBonusScroll()
  -- Only create/render inner label when 屬性 tab is active to avoid z-order issues
  if WuxiaGUI3.activeTab ~= "屬性" then
    WuxiaGUI3._bonusRenderedHash = nil  -- force re-render when tab becomes active
    return
  end
  local entries = WuxiaGUI3._bonusEntries or {}
  local label = WuxiaGUI3._bonusListLabel
  if not label then return end
  local track = WuxiaGUI3._bonusSbTrack
  local thumb = WuxiaGUI3._bonusSbThumb

  if #entries == 0 then
    label:echo(span(TEXT_DIM, "等待資料..."))
    if track then track:hide() end
    return
  end

  local labelH = label:get_height()
  if labelH <= 0 then labelH = 300 end
  local labelW = label:get_width()
  local contentH = 0
  for _, e in ipairs(entries) do contentH = contentH + e.h end
  local maxPx = math.max(0, contentH - labelH)
  WuxiaGUI3._bonusScrollPx = math.max(0, math.min(WuxiaGUI3._bonusScrollPx or 0, maxPx))
  local scrollPx = WuxiaGUI3._bonusScrollPx

  -- Create Geyser inner label as child of bonusList (Qt clips at parent boundary)
  if not WuxiaGUI3._bonusInnerLabel then
    WuxiaGUI3._bonusInnerLabel = Geyser.Label:new({
      name = "W3.attr.bonusInner",
      x = MX, y = 0, width = GW, height = contentH,
    }, label)
    WuxiaGUI3._bonusInnerLabel:setStyleSheet("background-color:transparent; qproperty-alignment: 'AlignLeft | AlignTop';")
    WuxiaGUI3._bonusInnerLabel:setFontSize(9)

    -- Wheel callback on inner label
    WuxiaGUI3._bonusInnerLabel:setWheelCallback(function(event)
      if not event then return end
      local delta = event.angleDeltaY or 0
      local step = 8
      local lH = label:get_height()
      if lH <= 0 then lH = 200 end
      local cH = 0
      for _, e2 in ipairs(WuxiaGUI3._bonusEntries or {}) do cH = cH + e2.h end
      local mPx = math.max(0, cH - lH)
      if delta > 0 then
        WuxiaGUI3._bonusScrollPx = math.max(0, (WuxiaGUI3._bonusScrollPx or 0) - step)
      elseif delta < 0 then
        WuxiaGUI3._bonusScrollPx = math.min(mPx, (WuxiaGUI3._bonusScrollPx or 0) + step)
      end
      WuxiaGUI3._renderBonusScroll()
    end)

    label:echo("")

    -- Re-raise elements that should be above the bonus scroll area (z-order)
    local raiseList = WuxiaGUI3._bonusRaiseList or {}
    for _, elem in ipairs(raiseList) do
      if elem and elem.raiseAll then elem:raiseAll() end
    end
    -- Re-raise header area (bg, title, tab buttons — they're in main, not the tab container)
    if WuxiaGUI3.headerBg then WuxiaGUI3.headerBg:raiseAll() end
    if WuxiaGUI3.titleLbl then WuxiaGUI3.titleLbl:raiseAll() end
    for _, btn in pairs(WuxiaGUI3.tabButtons or {}) do
      if btn and btn.raiseAll then btn:raiseAll() end
    end
    for _, btn in pairs(WuxiaGUI3._buffsFilterBtns or {}) do
      if btn and btn.raiseAll then btn:raiseAll() end
    end
  end

  local inner = WuxiaGUI3._bonusInnerLabel

  -- Scroll by moving inner label within parent
  inner:move(MX, -labelH - scrollPx)
  inner:resize(GW, contentH)

  -- Re-echo if entries changed
  if WuxiaGUI3._bonusRenderedHash ~= #entries then
    local allLines = {}
    allLines[#allLines + 1] = '<table cellspacing="0" cellpadding="0" width="100%" style="font-size:9px; text-shadow:1px 1px 2px #000;">'
    for _, e in ipairs(entries) do
      allLines[#allLines + 1] = '<tr><td height="' .. e.h .. '">' .. e.html .. '</td></tr>'
    end
    allLines[#allLines + 1] = '</table>'
    inner:echo(table.concat(allLines, ""))
    WuxiaGUI3._bonusRenderedHash = #entries
  end

  -- Scrollbar
  if not track then return end
  if contentH <= labelH then
    track:hide()
  else
    track:show()
    local trackH = track:get_height()
    if trackH <= 0 then trackH = 200 end
    local tH = math.max(16, math.floor(trackH * labelH / contentH))
    local tY = maxPx > 0 and math.floor((trackH - tH) * scrollPx / maxPx) or 0
    thumb:resize(nil, tH)
    thumb:move(0, tY)
    WuxiaGUI3._bonusSbThumbRelY = tY
    WuxiaGUI3._bonusSbThumbRelH = tH
  end
end

function WuxiaGUI3._refreshSkills()
  local sd = WuxiaGUI3.skillData
  if not sd or not sd.skills then return end

  local skills     = sd.skills or {}
  local learned    = sd.learned or {}
  local skillMap   = sd.skill_map or {}
  local skillPrep  = sd.skill_prepare or {}
  local wprepare   = sd.wprepare or {}
  local computed   = sd.computed or {}
  local filter     = WuxiaGUI3._skillsActiveFilter or "all"
  local SHADOW     = WuxiaGUI3._skillSHADOW or ""
  local CX         = WuxiaGUI3._skillCX or 40
  local CW         = WuxiaGUI3._skillCW or 240

  -- Reverse maps
  local enabledAs = {}
  for slot, skId in pairs(skillMap) do
    if not enabledAs[skId] then enabledAs[skId] = {} end
    enabledAs[skId][#enabledAs[skId]+1] = slot
  end
  local preparedAs = {}
  for slot, skId in pairs(skillPrep) do
    if not preparedAs[skId] then preparedAs[skId] = {} end
    preparedAs[skId][#preparedAs[skId]+1] = slot
  end

  -- Summary
  local skillCount = 0
  for _ in pairs(skills) do skillCount = skillCount + 1 end
  if WuxiaGUI3._skillSummaryLbl then
    WuxiaGUI3._skillSummaryLbl:echo(
      '<div style="'..SHADOW..'">' ..
      span(GOLD, "技能總覽 ") ..
      span(TEXT, "共 ") .. span("#55ffff", tostring(skillCount)) ..
      span(TEXT, " 項技能") .. '</div>')
  end

  -- ═══ Enable boxes ═══
  local container = WuxiaGUI3._skillEnableContainer
  if container then
    -- Destroy old child widgets
    for _, box in pairs(WuxiaGUI3._skillEnableBoxes or {}) do
      if box.lbl then box.lbl:hide() end
      if box.hdr then box.hdr:hide() end
    end
    WuxiaGUI3._skillEnableBoxes = {}

    -- Collect slots where character has the basic skill
    local availableSlots = {}
    local allSlotNames = {
      "force","parry","dodge","cuff","finger","staff","sword","blade",
      "unarmed","strike","claw","hand","whip","spear","hammer","club",
      "dagger","axe","throwing","shooting","magic","medical","poison",
      "cooking","array","taoism","leg",
      "chuixiao-jifa","guzheng-jifa","tanqin-jifa",
    }
    for _, slot in ipairs(allSlotNames) do
      if skills[slot] and tonumber(skills[slot]) > 0 then
        availableSlots[#availableSlots+1] = slot
      end
    end

    -- Layout: 2 columns
    local boxW = math.floor(CW / 2) - 2
    local boxH = 46
    local gap = 2
    local bx, by = 0, 0
    local col = 0

    for _, slot in ipairs(availableSlots) do
      local slotName = WuxiaGUI3._enableTypeNames[slot] or slot
      local currentSpecial = skillMap[slot]
      local specName, eff = "", 0
      if currentSpecial then
        specName = (computed[currentSpecial] and computed[currentSpecial].name) or currentSpecial
        eff = WuxiaGUI3._computeEffective(slot)
      end

      local boxLbl = Geyser.Label:new({
        name = "W3.enBox."..slot,
        x = bx, y = by, width = boxW, height = boxH,
      }, container)

      if currentSpecial then
        boxLbl:setStyleSheet(
          "background-color:rgba(17,17,28,160); border:1px solid "..GOLD.."; border-radius:3px; "..
          "padding:14px 4px 2px 4px; qproperty-alignment:'AlignHCenter|AlignVCenter';")
        boxLbl:echo('<div style="font-size:9pt; '..SHADOW..'">' ..
          '<span style="color:#ddd;">'..specName..'</span>' ..
          '<br><span style="color:#55ff55; font-size:8pt;">有效 '..tostring(eff)..'</span></div>')
      else
        boxLbl:setStyleSheet(
          "background-color:rgba(17,17,28,100); border:1px solid "..BORDER.."; border-radius:3px; "..
          "padding:14px 4px 2px 4px; qproperty-alignment:'AlignHCenter|AlignVCenter';")
        boxLbl:echo('<span style="color:#555; '..SHADOW..'">空</span>')
      end
      boxLbl:raiseAll()

      -- Click debug
      local slotKey, slotLabel = slot, slotName
      boxLbl:setClickCallback(function()
        debugc("WuxiaGUI3: [Enable Click] slot=" .. slotKey .. " (" .. slotLabel .. ")")
      end)

      -- Header strip
      local hdrLbl = Geyser.Label:new({
        name = "W3.enBox."..slot..".hdr",
        x = bx + 1, y = by + 1, width = boxW - 2, height = 13,
      }, container)
      hdrLbl:setStyleSheet(
        "background-color:rgba(8,6,4,140); "..
        "border-bottom:1px solid rgba(80,60,30,80); "..
        "padding:0px 3px; qproperty-alignment:'AlignLeft|AlignVCenter';")
      hdrLbl:setFontSize(7)
      hdrLbl:echo('<span style="color:#999; font-size:8pt; '..SHADOW..'">'..slotName..'</span>')
      hdrLbl:raiseAll()

      WuxiaGUI3._skillEnableBoxes[slot] = { lbl=boxLbl, hdr=hdrLbl }

      col = col + 1
      if col >= 2 then col = 0; bx = 0; by = by + boxH + gap
      else bx = boxW + gap * 2 end
    end

    -- Resize container to fit all rows
    local totalRows = math.ceil(#availableSlots / 2)
    local enableH = totalRows * (boxH + gap)
    if enableH < 10 then enableH = 10 end
    container:resize(nil, enableH)
  end

  -- ═══ Prepare boxes ═══
  local prepCont = WuxiaGUI3._skillPrepContainer
  if prepCont then
    for _, box in pairs(WuxiaGUI3._skillPrepBoxes or {}) do
      if box.lbl then box.lbl:hide() end
      if box.hdr then box.hdr:hide() end
    end
    WuxiaGUI3._skillPrepBoxes = {}

    local boxW = math.floor(CW / 2) - 2
    local boxH = 46
    local gap = 2
    local bx, by = 0, 0
    local col = 0
    local prepCount = 0

    local prepSlots = {}
    for slot, _ in pairs(skillPrep) do prepSlots[#prepSlots+1] = slot end
    table.sort(prepSlots)

    for _, slot in ipairs(prepSlots) do
      local slotName = WuxiaGUI3._enableTypeNames[slot] or slot
      local skId = skillPrep[slot]
      local skName = (computed[skId] and computed[skId].name) or skId

      local boxLbl = Geyser.Label:new({
        name = "W3.prepBox."..slot,
        x = bx, y = by, width = boxW, height = boxH,
      }, prepCont)
      boxLbl:setStyleSheet(
        "background-color:rgba(17,17,28,160); border:1px solid #8888aa; border-radius:3px; "..
        "padding:14px 4px 2px 4px; qproperty-alignment:'AlignHCenter|AlignVCenter';")
      boxLbl:echo('<div style="font-size:9pt; '..SHADOW..'">' ..
        '<span style="color:#ccccdd;">'..skName..'</span></div>')
      boxLbl:raiseAll()

      local hdrLbl = Geyser.Label:new({
        name = "W3.prepBox."..slot..".hdr",
        x = bx + 1, y = by + 1, width = boxW - 2, height = 13,
      }, prepCont)
      hdrLbl:setStyleSheet(
        "background-color:rgba(8,6,4,140); "..
        "border-bottom:1px solid rgba(80,60,30,80); "..
        "padding:0px 3px; qproperty-alignment:'AlignLeft|AlignVCenter';")
      hdrLbl:setFontSize(7)
      hdrLbl:echo('<span style="color:#999; font-size:8pt; '..SHADOW..'">'..slotName..'</span>')
      hdrLbl:raiseAll()

      WuxiaGUI3._skillPrepBoxes[slot] = { lbl=boxLbl, hdr=hdrLbl }

      prepCount = prepCount + 1
      col = col + 1
      if col >= 2 then col = 0; bx = 0; by = by + boxH + gap
      else bx = boxW + gap * 2 end
    end

    local totalRows = math.ceil(prepCount / 2)
    local prepH = totalRows * (boxH + gap)
    if prepH < 10 then prepH = 10 end
    prepCont:resize(nil, prepH)

    -- Show/hide prepare section based on whether there are prepared skills
    if prepCount == 0 then
      WuxiaGUI3._skillPrepHdr:hide()
      prepCont:hide()
      WuxiaGUI3._skillPrepVisible = false
    else
      WuxiaGUI3._skillPrepHdr:show()
      prepCont:show()
      WuxiaGUI3._skillPrepVisible = true
    end
  end

  -- ═══ Reflow layout after enable/prepare resize ═══
  if WuxiaGUI3._reflowSkillLayout then
    WuxiaGUI3._reflowSkillLayout()
  end

  -- ═══ Filtered skill list (card-based) ═══
  local skillList = {}
  for skId, rawLvl in pairs(skills) do
    local comp = computed[skId] or {}
    local skType = comp.type or "unknown"
    local cat = WuxiaGUI3._skillCategory(skId, skType)
    if filter == "all" or filter == cat then
      skillList[#skillList+1] = {
        id=skId, name=comp.name or skId, type=skType, category=cat,
        raw=tonumber(rawLvl) or 0, learnedXP=tonumber(learned[skId]) or 0,
      }
    end
  end

  local catOrder = {knowledge=1, basic=2, martial=3, other=4}
  table.sort(skillList, function(a,b)
    local ca = catOrder[a.category] or 9
    local cb = catOrder[b.category] or 9
    if ca ~= cb then return ca < cb end
    if a.raw ~= b.raw then return a.raw > b.raw end
    return a.id < b.id
  end)

  local catNames = {knowledge="知識類", basic="基本類", martial="特殊類", other="其它"}
  local entries = {}
  local lastCat = nil
  local lineH = WuxiaGUI3._skillLineH
  local cardH = 51  -- name line (~20px) + bar (18px) + padding/gap (~18px)

  -- Kill any previous animations
  WuxiaGUI3._killSkillAnims()

  for _, sk in ipairs(skillList) do
    if filter == "all" and sk.category ~= lastCat then
      lastCat = sk.category
      entries[#entries+1] = {
        html = '<table width="100%" cellspacing="0" cellpadding="0"><tr><td height="'..lineH..'" style="line-height:'..lineH..'px;">' ..
               span(GOLD, "── "..(catNames[sk.category] or sk.category).." ──") ..
               '</td></tr></table>',
        h = lineH + 4,
      }
    end

    local cardHtml, cardBg, cardBorder, barInfo = WuxiaGUI3._buildSkillCardHtml(sk, enabledAs, preparedAs)
    entries[#entries+1] = {
      html = cardHtml,
      cardBg = cardBg,
      cardBorder = cardBorder,
      barInfo = barInfo,
      h = cardH,
      skId = sk.id,
      skData = sk,
    }
  end

  if #entries == 0 then
    entries[#entries+1] = {html=span(TEXT_DIM, "此分類無技能"), h=lineH}
  end


  WuxiaGUI3._skillEntries = entries

  -- Clamp scroll position
  local totalH = 0
  for _, e in ipairs(entries) do totalH = totalH + e.h end
  WuxiaGUI3._skillScrollPx = math.min(
    WuxiaGUI3._skillScrollPx or 0,
    math.max(0, totalH - 200))

  -- Detect level-ups and start animations
  local prevState = WuxiaGUI3._prevSkillState or {}
  local upgradedEntries = {}
  for i, entry in ipairs(entries) do
    if entry.skId and entry.skData then
      local prev = prevState[entry.skId]
      if prev and entry.skData.raw > prev.level then
        upgradedEntries[#upgradedEntries+1] = {
          skId       = entry.skId,
          entryIdx   = i,
          skData     = entry.skData,
          enabledAs  = enabledAs,
          preparedAs = preparedAs,
          oldLevel   = prev.level,
          oldLearned = prev.learned,
          newLevel   = entry.skData.raw,
          newLearned = entry.skData.learnedXP,
        }
      end
    end
  end

  -- Clear prev state so filter changes don't replay the same animations
  WuxiaGUI3._prevSkillState = nil

  -- Start animations if any skills leveled up
  if #upgradedEntries > 0 then
    WuxiaGUI3._startSkillAnims(upgradedEntries)
  else
    WuxiaGUI3._renderSkillScroll()
  end
end

-- ─── 天賦 refresh (from Char.Talents GMCP) ───
function WuxiaGUI3._refreshTalents()
  local t = WuxiaGUI3.talents

  -- Points summary
  if WuxiaGUI3.talentPoints then
    if not t or not t.energy then
      WuxiaGUI3.talentPoints:echo(
        span(TEXT_DIM, "等待天賦資料..."))
    else
      local energy    = tonumber(t.energy) or 0
      local learned   = tonumber(t.learned_energy) or 0
      local available = tonumber(t.available) or 0
      local ys        = tonumber(t.yuanshen_level) or 0
      local maxIdx    = tonumber(t.max_unlocked) or 3

      WuxiaGUI3.talentPoints:echo(
        span(TEXT_DIM, "天賦點 ") ..
        span("#55cc55", tostring(available)) ..
        span(TEXT_DIM, " / " .. tostring(energy)) ..
        span(TEXT_DIM, "  (已用 ") ..
        span("#cc5555", tostring(learned)) ..
        span(TEXT_DIM, ")") ..
        "&nbsp;&nbsp;" ..
        span(TEXT_DIM, "元神Lv") ..
        span(GOLD, tostring(ys)) ..
        span(TEXT_DIM, " 解鎖至#" .. tostring(maxIdx))
      )
    end
  end

  -- Helper: estimate visual line count for a plain text string
  -- Chinese/fullwidth chars count as 2 units, ASCII as 1
  local function estimateLines(text, widthPx)
    local charW = 7  -- approximate px per unit at 10pt
    local charsPerLine = math.floor(widthPx / charW)
    if charsPerLine < 1 then charsPerLine = 1 end
    local units = 0
    for _, code in utf8.codes(text) do
      if code > 0x7F then
        units = units + 2  -- CJK / fullwidth
      else
        units = units + 1  -- ASCII
      end
    end
    return math.max(1, math.ceil(units / charsPerLine))
  end

  local lineH = WuxiaGUI3._talentLineH or 18
  local labelW = WuxiaGUI3._talentLabelW or 280

  -- Talent list → build entries for scroll
  if not WuxiaGUI3.talentList then return end
  if not t or not t.talents then
    WuxiaGUI3._talentEntries = {}
    WuxiaGUI3._talentScrollPx = 0
    WuxiaGUI3._renderTalentScroll()
    return
  end

  local entries = {}
  local talents = t.talents

  for i, talent in ipairs(talents) do
    local idx     = tonumber(talent.index) or i
    local id      = talent.id or "?"
    local name    = talent.name or id
    local desc    = talent.description or ""
    local level   = tonumber(talent.level) or 0
    local maxLv   = tonumber(talent.max_level) or 1
    local value   = tonumber(talent.value) or 0
    local perLv   = tonumber(talent.per_level) or 0
    local locked  = (tonumber(talent.locked) or 0) == 1

    -- Group separator every 3 talents
    if i > 1 and (i - 1) % 3 == 0 then
      local tierNum = math.floor((i - 1) / 3)
      local sepText = string.format("── 第%d階 (元神Lv%d) ──", tierNum + 1, tierNum * 10)
      entries[#entries+1] = {
        html = span(GOLD, sepText),
        h = lineH,
      }
    end

    local idxColor = locked and TEXT_DIM or WHITE
    local idxStr = span(idxColor, string.format("(%2d)", idx))

    local nameColor
    if locked then nameColor = TEXT_DIM
    elseif level >= maxLv then nameColor = GOLD
    elseif level > 0 then nameColor = "#55cc55"
    else nameColor = TEXT end
    local nameStr = span(nameColor, name)

    local lvStr
    if locked then
      lvStr = span(TEXT_DIM, "🔒")
    else
      local filled, empty = "", ""
      for j = 1, maxLv do
        if j <= level then filled = filled .. "■"
        else empty = empty .. "□" end
      end
      lvStr = span("#55cc55", filled) .. span(TEXT_DIM, empty) ..
              " " .. span(WHITE, tostring(level)) ..
              span(TEXT_DIM, "/" .. tostring(maxLv))
    end

    local effectStr
    if locked then effectStr = span(TEXT_DIM, desc)
    elseif value > 0 then
      effectStr = span("#5588cc", "+" .. tostring(value)) ..
                  span(TEXT_DIM, " ") .. span(TEXT, desc)
    else effectStr = span(TEXT_DIM, desc) end

    local upgradeStr = ""
    if not locked and level < maxLv then
      upgradeStr = " " .. span("#aaaa55", "[+" .. tostring(perLv) .. "]")
    elseif not locked and level >= maxLv then
      upgradeStr = " " .. span(GOLD, "✓")
    end

    -- Name + level line: estimate plain text width
    local namePlain = string.format("(%2d) %s  %s %d/%d", idx, name,
      string.rep("■", level) .. string.rep("□", maxLv - level), level, maxLv)
    local nameLines = estimateLines(namePlain, labelW)
    entries[#entries+1] = {
      html = idxStr .. " " .. nameStr .. "&nbsp;&nbsp;" .. lvStr .. upgradeStr,
      h = nameLines * lineH,
    }

    -- Effect/description line
    local descPlain = "      " .. desc
    local descLines = estimateLines(descPlain, labelW)
    entries[#entries+1] = {
      html = "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" .. effectStr,
      h = descLines * lineH,
    }
  end

  -- Footer
  entries[#entries+1] = {
    html = span(TEXT_DIM, "────────────────────"),
    h = lineH,
  }
  entries[#entries+1] = {
    html = span(TEXT_DIM, "點擊 ") ..
      span(GOLD, "talent + N") ..
      span(TEXT_DIM, " 提高第N項天賦等級"),
    h = lineH,
  }

  WuxiaGUI3._talentEntries = entries
  WuxiaGUI3._renderTalentScroll()
end

-- ─── 裝備 refresh (from Char.Inventory GMCP) ───
function WuxiaGUI3._refreshEquipment()
  local inv = WuxiaGUI3.inventory
  if not inv or not inv.items then
    -- No data yet
    if WuxiaGUI3.invHeader then
      WuxiaGUI3.invHeader:echo(span(TEXT_DIM, "等待資料..."))
    end
    return
  end

  local items = inv.items or {}

  -- Slot display names
  local slotNames = {
    hand_primary = "主手", hand_secondary = "副手",
    head = "頭盔", mask = "面具", surcoat = "披風",
    armor = "護甲", cloth = "衣服", wrists = "護腕",
    waist = "腰帶", leggings = "腿甲", boots = "鞋子",
    necklace = "項鏈", earring = "耳墜", hairpin = "髮飾",
    ring = "戒指",
    medal_1 = "勳章①", medal_2 = "勳章②", medal_3 = "勳章③",
    medal_4 = "勳章④", medal_5 = "勳章⑤",
    heart = "胸口", charm = "護符",
  }

  -- Quality names
  local qualityNames = { [1] = "普通", [2] = "優良", [3] = "精良", [4] = "卓越", [5] = "傳說" }
  local qualityColors = { [1] = TEXT_DIM, [2] = "#8a8a5a", [3] = "#5a8a5a", [4] = "#5a5acc", [5] = "#cc8a33" }

  -- ═══ Update equipment slots ═══
  -- GUI slot keys (some are virtual, mapped from PART_ID)
  local allSlots = {
    "hand_primary", "hand_secondary",
    "head", "mask", "surcoat", "armor", "cloth", "wrists",
    "waist", "leggings", "boots",
    "necklace", "earring", "hairpin", "ring",
    "medal_1", "medal_2", "medal_3", "medal_4", "medal_5",
    "heart", "charm",
  }
  local slotItems = {}  -- guiSlotKey → item data

  -- Collect items by PART_ID slot, handling multi-item slots
  local handItems = {}    -- items in "hand" PART_ID (up to 2)
  local medalItems = {}   -- items in "medal" PART_ID (up to 5)
  local holdingItem = nil

  for _, item in ipairs(items) do
    if item.equip_status then
      local slot = item.slot
      if item.equip_status == "holding" then
        holdingItem = item
      elseif slot == "hand" or slot == "twohand" then
        handItems[#handItems + 1] = item
      elseif slot == "medal" then
        medalItems[#medalItems + 1] = item
      elseif slot and slot ~= "" then
        slotItems[slot] = item
      end
    end
  end

  -- Map hand items to primary/secondary GUI slots
  if #handItems >= 1 then slotItems["hand_primary"] = handItems[1] end
  if #handItems >= 2 then slotItems["hand_secondary"] = handItems[2] end
  -- Holding item goes in secondary if no second weapon
  if holdingItem and not slotItems["hand_secondary"] then
    slotItems["hand_secondary"] = holdingItem
  end

  -- Map medals to medal_1 through medal_5
  for i, item in ipairs(medalItems) do
    if i <= 5 then
      slotItems["medal_" .. i] = item
    end
  end

  if WuxiaGUI3._equipSlotLabels then
    for _, slotKey in ipairs(allSlots) do
      local lbl = WuxiaGUI3._equipSlotLabels[slotKey]
      if lbl then
        local item = slotItems[slotKey]
        local slotLabel = slotNames[slotKey] or slotKey
        if item then
          local qColor = qualityColors[item.quality_level] or TEXT_DIM
          local qName = qualityNames[item.quality_level] or ""
          lbl:setStyleSheet(
            "background-color: rgba(20,34,20,160); border: 1px solid #3a5a3a; " ..
            "padding: 18px 5px 2px 5px; " ..
            "qproperty-alignment: 'AlignHCenter | AlignVCenter';")
          lbl:setFontSize(12)
          lbl:echo('<span style="font-size:13px;">' ..
            ansiToHtml(item.display_name or item.name or "???") .. '</span>')
          lbl:setToolTip('<span style="font-size:12px;">' ..
            ansiToHtml(item.name or "???") .. '</span>')
          local hdr = WuxiaGUI3._equipSlotHeaders and WuxiaGUI3._equipSlotHeaders[slotKey]
          if hdr then
            hdr:echo(
              '<span style="color:#888;font-size:10px;">' .. slotLabel ..
              '</span> <span style="color:' .. qColor .. ';font-size:10px;">' .. qName .. '</span>')
          end
        else
          lbl:setStyleSheet(
            "background-color: rgba(17,17,28,160); border: 1px solid " .. BORDER .. "; " ..
            "padding: 18px 5px 2px 5px; " ..
            "qproperty-alignment: 'AlignHCenter | AlignVCenter';")
          lbl:setFontSize(12)
          lbl:echo(span("#555", "空"))
          lbl:setToolTip(slotLabel)
          local hdr = WuxiaGUI3._equipSlotHeaders and WuxiaGUI3._equipSlotHeaders[slotKey]
          if hdr then
            hdr:echo('<span style="color:#777;font-size:10px;">' .. slotLabel .. '</span>')
          end
        end
      end
    end
  end

  -- ═══ Equipment buff summary ═══
  -- Compute equipment buffs from raw item dbase (mirrors attribute.c)
  -- Direct props: armor_prop, weapon_prop
  -- Nested props: rare.apply_prop, enchase.apply_prop,
  --               qianghua.apply_prop, qiling.apply_prop
  -- Conditional:  enchase.mod_prop (only if mod_active)
  local equipBuffs = {}

  local function addProps(props)
    if type(props) ~= "table" then return end
    for k, v in pairs(props) do
      if type(v) == "number" and v ~= 0 then
        equipBuffs[k] = (equipBuffs[k] or 0) + v
      end
    end
  end

  for _, item in ipairs(items) do
    if item.equip_status then
      addProps(item.armor_prop)
      addProps(item.weapon_prop)
      -- Nested: rare/apply_prop → item.rare.apply_prop in Lua table
      if type(item.rare) == "table" then addProps(item.rare.apply_prop) end
      if type(item.enchase) == "table" then
        addProps(item.enchase.apply_prop)
        -- mod_prop only if mod_active
        if item.mod_active then addProps(item.enchase.mod_prop) end
      end
      if type(item.qianghua) == "table" then addProps(item.qianghua.apply_prop) end
      if type(item.qiling) == "table" then addProps(item.qiling.apply_prop) end
    end
  end
  -- Add fullsuit bonuses
  if inv.fullsuit then
    addProps(inv.fullsuit)
  end

  -- Store equipment buffs in the buffs table for the 附加屬性 "裝備" filter
  WuxiaGUI3.buffs.equipment = equipBuffs

  if WuxiaGUI3._equipBuffLabel then
    local sortedKeys = {}
    for k, v in pairs(equipBuffs) do
      if v ~= 0 then sortedKeys[#sortedKeys + 1] = k end
    end
    table.sort(sortedKeys)

    local buffNames = {
      -- Attributes
      str = "臂力", ["int"] = "悟性", con = "根骨", dex = "身法",
      kar = "福緣", per = "容貌", fy = "福緣",
      -- Base stats
      consistence = "耐久度", damage = "兵器傷害力", unarmed_damage = "空手傷害力",
      armor = "保護力",
      -- Max pools
      max_neili = "內力上限", max_qi = "氣血上限",
      max_jingli = "精力上限", max_jing = "精氣上限",
      max_potential = "潛能上限", max_experience = "體會上限",
      -- Combat skills
      sword = "劍法", blade = "刀法", club = "棍法", hammer = "錘法",
      staff = "杖法", whip = "鞭法", unarmed = "拳腳", strike = "掌法",
      cuff = "拳法", hand = "手法", finger = "指法", claw = "爪法",
      -- Combat
      attack = "攻擊", parry = "招架", dodge = "躲閃", defense = "防禦",
      -- Recovery
      neili_recover = "內力恢復", qi_recover = "生命恢復", jing_recover = "精氣恢復",
      -- Elemental damage
      add_poison = "毒傷害", add_magic = "魔傷害",
      add_metal = "金傷害", add_wood = "木傷害",
      add_water = "水傷害", add_fire = "火傷害", add_earth = "土傷害",
      -- Elemental resist
      reduce_magic = "抗魔", reduce_metal = "抗金", reduce_wood = "抗木",
      reduce_water = "抗水", reduce_fire = "抗火", reduce_earth = "抗土",
      reduce_poison = "抗毒", avoid_poison = "百毒不侵",
      -- Training effects
      research_effect = "研究效果", practice_effect = "練習效果",
      study_effect = "讀書效果", learn_effect = "學習效果", derive_effect = "汲取效果",
      research_times = "研究次數", learn_times = "學習次數",
      practice_times = "練習次數", study_times = "讀書次數", derive_times = "汲取消耗",
      -- Special
      magic_find = "尋寶率",
      leech_neili = "偷取內力", leech_qi = "偷取生命",
      ap_power = "絕招命中", dp_power = "絕招防禦", da_power = "絕招傷害",
      avoid_parry = "忽視招架", avoid_dodge = "忽視躲閃",
      avoid_force = "忽視內防", avoid_attack = "忽視特攻",
      through_armor = "穿透破甲", double_damage = "雙倍傷害",
      qi_abs_neili = "傷轉內力", add_reward = "額外獎勵",
      -- Status effects
      add_blind = "致盲", add_freeze = "冰凍", add_forget = "遺忘",
      add_weak = "虛弱", add_busy = "忙亂",
      avoid_blind = "忽視致盲", avoid_freeze = "忽視冰凍",
      avoid_forget = "忽視遺忘", avoid_weak = "忽視虛弱",
      avoid_busy = "忽視忙亂", reduce_busy = "化解忙亂", avoid_fear = "忽視恐懼",
      fatal_blow = "致命一擊",
      add_skill = "提升技能", add_damage = "追加傷害",
      reduce_damage = "化解傷害", full_self = "戰神附體",
      avoid_die = "浴血重生", counter_damage = "傷害反射",
      -- Job
      joblv = "職業等級",
    }

    -- Build entries
    local entries = {}
    if #sortedKeys == 0 then
      entries = {}
    else
      for _, k in ipairs(sortedKeys) do
        local v = equipBuffs[k]
        local label = buffNames[k] or k
        local vStr = v > 0 and ("+" .. tostring(v)) or tostring(v)
        entries[#entries + 1] = {label, vStr}
      end
    end

    if #entries == 0 then
      WuxiaGUI3._equipBuffLabel:echo(span(TEXT_DIM, "無裝備效果"))
    else
      local cols = 3
      local colW = WuxiaGUI3._equipBuffColW or 72
      local rows = math.ceil(#entries / cols)
      local html = '<table cellpadding="0" cellspacing="0" style="line-height:16px;">'
      for r = 1, rows do
        html = html .. '<tr>'
        for c = 1, cols do
          local idx = (r - 1) * cols + c
          local e = entries[idx]
          if e then
            html = html .. '<td width="' .. colW .. '" style="font-size:10px;">' ..
              '<span style="color:' .. TEXT_DIM .. ';">' .. e[1] .. '</span>' ..
              '<span style="color:#55cc55;"> ' .. e[2] .. '</span></td>'
          else
            html = html .. '<td width="' .. colW .. '"></td>'
          end
        end
        html = html .. '</tr>'
      end
      html = html .. '</table>'
      WuxiaGUI3._equipBuffLabel:echo(html)
    end
  end

  -- ═══ Equipment sets ═══
  if WuxiaGUI3._equipSetBtns then
    local sets = inv.sets or {}
    for i = 1, 5 do
      local btn = WuxiaGUI3._equipSetBtns[i]
      if btn and not (WuxiaGUI3._equipSetCooldowns and WuxiaGUI3._equipSetCooldowns[i]) then
        local setData = sets[tostring(i)]
        local hasSet = setData ~= nil
        if hasSet then
          btn:setStyleSheet(
            "background-color: transparent; border: none; qproperty-alignment: AlignCenter;")
          btn:echo(span(GOLD, "<b>" .. tostring(i) .. "</b>"))
          if type(setData) == "table" then
            local tipLines = {}
            for _, base in ipairs(setData) do
              local short = base:match("([^/]+)$") or base
              tipLines[#tipLines + 1] = short
            end
            btn:setToolTip("套裝 " .. tostring(i) .. ":\n" .. table.concat(tipLines, "\n"))
          end
        else
          btn:setStyleSheet(
            "background-color: transparent; border: none; qproperty-alignment: AlignCenter;")
          btn:echo(span(TEXT_DIM, tostring(i)))
          btn:setToolTip("套裝 " .. tostring(i) .. ": 空\n右鍵儲存當前裝備")
        end
      end
    end
  end

  -- ═══ Inventory list ═══
  -- Header: "物品欄 · N件 · 負重 X%"
  if WuxiaGUI3.invHeader then
    local count = 0
    for _ in ipairs(items) do count = count + 1 end
    local enc = inv.encumbrance or 0
    WuxiaGUI3.invHeader:echo(
      span(GOLD, "物品欄") ..
      span(TEXT_DIM, " · " .. tostring(count) .. "件 · ") ..
      span(GOLD, "負重 " .. tostring(enc) .. "%")
    )
  end

  -- Item list
  if WuxiaGUI3.invList then
    local invSlotNames = {
      hand = "主手", twohand = "雙手", holding = "持有",
      head = "頭盔", mask = "面具", surcoat = "披風",
      armor = "護甲", cloth = "衣服", wrists = "護腕",
      waist = "腰帶", leggings = "腿甲", boots = "鞋子",
      necklace = "項鏈", earring = "耳墜", hairpin = "髮飾",
      ring = "戒指", medal = "勳章",
      heart = "胸口", charm = "護符",
    }

    local equipped = {}
    local regular = {}
    for _, item in ipairs(items) do
      if item.equip_status then
        equipped[#equipped + 1] = item
      else
        regular[#regular + 1] = item
      end
    end

    local entries = {}

    for _, item in ipairs(equipped) do
      local slotKey = item.slot or item.armor_type or item.equip_status or "裝備"
      local slotName = invSlotNames[slotKey] or "裝備"
      local nameHtml = ansiToHtml(item.display_name or item.name or "???")
      local idStr = ""
      if item.id and item.id ~= "" then
        idStr = '<span style="color:#888;">(' .. item.id .. ')</span>'
      end
      local qStr = ""
      if item.quality_level and qualityNames[item.quality_level] then
        qStr = ' <span style="color:' .. (qualityColors[item.quality_level] or TEXT_DIM) ..
               ';">' .. qualityNames[item.quality_level] .. '</span>'
      end
      entries[#entries + 1] = {
        html = '<span style="color:#888;">[' .. slotName .. ']</span> ' ..
               nameHtml .. idStr .. qStr
      }
    end

    if #equipped > 0 and #regular > 0 then
      entries[#entries + 1] = {
        html = '<span style="color:#5a4a2a;">────────────</span>'
      }
    end

    -- Stack regular items by base_name + name (like server inventory.c)
    local stacks = {}
    local stackOrder = {}
    for _, item in ipairs(regular) do
      local key = (item.base_name or "") .. "|" .. (item.name or "???")
      if stacks[key] then
        stacks[key].count = stacks[key].count + (item.amount or 1)
      else
        stacks[key] = { item = item, count = item.amount or 1 }
        stackOrder[#stackOrder + 1] = key
      end
    end

    -- Chinese number conversion
    local function chineseNumber(n)
      if n <= 0 then return "" end
      local digits = {"一","二","三","四","五","六","七","八","九"}
      local units = {"","十","百","千","萬"}
      if n <= 10 then
        if n == 10 then return "十" end
        return digits[n]
      elseif n < 20 then
        return "十" .. digits[n - 10]
      elseif n < 100 then
        local tens = math.floor(n / 10)
        local ones = n % 10
        if ones == 0 then return digits[tens] .. "十" end
        return digits[tens] .. "十" .. digits[ones]
      else
        return tostring(n)
      end
    end

    for _, key in ipairs(stackOrder) do
      local s = stacks[key]
      local item = s.item
      local count = s.count
      local nameHtml = ansiToHtml(item.display_name or item.name or "???")
      local idStr = ""
      if item.id and item.id ~= "" then
        idStr = '<span style="color:#888;">(' .. item.id .. ')</span>'
      end
      local countStr = ""
      if count > 1 then
        local unit = item.unit or "個"
        countStr = '<span style="color:#888;">' ..
                   chineseNumber(count) .. unit .. '</span>'
      end
      local qStr = ""
      if item.quality_level and qualityNames[item.quality_level] then
        qStr = ' <span style="color:' .. (qualityColors[item.quality_level] or TEXT_DIM) ..
               ';">' .. qualityNames[item.quality_level] .. '</span>'
      end
      if count > 1 then
        entries[#entries + 1] = {
          html = '&nbsp;' .. countStr .. nameHtml .. idStr .. qStr
        }
      else
        entries[#entries + 1] = {
          html = '&nbsp;' .. nameHtml .. idStr .. qStr
        }
      end
    end

    WuxiaGUI3._invEntries = entries
    WuxiaGUI3._invScrollOffset = 0
    WuxiaGUI3._renderInvScroll()
  end
end

-- ═══════════════════════════════════════════════
-- § 7  GMCP Event Registration
-- ═══════════════════════════════════════════════
function WuxiaGUI3.registerEvents()
  local h = WuxiaGUI3._handlers

  -- F9 hotkey: toggle big map
  WuxiaGUI3._bigMapHotkey = tempKey(mudlet.key.F9, [[WuxiaGUI3._toggleBigMap()]])

  -- Char.Vitals
  h[#h+1] = registerAnonymousEventHandler("gmcp.Char.Vitals", function()
    local gv = gmcp and gmcp.Char and gmcp.Char.Vitals
    if not gv then return end
    local v = WuxiaGUI3.vitals

    v.jing       = tonumber(gv.jing) or v.jing
    v.eff_jing   = tonumber(gv.eff_jing) or v.eff_jing
    v.max_jing   = tonumber(gv.max_jing) or v.max_jing
    v.qi         = tonumber(gv.qi) or v.qi
    v.eff_qi     = tonumber(gv.eff_qi) or v.eff_qi
    v.max_qi     = tonumber(gv.max_qi) or v.max_qi
    v.jingli     = tonumber(gv.jingli) or v.jingli
    v.max_jingli = tonumber(gv.max_jingli) or v.max_jingli
    v.jiajing    = tonumber(gv.jiajing) or v.jiajing
    v.neili      = tonumber(gv.neili) or v.neili
    v.max_neili  = tonumber(gv.max_neili) or v.max_neili
    v.jiali      = tonumber(gv.jiali) or v.jiali
    v.food       = tonumber(gv.food) or v.food
    v.max_food   = tonumber(gv.max_food) or v.max_food
    v.water      = tonumber(gv.water) or v.water
    v.max_water  = tonumber(gv.max_water) or v.max_water
    v.potential  = tonumber(gv.potential) or v.potential
    v.experience = tonumber(gv.experience) or v.experience
    v.combat_exp = tonumber(gv.combat_exp) or v.combat_exp
    v.craze      = tonumber(gv.craze) or v.craze
    v.max_craze  = tonumber(gv.max_craze) or v.max_craze
    v.jianu      = tonumber(gv.jianu) or v.jianu

    WuxiaGUI3.refresh()
  end)

  -- Char.Status
  h[#h+1] = registerAnonymousEventHandler("gmcp.Char.Status", function()
    local gs = gmcp and gmcp.Char and gmcp.Char.Status
    if not gs then return end
    local s = WuxiaGUI3.status

    -- Identity
    s.name           = gs.name or s.name
    s.id             = gs.id or s.id
    s.title          = gs.title or s.title
    s.age            = gs.age or s.age
    s.gender         = gs.gender or s.gender

    -- Attributes
    s.str            = tonumber(gs.str) or s.str
    s.int_           = tonumber(gs["int"]) or s.int_
    s.con            = tonumber(gs.con) or s.con
    s.dex            = tonumber(gs.dex) or s.dex
    s.per            = tonumber(gs.per) or s.per
    s.kar            = tonumber(gs.kar) or s.kar

    -- Level & Combat
    s.level          = tonumber(gs.level) or s.level
    s.wugong_level   = tonumber(gs.wugong_level) or s.wugong_level
    s.combat_exp     = tonumber(gs.combat_exp) or s.combat_exp
    s.next_level     = tonumber(gs.next_level) or s.next_level

    -- Limits
    s.jingli_limit     = tonumber(gs.jingli_limit) or s.jingli_limit
    s.neili_limit      = tonumber(gs.neili_limit) or s.neili_limit
    s.potential_limit   = tonumber(gs.potential_limit) or s.potential_limit
    s.experience_limit  = tonumber(gs.experience_limit) or s.experience_limit

    -- Ability & Achievement
    s.ability        = tonumber(gs.ability) or s.ability
    s.achievement    = tonumber(gs.achievement) or s.achievement
    s.active         = tonumber(gs.active) or s.active

    -- Special
    s.xuemai_level   = tonumber(gs.xuemai_level) or s.xuemai_level
    s.yuanshen_level = tonumber(gs.yuanshen_level) or s.yuanshen_level

    -- Computed hp -m fields
    s.max_jiali       = tonumber(gs.max_jiali) or s.max_jiali
    s.max_jianu       = tonumber(gs.max_jianu) or s.max_jianu
    s.xuemai_progress = tonumber(gs.xuemai_progress) or s.xuemai_progress
    s.yuanshen_next   = tonumber(gs.yuanshen_next) or s.yuanshen_next
    s.death_protect   = tonumber(gs.death_protect) or s.death_protect
    s.kill_protect    = tonumber(gs.kill_protect) or s.kill_protect

    -- Attribute breakdown (nested tables - assign directly)
    if type(gs.gift) == "table" then s.gift = gs.gift end
    if type(gs.jm) == "table" then s.jm = gs.jm end
    if type(gs.ys) == "table" then s.ys = gs.ys end

    -- Skills
    s.force          = tonumber(gs.force) or s.force
    s.dodge          = tonumber(gs.dodge) or s.dodge
    s.parry          = tonumber(gs.parry) or s.parry
    s.unarmed        = tonumber(gs.unarmed) or s.unarmed
    s.sword          = tonumber(gs.sword) or s.sword
    s.blade          = tonumber(gs.blade) or s.blade
    s.staff          = tonumber(gs.staff) or s.staff
    s.whip           = tonumber(gs.whip) or s.whip
    s.throwing       = tonumber(gs.throwing) or s.throwing
    s.shooting       = tonumber(gs.shooting) or s.shooting
    s.literate       = tonumber(gs.literate) or s.literate
    s["martial-arts"] = tonumber(gs["martial-arts"]) or s["martial-arts"]

    WuxiaGUI3.refresh()
  end)

  -- Char.Info
  h[#h+1] = registerAnonymousEventHandler("gmcp.Char.Info", function()
    local gi = gmcp and gmcp.Char and gmcp.Char.Info
    if not gi then return end
    WuxiaGUI3.status.name = gi.name or WuxiaGUI3.status.name
    -- Welcome message in chat
    WuxiaGUI3.chat("系統",
      string.format("<gold>歡迎回來，%s。<reset>", gi.name or "俠客"))
  end)

  -- Room.Info (store for future map tab)
  h[#h+1] = registerAnonymousEventHandler("gmcp.Room.Info", function()
    local gr = gmcp and gmcp.Room and gmcp.Room.Info
    if not gr then return end
    WuxiaGUI3.room = {
      name  = gr.name or "",
      path  = gr.path or "",
      exits = gr.exits or {},
      long  = gr.long or "",
    }
    -- Send Map.Hello once after first Room.Info (server is ready)
    if not WuxiaGUI3.graphMap.initialized then
      sendGMCP('Map.Hello {"ver":1,"subscriptions":{"topology":true,"viewstate":true,"entities":true,"poi":true}}')
      WuxiaGUI3.graphMap.initialized = true
    end
    WuxiaGUI3._updateScenePanel()
  end)

  -- ═══ Graph Map GMCP Handlers ═══

  h[#h+1] = registerAnonymousEventHandler("gmcp.Map.Init", function()
    local data = gmcp and gmcp.Map and gmcp.Map.Init
    if not data then return end
    local gm = WuxiaGUI3.graphMap

    gm.config = data.config or {}
    gm.currentRoom = data.character and data.character.room_id

    -- Load topology
    if data.topology then
      for _, r in ipairs(data.topology.rooms or {}) do
        gm.rooms[r.id] = r
        gm.exploredRooms[r.id] = true
      end
      for _, e in ipairs(data.topology.edges or {}) do
        gm.edges[e.id] = e
      end
    end

    -- Set visible
    gm.visibleRooms = {}
    for _, rid in ipairs(data.visible or {}) do
      gm.visibleRooms[rid] = true
    end

    -- Load entities
    gm.entities = {}
    for _, ent in ipairs(data.entities or {}) do
      if ent.id then gm.entities[ent.id] = ent end
    end

    -- Load POIs
    gm.pois = {}
    for _, poi in ipairs(data.pois or {}) do
      if poi.id then gm.pois[poi.id] = poi end
    end

    -- Reset all map view contexts
    local room = gm.rooms[gm.currentRoom]
    local rz = room and (room.z or 0) or 0
    if WuxiaGUI3.miniMapCtx then
      WuxiaGUI3.miniMapCtx.currentZ = rz
      WuxiaGUI3.miniMapCtx.panX = 0
      WuxiaGUI3.miniMapCtx.panY = 0
    end
    if WuxiaGUI3.bigMapCtx then
      WuxiaGUI3.bigMapCtx.currentZ = rz
      WuxiaGUI3.bigMapCtx.panX = 0
      WuxiaGUI3.bigMapCtx.panY = 0
    end

    WuxiaGUI3._renderGraphMap()
    WuxiaGUI3._updateScenePanel()
  end)

  h[#h+1] = registerAnonymousEventHandler("gmcp.Map.TopologyAdd", function()
    local data = gmcp and gmcp.Map and gmcp.Map.TopologyAdd
    if not data then return end
    local gm = WuxiaGUI3.graphMap

    for _, r in ipairs(data.rooms or {}) do
      gm.rooms[r.id] = r
      gm.exploredRooms[r.id] = true
    end
    for _, e in ipairs(data.edges or {}) do
      gm.edges[e.id] = e
    end

    -- Accumulate POIs from topology batches
    for _, poi in ipairs(data.pois or {}) do
      if poi.id then gm.pois[poi.id] = poi end
    end

    WuxiaGUI3._renderGraphMap()
  end)

  h[#h+1] = registerAnonymousEventHandler("gmcp.Map.ViewState", function()
    local data = gmcp and gmcp.Map and gmcp.Map.ViewState
    if not data then return end
    local gm = WuxiaGUI3.graphMap

    gm.currentRoom = data.room

    -- Apply visibility delta
    for _, rid in ipairs(data.visible_add or {}) do
      gm.visibleRooms[rid] = true
    end
    for _, rid in ipairs(data.visible_remove or {}) do
      gm.visibleRooms[rid] = nil
    end
    for _, rid in ipairs(data.explored_add or {}) do
      gm.exploredRooms[rid] = true
    end

    -- Auto-follow for each map view context
    local room = gm.rooms[gm.currentRoom]
    local rz = room and (room.z or 0) or 0
    if WuxiaGUI3.miniMapCtx then
      WuxiaGUI3.miniMapCtx.currentZ = rz
      WuxiaGUI3.miniMapCtx.panX = 0
      WuxiaGUI3.miniMapCtx.panY = 0
    end
    if WuxiaGUI3.bigMapCtx and WuxiaGUI3._bigMapVisible then
      WuxiaGUI3.bigMapCtx.currentZ = rz
      if WuxiaGUI3.bigMapCtx.followPlayer then
        WuxiaGUI3.bigMapCtx.panX = 0
        WuxiaGUI3.bigMapCtx.panY = 0
      end
    end

    WuxiaGUI3._renderGraphMap()
    WuxiaGUI3._updateScenePanel()
  end)

  h[#h+1] = registerAnonymousEventHandler("gmcp.Map.Error", function()
    local data = gmcp and gmcp.Map and gmcp.Map.Error
    if not data then return end
    WuxiaGUI3.chat("系統",
      string.format("<red>地圖錯誤：%s<reset>", data.message or data.code or "unknown"))
  end)

  h[#h+1] = registerAnonymousEventHandler("gmcp.Map.EntitiesDelta", function()
    local data = gmcp and gmcp.Map and gmcp.Map.EntitiesDelta
    if not data then return end
    local gm = WuxiaGUI3.graphMap

    -- Process adds
    for _, ent in ipairs(data.add or {}) do
      if ent.id then gm.entities[ent.id] = ent end
    end

    -- Process updates (entity moved room, or data changed)
    for _, ent in ipairs(data.update or {}) do
      if ent.id then
        if gm.entities[ent.id] then
          for k, v in pairs(ent) do
            gm.entities[ent.id][k] = v
          end
        else
          gm.entities[ent.id] = ent
        end
      end
    end

    -- Process removes
    for _, eid in ipairs(data.remove or {}) do
      gm.entities[eid] = nil
    end

    WuxiaGUI3._renderGraphMap()
    WuxiaGUI3._updateScenePanel()
  end)

  h[#h+1] = registerAnonymousEventHandler("gmcp.Map.POIDelta", function()
    local data = gmcp and gmcp.Map and gmcp.Map.POIDelta
    if not data then return end
    local gm = WuxiaGUI3.graphMap

    for _, poi in ipairs(data.add or {}) do
      if poi.id then gm.pois[poi.id] = poi end
    end
    for _, pid in ipairs(data.remove or {}) do
      gm.pois[pid] = nil
    end

    WuxiaGUI3._renderGraphMap()
  end)

  -- Char.Buffs (raw source mappings — GUI computes totals)
  h[#h+1] = registerAnonymousEventHandler("gmcp.Char.Buffs", function()
    local gb = gmcp and gmcp.Char and gmcp.Char.Buffs
    if not gb then return end

    local b = WuxiaGUI3.buffs or {}
    for srcName, srcData in pairs(gb) do
      if type(srcData) == "table" then
        local m = {}
        for k, v in pairs(srcData) do
          m[k] = tonumber(v) or 0
        end
        b[srcName] = m
      end
    end
    WuxiaGUI3.buffs = b

    WuxiaGUI3.refresh()
  end)

  -- Char.Skills (skill data from server)
  h[#h+1] = registerAnonymousEventHandler("gmcp.Char.Skills", function()
    local gs = gmcp and gmcp.Char and gmcp.Char.Skills
    if not gs then return end

    -- Save previous state for level-up detection.
    -- Only update if no pending upgrades exist — preserve the baseline from
    -- when the user last saw the tab so the full delta is animated.
    if not WuxiaGUI3._pendingSkillUpgrades then
      local prevSD = WuxiaGUI3.skillData
      if prevSD and prevSD.skills then
        local newPrevState = {}
        for skId, rawLvl in pairs(prevSD.skills) do
          newPrevState[skId] = {
            level   = tonumber(rawLvl) or 0,
            learned = tonumber((prevSD.learned or {})[skId]) or 0,
          }
        end
        WuxiaGUI3._prevSkillState = newPrevState
      end
    end

    WuxiaGUI3.skillData = {
      skills        = gs.skills or {},
      learned       = gs.learned or {},
      skill_map     = gs.skill_map or {},
      skill_prepare = gs.skill_prepare or {},
      wprepare      = gs.wprepare or {},
      computed      = gs.computed or {},
    }

    if WuxiaGUI3.activeTab == "技能" then
      -- User is on the tab: refresh immediately (will detect upgrades and animate)
      WuxiaGUI3._refreshSkills()
    else
      -- User is NOT on the tab: check for level-ups and mark as pending
      local prevState = WuxiaGUI3._prevSkillState or {}
      local newSkills = WuxiaGUI3.skillData.skills or {}
      local hasUpgrade = false
      for skId, rawLvl in pairs(newSkills) do
        local prev = prevState[skId]
        if prev and (tonumber(rawLvl) or 0) > prev.level then
          hasUpgrade = true
          break
        end
      end
      if hasUpgrade then
        WuxiaGUI3._pendingSkillUpgrades = true
        -- Add gold indicator dot to the 技能 tab button
        local btn = WuxiaGUI3.tabButtons and WuxiaGUI3.tabButtons["技能"]
        if btn then
          btn:echo(span(GOLD_DIM, "技能") .. ' <span style="color:#e8c170;">●</span>')
        end
      end
    end
  end)


  -- Char.Talents (talent tree data)
  h[#h+1] = registerAnonymousEventHandler("gmcp.Char.Talents", function()
    local gt = gmcp and gmcp.Char and gmcp.Char.Talents
    if not gt then return end

    WuxiaGUI3.talents = gt

    -- DEBUG: uncomment to verify data arrival
    -- debugc("WuxiaGUI3: Char.Talents received, " .. tostring(gt.energy or "nil") .. " energy")

    if WuxiaGUI3.activeTab == "天賦" then
      WuxiaGUI3._refreshTalents()
    end
  end)

  -- Char.Inventory (items, equipment slots, sets, fullsuit)
  h[#h+1] = registerAnonymousEventHandler("gmcp.Char.Inventory", function()
    local gi = gmcp and gmcp.Char and gmcp.Char.Inventory
    if not gi then return end

    local inv = {}
    inv.encumbrance = tonumber(gi.encumbrance) or 0
    inv.handing = gi.handing
    inv.secondary = gi.secondary
    inv.fullsuit = gi.fullsuit  -- mapping or nil
    inv.sets = gi.sets          -- mapping or nil

    -- Parse items[] (raw dbase) + computed[] (server-only data), parallel arrays
    inv.items = {}
    if type(gi.items) == "table" then
      local computed = gi.computed or {}
      for i, raw in ipairs(gi.items) do
        if type(raw) == "table" then
          local item = {}
          for k, v in pairs(raw) do
            item[k] = v
          end

          -- Merge server-computed fields (parallel array, same index)
          local comp = computed[i]
          if type(comp) == "table" then
            item.display_name  = comp.name
            item.short_desc    = comp.short
            item.base_name     = comp.base_name
            item.equip_status  = comp.equip_status
            if comp.slot then item.slot = comp.slot end
            if comp.mod_active then item.mod_active = true end
            if comp.amount then item.amount = tonumber(comp.amount) end
          end

          -- Slot from computed already matches PART_ID from equip.h

          -- Fallbacks
          if not item.display_name then
            item.display_name = item.name or "???"
          end
          if not item.slot or item.slot == "" then
            item.slot = item.armor_type or item.weapon_type
          end
          if not item.base_name then item.base_name = "" end

          -- Ensure numeric fields from dbase
          if item.quality_level then item.quality_level = tonumber(item.quality_level) end

          inv.items[#inv.items + 1] = item
        end
      end
    end

    WuxiaGUI3.inventory = inv

    -- Refresh equipment tab
    WuxiaGUI3._refreshEquipment()
    -- Also refresh bonus stats since equipment buffs changed
    WuxiaGUI3._refreshBonusStats()
  end)

  -- Request initial burst
  sendGMCP("Char.Vitals.Request")
  sendGMCP("Char.Status.Request")
  sendGMCP("Char.Buffs.Request")
  sendGMCP("Char.Skills.Request")
  sendGMCP("Char.Talents.Request")
  sendGMCP("Char.Inventory.Request")
  sendGMCP("Char.Info.Request")
  sendGMCP("Room.Info.Request")
end

-- ═══════════════════════════════════════════════
-- § 8  Cleanup / Destroy
-- ═══════════════════════════════════════════════
function WuxiaGUI3.destroy()
  -- Kill GMCP handlers
  if WuxiaGUI3._handlers then
    for _, h in ipairs(WuxiaGUI3._handlers) do
      killAnonymousEventHandler(h)
    end
    WuxiaGUI3._handlers = {}
  end

  -- Kill system handlers
  if WuxiaGUI3._sysHandlers then
    for _, h in ipairs(WuxiaGUI3._sysHandlers) do
      killAnonymousEventHandler(h)
    end
    WuxiaGUI3._sysHandlers = {}
  end

  -- Save state and kill big map hotkey and window
  WuxiaGUI3._saveSettings()
  if WuxiaGUI3._bigMapWin then
    saveWindowLayout()
  end
  if WuxiaGUI3._bigMapHotkey then
    killKey(WuxiaGUI3._bigMapHotkey)
    WuxiaGUI3._bigMapHotkey = nil
  end
  if WuxiaGUI3._bigMapWin then
    WuxiaGUI3._bigMapWin:hide()
    WuxiaGUI3._bigMapWin = nil
  end
  WuxiaGUI3._bigMapFrame = nil
  WuxiaGUI3.bigMapCtx = nil
  WuxiaGUI3.miniMapCtx = nil
  WuxiaGUI3._bigMapVisible = false

  -- Kill chat aliases
  if WuxiaGUI3._chatAliasID then
    killAlias(WuxiaGUI3._chatAliasID)
    WuxiaGUI3._chatAliasID = nil
  end
  if WuxiaGUI3._chatDirectAliasID then
    killAlias(WuxiaGUI3._chatDirectAliasID)
    WuxiaGUI3._chatDirectAliasID = nil
  end
  if WuxiaGUI3._chatTuneAliasID then
    killAlias(WuxiaGUI3._chatTuneAliasID)
    WuxiaGUI3._chatTuneAliasID = nil
  end

  -- Destroy GUI
  WuxiaGUI3._destroyDrawer()
  if WuxiaGUI3.chatMain then
    WuxiaGUI3.chatMain:hide()
    WuxiaGUI3.chatMain = nil
  end
  WuxiaGUI3.chatConsoles = nil
  WuxiaGUI3.chatTabButtons = nil

  if WuxiaGUI3.main then
    WuxiaGUI3.main:hide()
    WuxiaGUI3.main = nil
  end
  if WuxiaGUI3.leftMain then
    WuxiaGUI3.leftMain:hide()
    WuxiaGUI3.leftMain = nil
  end

  setBorderRight(0)
  setBorderLeft(0)
  setBorderTop(0)
  setBorderBottom(0)
  WuxiaGUI3.initialized = false
end

-- ═══════════════════════════════════════════════
-- § 9  Start
-- ═══════════════════════════════════════════════
function WuxiaGUI3.start()
  WuxiaGUI3.build()
  WuxiaGUI3.registerEvents()
  WuxiaGUI3.refresh()

  -- Restore big map if it was open last session
  if WuxiaGUI3._savedBigMapOpen then
    WuxiaGUI3._toggleBigMap()
  end

  -- Fix initial layout timing: re-apply borders after Mudlet finishes its
  -- own window geometry setup (avoids main console hidden behind left panel)
  tempTimer(0.1, function()
    if WuxiaGUI3.initialized then
      local chatH = WuxiaGUI3._currentChatH or CHAT_H
      setBorderRight(PW)
      setBorderLeft(LPW)
      setBorderTop(chatH)
      setBorderBottom(18)
    end
  end)

  -- Re-apply borders on reconnect (same timing fix as initial load)
  WuxiaGUI3._sysHandlers[#WuxiaGUI3._sysHandlers+1] =
    registerAnonymousEventHandler("sysConnectionEvent", function()
      tempTimer(0.1, function()
        if WuxiaGUI3.initialized then
          local chatH = WuxiaGUI3._currentChatH or CHAT_H
          setBorderRight(PW)
          setBorderLeft(LPW)
          setBorderTop(chatH)
          setBorderBottom(18)
        end
      end)
    end)

  -- Cleanup on profile exit
  WuxiaGUI3._sysHandlers[#WuxiaGUI3._sysHandlers+1] =
    registerAnonymousEventHandler("sysExitEvent", function()
      if WuxiaGUI3 and WuxiaGUI3.destroy then
        WuxiaGUI3.destroy()
      end
    end)
end

-- Auto-start
WuxiaGUI3.start()
