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
}

-- Char.Buffs: raw source data from server
WuxiaGUI3.buffs = {}
WuxiaGUI3._buffsActiveFilter = "all"

-- Char.Inventory: items, equipment, sets
WuxiaGUI3.inventory = {}

-- Char.Talents: talent tree data from server
WuxiaGUI3.talents = {}

-- ═══════════════════════════════════════════════
-- § 3  Helpers
-- ═══════════════════════════════════════════════
local MX = 10                       -- horizontal margin
local GW = PW - MX * 2             -- gauge / content width

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

  -- Background
  local back = Geyser.Label:new({
    name = "W3."..id..".back",
    x = 0, y = 0, width = "100%", height = "100%",
  }, gc)
  back:setStyleSheet(string.format(
    "background-color: %s; border-radius: 2px; border: 1px solid rgba(80,70,50,0.4);", bgColor))

  -- Normal fill (0–100%)
  local fill = Geyser.Label:new({
    name = "W3."..id..".fill",
    x = 0, y = 0, width = "0%", height = "100%",
  }, gc)
  fill:setStyleSheet(string.format(
    "background-color: %s; border-radius: 2px;", fgColor))

  -- Overflow fill (100%+ portion, brighter color)
  local overflow = Geyser.Label:new({
    name = "W3."..id..".overflow",
    x = 0, y = 0, width = "0%", height = "100%",
  }, gc)
  overflow:setStyleSheet(string.format(
    "background-color: %s; border-radius: 0px 2px 2px 0px;", fgColor))
  overflow:hide()

  -- 100% marker line (thin vertical line)
  local marker = Geyser.Label:new({
    name = "W3."..id..".marker",
    x = "50%", y = 0, width = 2, height = "100%",
  }, gc)
  marker:setStyleSheet("background-color: #ffffff;")
  marker:hide()

  WuxiaGUI3[id.."Gauge"]    = { container = gc, back = back, fill = fill,
                                 overflow = overflow, marker = marker,
                                 fgColor = fgColor }

  return y + 15 + h + 4
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

  -- Background fill
  WuxiaGUI3.leftBg = Geyser.Label:new({
    name = "W3.left.bg", x = 0, y = 0,
    width = "100%", height = "100%",
  }, WuxiaGUI3.leftMain)
  WuxiaGUI3.leftBg:setStyleSheet(string.format(
    "background-color: %s; border-right: 1px solid %s;", BG, BORDER))

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
  local y = 4

  -- Vitals gauges
  y = makeGauge(p, "jing",   y, 18, C_JING[1],   C_JING[2])
  y = makeGauge(p, "qi",     y, 18, C_QI[1],     C_QI[2])
  y = makeGauge(p, "jingli", y, 18, C_JINGLI[1], C_JINGLI[2])
  y = makeGauge(p, "neili",  y, 18, C_NEILI[1],  C_NEILI[2])

  -- Food / Water small gauges
  y = y + 2
  -- Food gauge (half width)
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

  -- Water gauge (half width, right side)
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

  -- Separator
  y = makeSep(p, y)

  -- Experience / Potential / Tihui block
  y = makeLabel(p, "expBlock", y, 52)
  y = y + 2

  -- Separator
  y = makeSep(p, y)

  -- Identity quick view
  y = makeLabel(p, "identityBlock", y, 80)
end

-- ═══════════════════════════════════════════════
-- § 4b  Tab: 屬性 (Attributes / Stats)
-- ═══════════════════════════════════════════════
function WuxiaGUI3._buildAttributes()
  local p = WuxiaGUI3.tabContainers["屬性"]
  local y = 4

  -- Section: 六大屬性
  local hdr = Geyser.Label:new({
    name = "W3.attr.hdr", x = MX, y = y, width = GW, height = 18,
  }, p)
  hdr:setStyleSheet("background-color:transparent;")
  hdr:setFontSize(10)
  hdr:echo(span(GOLD, "── 六大屬性 ──"))
  y = y + 22

  -- 6 attributes displayed as a 2-column grid
  y = makeLabel(p, "attrGrid", y, 80)
  y = y + 4

  -- Section: 等級 & 戰鬥
  y = makeSep(p, y)
  local hdr2 = Geyser.Label:new({
    name = "W3.level.hdr", x = MX, y = y, width = GW, height = 18,
  }, p)
  hdr2:setStyleSheet("background-color:transparent;")
  hdr2:setFontSize(10)
  hdr2:echo(span(GOLD, "── 等級 ──"))
  y = y + 22

  y = makeLabel(p, "levelBlock", y, 80)
  y = y + 4

  -- Section: 上限
  y = makeSep(p, y)
  local hdr3 = Geyser.Label:new({
    name = "W3.limits.hdr", x = MX, y = y, width = GW, height = 18,
  }, p)
  hdr3:setStyleSheet("background-color:transparent;")
  hdr3:setFontSize(10)
  hdr3:echo(span(GOLD, "── 上限 ──"))
  y = y + 22

  y = makeLabel(p, "limitsBlock", y, 80)

  -- Section: 血脈 / 元神
  y = y + 4
  y = makeSep(p, y)
  local hdr4 = Geyser.Label:new({
    name = "W3.special.hdr", x = MX, y = y, width = GW, height = 18,
  }, p)
  hdr4:setStyleSheet("background-color:transparent;")
  hdr4:setFontSize(10)
  hdr4:echo(span(GOLD, "── 修煉 ──"))
  y = y + 22

  y = makeLabel(p, "specialBlock", y, 60)

  -- Section: 附加屬性 (full istat, client-side filtering)
  y = y + 4
  y = makeSep(p, y)
  local hdr5 = Geyser.Label:new({
    name = "W3.bonusStats.hdr", x = MX, y = y, width = GW, height = 18,
  }, p)
  hdr5:setStyleSheet("background-color:transparent;")
  hdr5:setFontSize(10)
  hdr5:echo(span(GOLD, "── 附加屬性 ──"))
  y = y + 22

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
  local btnH = 18
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
  y = y + math.ceil(#filterSources / 4) * btnH + 4
  WuxiaGUI3._updateBuffsFilterBtns()

  y = makeLabel(p, "bonusStatsInfo", y, 20)
  y = makeLabel(p, "bonusStatsList", y, 700)
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
function WuxiaGUI3._buildSkills()
  local p = WuxiaGUI3.tabContainers["技能"]
  local y = 4

  local hdr = Geyser.Label:new({
    name = "W3.skills.hdr", x = MX, y = y, width = GW, height = 18,
  }, p)
  hdr:setStyleSheet("background-color:transparent;")
  hdr:setFontSize(10)
  hdr:echo(span(GOLD, "── 武功技能 ──"))
  y = y + 22

  -- We'll render skill bars as label + gauge pairs
  local skillList = {
    { id = "sk_force",   label = "內功" },
    { id = "sk_dodge",   label = "躲閃" },
    { id = "sk_parry",   label = "招架" },
    { id = "sk_unarmed", label = "拳腳" },
    { id = "sk_sword",   label = "劍法" },
    { id = "sk_blade",   label = "刀法" },
    { id = "sk_staff",   label = "棍法" },
    { id = "sk_whip",    label = "鞭法" },
    { id = "sk_throw",   label = "暗器" },
    { id = "sk_shoot",   label = "弓術" },
    { id = "sk_lit",     label = "讀書" },
    { id = "sk_martial", label = "武術" },
  }

  WuxiaGUI3._skillList = skillList

  for _, sk in ipairs(skillList) do
    -- Label
    local lbl = Geyser.Label:new({
      name = "W3."..sk.id..".lbl",
      x = MX, y = y, width = GW, height = 14,
    }, p)
    lbl:setStyleSheet("background-color:transparent;")
    lbl:setFontSize(8)
    WuxiaGUI3[sk.id.."Lbl"] = lbl

    -- Gauge
    local g = Geyser.Gauge:new({
      name = "W3."..sk.id..".gauge",
      x = MX, y = y + 14, width = GW, height = 10,
    }, p)
    g.front:setStyleSheet("background-color:#5588aa;border-radius:2px;")
    g.back:setStyleSheet("background-color:#1a2a3a;border-radius:2px;")
    g:setValue(0, 1)
    WuxiaGUI3[sk.id.."Gauge"] = g

    y = y + 28
  end
end

-- ═══════════════════════════════════════════════
-- § 4d  Tab: 天賦 (Talents)
-- ═══════════════════════════════════════════════
function WuxiaGUI3._buildTalents()
  local p = WuxiaGUI3.tabContainers["天賦"]
  local y = 4

  -- Background image
  local bgLabel = Geyser.Label:new({
    name = "W3.talent.bg",
    x = 0, y = 0,
    width = PW, height = 1200,
  }, p)
  local imgPath = getMudletHomeDir() .. "/WuxiaGUI3/wuxia_talent_bg.png"
  if io.open(imgPath, "r") then
    bgLabel:setStyleSheet(
      "background-color: transparent; " ..
      "border-image: url(" .. imgPath .. ") 0 0 0 0 stretch stretch;")
  else
    bgLabel:setStyleSheet("background-color: transparent; border: none;")
  end

  -- Header
  local hdr = Geyser.Label:new({
    name = "W3.talent.hdr", x = MX, y = y, width = GW, height = 18,
  }, p)
  hdr:setStyleSheet("background-color:transparent;")
  hdr:setFontSize(10)
  hdr:echo(span(GOLD, "── 天賦技能 ──"))
  y = y + 22

  -- Points summary bar
  y = makeLabel(p, "talentPoints", y, 20)
  y = y + 4

  -- Separator
  y = makeSep(p, y)

  -- Column header row
  local colHdr = Geyser.Label:new({
    name = "W3.talent.colHdr", x = MX, y = y, width = GW, height = 16,
  }, p)
  colHdr:setStyleSheet("background-color:transparent;")
  colHdr:setFontSize(7)
  colHdr:echo(
    span(TEXT_DIM, "序號") ..
    "&nbsp;&nbsp;&nbsp;&nbsp;" ..
    span(TEXT_DIM, "天賦名稱") ..
    "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" ..
    span(TEXT_DIM, "等級") ..
    "&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" ..
    span(TEXT_DIM, "效果")
  )
  y = y + 18

  -- Scrollable talent list (32 talents x ~30px = ~960px)
  y = makeLabel(p, "talentList", y, 900)
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
  local w = LPW - 8
  local mapH = 160
  local battleH = 160

  -- ─── Section 1: 地圖 (top, fixed) ───
  local y = 4
  local mapHdr = Geyser.Label:new({
    name = "W3.left.mapHdr", x = 4, y = y, width = w, height = 18,
  }, p)
  mapHdr:setStyleSheet("background-color:transparent; qproperty-alignment: AlignCenter;")
  mapHdr:setFontSize(9)
  mapHdr:echo(span(GOLD, "── 地圖 ──"))
  y = y + 20

  WuxiaGUI3.mapArea = Geyser.Label:new({
    name = "W3.left.map",
    x = 4, y = y, width = w, height = mapH,
  }, p)
  WuxiaGUI3.mapArea:setStyleSheet(string.format([[
    background-color: %s;
    border: 1px solid %s;
    qproperty-alignment: AlignCenter;
  ]], BG2, BORDER))
  WuxiaGUI3.mapArea:setFontSize(8)
  WuxiaGUI3.mapArea:echo(
    span(TEXT_DIM, "需要 GMCP 封包") .. "<br>" ..
    span(TEXT_DIM, "地圖功能開發中"))

  local sceneTopY = y + mapH + 4  -- where scene starts

  -- ─── Section 3: 戰鬥 (bottom, fixed, anchored to bottom) ───
  -- Build from bottom up: enemy list, target info, header
  local battleListH = battleH - 38  -- subtract header + target line

  local battleHdr = Geyser.Label:new({
    name = "W3.left.battleHdr", x = 4, y = -(battleH), width = w, height = 18,
  }, p)
  battleHdr:setStyleSheet("background-color:transparent; qproperty-alignment: AlignCenter;")
  battleHdr:setFontSize(9)
  battleHdr:echo(span(GOLD, "── 戰鬥 ──"))

  WuxiaGUI3.battleTargetInfo = Geyser.Label:new({
    name = "W3.left.target",
    x = 4, y = -(battleH - 18), width = w, height = 18,
  }, p)
  WuxiaGUI3.battleTargetInfo:setStyleSheet(string.format(
    "background-color: transparent; padding-left: 2px;"))
  WuxiaGUI3.battleTargetInfo:setFontSize(8)
  WuxiaGUI3.battleTargetInfo:echo(span(TEXT_DIM, "目前無目標"))

  WuxiaGUI3.battleEnemyList = Geyser.Label:new({
    name = "W3.left.enemies",
    x = 4, y = -(battleListH + 2), width = w, height = battleListH,
  }, p)
  WuxiaGUI3.battleEnemyList:setStyleSheet(string.format([[
    background-color: %s;
    border: 1px solid %s;
    padding: 4px;
    qproperty-alignment: AlignTop;
  ]], BG2, BORDER))
  WuxiaGUI3.battleEnemyList:setFontSize(8)
  WuxiaGUI3.battleEnemyList:echo(
    span(TEXT_DIM, "需要 GMCP 封包") .. "<br>" ..
    span(TEXT_DIM, "戰鬥系統開發中"))

  -- ─── Section 2: 場景 (middle, fills remaining space) ───
  -- Use a container anchored between map bottom and battle top
  local sceneContainer = Geyser.Container:new({
    name = "W3.left.sceneCont",
    x = 0, y = sceneTopY,
    width = LPW, height = "-" .. (battleH + 4 + sceneTopY) .. "px",
  }, p)

  local sceneHdr = Geyser.Label:new({
    name = "W3.left.sceneHdr", x = 4, y = 0, width = w, height = 18,
  }, sceneContainer)
  sceneHdr:setStyleSheet("background-color:transparent; qproperty-alignment: AlignCenter;")
  sceneHdr:setFontSize(9)
  sceneHdr:echo(span(GOLD, "── 場景 ──"))

  WuxiaGUI3.sceneRoomName = Geyser.Label:new({
    name = "W3.left.roomName",
    x = 4, y = 20, width = w, height = 18,
  }, sceneContainer)
  WuxiaGUI3.sceneRoomName:setStyleSheet(string.format(
    "background-color: transparent; padding-left: 2px;"))
  WuxiaGUI3.sceneRoomName:setFontSize(8)
  WuxiaGUI3.sceneRoomName:echo(span(TEXT_DIM, "未知位置"))

  -- Content list: fills rest of scene container
  WuxiaGUI3.sceneContentList = Geyser.Label:new({
    name = "W3.left.content",
    x = 4, y = 40,
    width = w, height = "-4px",
  }, sceneContainer)
  WuxiaGUI3.sceneContentList:setStyleSheet(string.format([[
    background-color: %s;
    border: 1px solid %s;
    padding: 4px;
    qproperty-alignment: AlignTop;
  ]], BG2, BORDER))
  WuxiaGUI3.sceneContentList:setFontSize(8)
  WuxiaGUI3.sceneContentList:echo(
    span(TEXT_DIM, "需要 GMCP 封包") .. "<br>" ..
    span(TEXT_DIM, "輸入 ") .. span(GOLD, "look") ..
    span(TEXT_DIM, " 來查看"))
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
  WuxiaGUI3.activeTab = tabName

  -- Style all tab buttons
  for name, btn in pairs(WuxiaGUI3.tabButtons) do
    if name == tabName then
      btn:setStyleSheet(string.format([[
        background-color: %s;
        border-bottom: 2px solid %s;
        qproperty-alignment: AlignCenter;
      ]], BG2, GOLD))
      btn:echo(span(GOLD, "<b>"..name.."</b>"))
    else
      btn:setStyleSheet(string.format([[
        background-color: %s;
        border-bottom: 1px solid %s;
        qproperty-alignment: AlignCenter;
      ]], BG, BORDER))
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

    if pct <= 1.0 then
      -- Normal: single fill, no overflow
      local wPct = math.max(0, math.min(100, pctInt))
      g.fill:resize(wPct.."%", nil)
      g.fill:setStyleSheet(string.format(
        "background-color: %s; border-radius: 2px;", g.fgColor))
      g.overflow:hide()
      g.marker:hide()
    else
      -- Overflow: base fill to 100% mark, overflow fill beyond
      -- Scale: total bar = cur, so 100% mark is at (max/cur) of bar width
      local basePct = math.floor(max / cur * 100)  -- where 100% mark falls
      local overW   = 100 - basePct                 -- overflow portion width

      -- Base fill: from 0 to basePct (normal color)
      g.fill:resize(basePct.."%", nil)
      g.fill:setStyleSheet(string.format(
        "background-color: %s; border-radius: 2px 0px 0px 2px;", g.fgColor))

      -- Overflow fill: brighter color from basePct to 100%
      g.overflow:move(basePct.."%", 0)
      g.overflow:resize(overW.."%", nil)
      -- Lighten the color for overflow portion
      local r, gr, b = g.fgColor:match("#(%x%x)(%x%x)(%x%x)")
      if r then
        r = math.min(255, tonumber(r, 16) + 60)
        gr = math.min(255, tonumber(gr, 16) + 60)
        b = math.min(255, tonumber(b, 16) + 60)
        g.overflow:setStyleSheet(string.format(
          "background-color: rgb(%d,%d,%d); border-radius: 0px 2px 2px 0px;", r, gr, b))
      end
      g.overflow:show()

      -- 100% marker line at basePct
      g.marker:move(basePct.."%", 0)
      g.marker:show()
    end

    local txt = string.format("%s %d/%d (%d%%)", label, cur, max, pctInt)
    if suffix and suffix ~= "" then txt = txt .. " " .. suffix end
    l:echo(span(TEXT, txt))
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
    WuxiaGUI3.foodGauge:setValue(fc, fm)
    WuxiaGUI3.foodLbl:echo(span(C_FOOD[1], string.format("食 %d/%d", fc, fm)))
  end
  if WuxiaGUI3.waterGauge then
    local wc, wm = v.water or 0, v.max_water or 300
    WuxiaGUI3.waterGauge:setValue(wc, wm)
    WuxiaGUI3.waterLbl:echo(span(C_WATER[1], string.format("水 %d/%d", wc, wm)))
  end

  -- Craze / Pinghe
  if WuxiaGUI3.crazeLbl then
    local craze = tonumber(v.craze) or 0
    if craze > 0 then
      local maxc = tonumber(v.max_craze) or 1
      WuxiaGUI3.crazeLbl:echo(
        span("#cc4444", string.format("【憤怒】%d/%d", craze, maxc)))
    else
      WuxiaGUI3.crazeLbl:echo(span(TEXT_DIM, "【平和】————————————"))
    end
  end

  -- Experience block
  if WuxiaGUI3.expBlock then
    WuxiaGUI3.expBlock:echo(
      kv("潛能", fmtNum(v.potential)) .. "<br>" ..
      kv("體會", fmtNum(v.experience)) .. "<br>" ..
      kv("經驗", fmtNum(v.combat_exp))
    )
  end

  -- Identity block
  if WuxiaGUI3.identityBlock then
    local name = s.name or ""
    local title = s.title or ""
    local lvl = s.level or 1
    local guild = s.guild or ""
    WuxiaGUI3.identityBlock:echo(
      span(GOLD, "<b>" .. name .. "</b>") .. "<br>" ..
      span(TEXT_DIM, title) .. "<br>" ..
      kv("等級", lvl) .. " " .. kv("武功", s.wugong_level or 1) .. "<br>" ..
      kv("能力", s.ability or 0) .. " " .. kv("成就", s.achievement or 0) .. "<br>" ..
      kv("活躍", s.active or 0)
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
function WuxiaGUI3._refreshAttributes()
  local s = WuxiaGUI3.status

  -- Attribute grid (2 columns)
  if WuxiaGUI3.attrGrid then
    local str = tonumber(s.str) or 0
    local int_ = tonumber(s.int_) or 0
    local con = tonumber(s.con) or 0
    local dex = tonumber(s.dex) or 0
    local per = tonumber(s.per) or 0
    local kar = tonumber(s.kar) or 0

    WuxiaGUI3.attrGrid:echo(
      kv("膂力", str) .. "&nbsp;&nbsp;&nbsp;&nbsp;" .. kv("悟性", int_) .. "<br>" ..
      kv("根骨", con) .. "&nbsp;&nbsp;&nbsp;&nbsp;" .. kv("身法", dex) .. "<br>" ..
      kv("容貌", per) .. "&nbsp;&nbsp;&nbsp;&nbsp;" .. kv("福緣", kar)
    )
  end

  -- Level block
  if WuxiaGUI3.levelBlock then
    WuxiaGUI3.levelBlock:echo(
      kv("當前等級", s.level or 1) .. "<br>" ..
      kv("武功等級", s.wugong_level or 1) .. "<br>" ..
      kv("升級所需", fmtNum(s.next_level or 0)) .. "<br>" ..
      kv("戰鬥經驗", fmtNum(s.combat_exp or 0))
    )
  end

  -- Limits block
  if WuxiaGUI3.limitsBlock then
    WuxiaGUI3.limitsBlock:echo(
      kv("精力上限", fmtNum(s.jingli_limit or 0)) .. "<br>" ..
      kv("內力上限", fmtNum(s.neili_limit or 0)) .. "<br>" ..
      kv("潛能上限", fmtNum(s.potential_limit or 0)) .. "<br>" ..
      kv("體會上限", fmtNum(s.experience_limit or 0))
    )
  end

  -- Special block (bloodline, yuanshen)
  if WuxiaGUI3.specialBlock then
    WuxiaGUI3.specialBlock:echo(
      kv("血脈等級", s.xuemai_level or 0) .. "<br>" ..
      kv("元神等級", s.yuanshen_level or 0) .. "<br>" ..
      kv("能力點數", s.ability or 0) .. " " ..
      kv("成就點數", s.achievement or 0)
    )
  end

  -- Bonus stats (from Char.Buffs GMCP — raw sources, client-side computed)
  WuxiaGUI3._refreshBonusStats()
end

-- ─── Bonus stats renderer ───
function WuxiaGUI3._refreshBonusStats()
  local b = WuxiaGUI3.buffs
  if not b then return end
  local hasData = (b.skillmix ~= nil or b.jingmai ~= nil or b.talent ~= nil)
  if not hasData then
    if WuxiaGUI3.bonusStatsInfo then
      WuxiaGUI3.bonusStatsInfo:echo(span(TEXT_DIM, "等待資料..."))
    end
    if WuxiaGUI3.bonusStatsList then
      WuxiaGUI3.bonusStatsList:echo(span(TEXT_DIM, "連線後自動更新"))
    end
    return
  end

  local filter = WuxiaGUI3._buffsActiveFilter or "all"

  -- Read value for a key from the active filter source
  -- "equipment" source comes from inventory data
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

  local lines = {}
  local function add(s) lines[#lines+1] = s end

  add(hdr("天賦加成"))
  add(row2("臂力", colorVal(val("str"), 2000), "悟性", colorVal(val("int"), 2000)))
  add(row2("根骨", colorVal(val("con"), 2000), "身法", colorVal(val("dex"), 2000)))

  add(hdr("上限加成"))
  add(row2("潛能", colorVal(val("max_potential"), 10000000), "體會", colorVal(val("max_experience"), 10000000)))
  add(row2("內力", colorVal(val("max_neili"), 2000000), "精力", colorVal(val("max_jingli"), 1000000)))
  add(row2("氣血", colorVal(val("max_qi"), 2000000), "精氣", colorVal(val("max_jing"), 1000000)))

  add(hdr("練功加成"))
  add(row2("研究次", colorVal(val("research_times"), 2000), "研究效", colorPct(val("research_effect"), "2000%")))
  add(row2("練習次", colorVal(val("practice_times"), 2000), "練習效", colorPct(val("practice_effect"), "2000%")))
  add(row2("學習次", colorVal(val("learn_times"), 2000), "學習效", colorPct(val("learn_effect"), "2000%")))
  add(row2("汲取消", colorVal(val("derive_times"), 2000), "汲取效", colorPct(val("derive_effect"), "2000%")))

  add(hdr("五行加成", "#cc4444"))
  for _, e in ipairs({
    {"毒","add_poison","reduce_poison"}, {"魔","add_magic","reduce_magic"},
    {"金","add_metal","reduce_metal"},   {"木","add_wood","reduce_wood"},
    {"水","add_water","reduce_water"},   {"火","add_fire","reduce_fire"},
    {"土","add_earth","reduce_earth"},
  }) do
    add(row2(e[1].."傷", colorPct(val(e[2]), "100%"), "抗"..e[1], colorPct(val(e[3]), "100%")))
  end

  add(hdr("狀態恢復", "#5588cc"))
  add(row2("偷內力", colorPct(val("leech_neili"), "90%"), "偷生命", colorPct(val("leech_qi"), "90%")))

  add(hdr("戰鬥加成"))
  add(row2("攻擊", colorVal(val("attack"), 9000), "防禦", colorVal(val("defense"), 9000)))
  add(row2("躲閃", colorVal(val("dodge"), 9000), "招架", colorVal(val("parry"), 9000)))
  add(row2("絕命中", colorPct(val("ap_power"), "120%"), "絕防禦", colorPct(val("dp_power"), "120%")))
  add(row2("兵傷害", colorVal(val("damage"), 200000), "拳傷害", colorVal(val("unarmed_damage"), 200000)))
  add(row2("絕傷害", colorPct(val("da_power"), "120%"), "戰保護", colorVal(val("armor"), 200000)))
  add(row2("忽招架", colorPct(val("avoid_parry"), "90%"), "忽躲閃", colorPct(val("avoid_dodge"), "90%")))
  add(row2("忽特攻", colorPct(val("avoid_attack"), "90%"), "忽內防", colorPct(val("avoid_force"), "90%")))

  add(hdr("高級屬性", "#aa55cc"))
  add(row2("化忙亂", colorVal(val("reduce_busy"), 90), "尋寶率", colorPct(val("magic_find"), "300%")))
  add(row2("雙傷害", colorPct(val("double_damage"), "200%"), "傷轉內", colorPct(val("qi_abs_neili"), "90%")))
  add(row2("致  盲", colorPct(val("add_blind"), "90%"), "忽致盲", colorPct(val("avoid_blind"), "90%")))
  add(row2("穿破甲", colorPct(val("through_armor"), "90%"), "百毒侵", colorPct(val("avoid_poison"), "100%")))
  add(span(TEXT_DIM, "戰神 ") .. colorPct(val("full_self"), "90%"))

  add(hdr("終極屬性", "#ccaa33"))
  add(row2("冰  凍", colorPct(val("add_freeze"), "90%"), "忽冰凍", colorPct(val("avoid_freeze"), "90%")))
  add(row2("遺  忘", colorPct(val("add_forget"), "90%"), "忽遺忘", colorPct(val("avoid_forget"), "90%")))
  add(row2("忙  亂", colorVal(val("add_busy"), 90), "忽忙亂", colorPct(val("avoid_busy"), "90%")))
  add(row2("虛  弱", colorPct(val("add_weak"), "90%"), "忽虛弱", colorPct(val("avoid_weak"), "90%")))
  add(row2("追傷害", colorPct(val("add_damage"), "200%"), "化傷害", colorPct(val("reduce_damage"), "90%")))
  add(row2("反  噬", colorPct(val("counter_damage"), "90%"), "浴重生", colorPct(val("avoid_die"), "90%")))
  add(row2("致命擊", colorPct(val("fatal_blow"), "90%"), "提技能", colorVal(val("add_skill"), 1200)))

  if WuxiaGUI3.bonusStatsInfo then
    local srcNames = {
      all = "總計", equipment = "裝備", skillmix = "技能組合",
      jingmai = "經脈", yuanshen = "元神",
      ability = "能力進階", talent = "天賦", temp = "暫時",
    }
    WuxiaGUI3.bonusStatsInfo:echo(
      span(TEXT_DIM, "附加屬性 ") .. span(GOLD, srcNames[filter] or filter))
  end
  if WuxiaGUI3.bonusStatsList then
    WuxiaGUI3.bonusStatsList:echo(table.concat(lines, "<br>"))
  end
end

-- ─── 技能 refresh ───
function WuxiaGUI3._refreshSkills()
  local s = WuxiaGUI3.status
  local mapping = {
    sk_force   = "force",
    sk_dodge   = "dodge",
    sk_parry   = "parry",
    sk_unarmed = "unarmed",
    sk_sword   = "sword",
    sk_blade   = "blade",
    sk_staff   = "staff",
    sk_whip    = "whip",
    sk_throw   = "throwing",
    sk_shoot   = "shooting",
    sk_lit     = "literate",
    sk_martial = "martial-arts",
  }

  for _, sk in ipairs(WuxiaGUI3._skillList or {}) do
    local g = WuxiaGUI3[sk.id.."Gauge"]
    local l = WuxiaGUI3[sk.id.."Lbl"]
    if g and l then
      local key = mapping[sk.id]
      local val = tonumber(s[key]) or 0
      -- Max skill is roughly 1000 for display purposes
      -- Adjust if your game uses different caps
      local displayMax = math.max(val, 500)
      g:setValue(val, displayMax)

      local color = val > 0 and TEXT or TEXT_DIM
      l:echo(span(color, string.format("%s %d", sk.label, val)))
    end
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

  -- Talent list
  if WuxiaGUI3.talentList then
    if not t or not t.talents then
      WuxiaGUI3.talentList:echo(
        span(TEXT_DIM, "輸入 ") .. span(GOLD, "talent") ..
        span(TEXT_DIM, " 或等待 GMCP 資料"))
      return
    end

    local lines = {}
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

      -- Group separator every 3 talents (matches yuanshen gating)
      if i > 1 and (i - 1) % 3 == 0 then
        local tierNum = math.floor((i - 1) / 3)
        lines[#lines+1] = span(GOLD, string.format(
          "── 第%d階 (元神Lv%d) ──", tierNum + 1, tierNum * 10))
      end

      -- Index number
      local idxColor = locked and TEXT_DIM or WHITE
      local idxStr = span(idxColor, string.format("(%2d)", idx))

      -- Name — colored by state
      local nameColor
      if locked then
        nameColor = TEXT_DIM
      elseif level >= maxLv then
        nameColor = GOLD  -- maxed out
      elseif level > 0 then
        nameColor = "#55cc55"  -- partially trained
      else
        nameColor = TEXT  -- available but untrained
      end
      local nameStr = span(nameColor, name)

      -- Level display with mini text-bar
      local lvStr
      if locked then
        lvStr = span(TEXT_DIM, "🔒")
      else
        local filled = ""
        local empty = ""
        for j = 1, maxLv do
          if j <= level then
            filled = filled .. "■"
          else
            empty = empty .. "□"
          end
        end
        lvStr = span("#55cc55", filled) .. span(TEXT_DIM, empty) ..
                " " .. span(WHITE, tostring(level)) ..
                span(TEXT_DIM, "/" .. tostring(maxLv))
      end

      -- Value/effect description
      local effectStr
      if locked then
        effectStr = span(TEXT_DIM, desc)
      else
        if value > 0 then
          effectStr = span("#5588cc", "+" .. tostring(value)) ..
                      span(TEXT_DIM, " ") .. span(TEXT, desc)
        else
          effectStr = span(TEXT_DIM, desc)
        end
      end

      -- Upgrade hint
      local upgradeStr = ""
      if not locked and level < maxLv then
        upgradeStr = " " .. span("#aaaa55",
          "[+" .. tostring(perLv) .. "]")
      elseif not locked and level >= maxLv then
        upgradeStr = " " .. span(GOLD, "✓")
      end

      -- Compose the full row
      lines[#lines+1] = idxStr .. " " .. nameStr ..
                         "&nbsp;&nbsp;" .. lvStr ..
                         upgradeStr ..
                         "<br>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;" ..
                         effectStr
    end

    -- Upgrade instructions at the bottom
    lines[#lines+1] = ""
    lines[#lines+1] = span(TEXT_DIM, "────────────────────")
    lines[#lines+1] = span(TEXT_DIM, "點擊 ") ..
                       span(GOLD, "talent + N") ..
                       span(TEXT_DIM, " 提高第N項天賦等級")

    WuxiaGUI3.talentList:echo(table.concat(lines, "<br>"))
  end
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
    }
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
