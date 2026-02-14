-- ╔═══════════════════════════════════════════════════════════════════╗
-- ║              武俠 MUD GUI v2.0 - Wuxia Interface               ║
-- ║              Chinese Kung Fu Style Mudlet Package               ║
-- ║                                                                 ║
-- ║  Layout:                                                        ║
-- ║  ┌──────────────────────────────────┬──────────────┐           ║
-- ║  │                                  │  Character   │           ║
-- ║  │       Primary Message Window     │   Sheet      │           ║
-- ║  │       (Main MUD Console)         │              │           ║
-- ║  │                                  ├──────────────┤           ║
-- ║  │                                  │   Quest      │           ║
-- ║  │                                  │   Sheet      │           ║
-- ║  ├──────────────────────────────────┴──────────────┤           ║
-- ║  │ Chat [全部] [閒聊] [幫派] [私訊] [系統]         │           ║
-- ║  │                                                  │           ║
-- ║  ├──────────────────────────────────────────────────┤           ║
-- ║  │ [Input - Mudlet native, untouched]               │           ║
-- ║  └──────────────────────────────────────────────────┘           ║
-- ║                                                                 ║
-- ║  GMCP-ready: WuxiaGUI.data is the single source of truth.      ║
-- ║  Call WuxiaGUI.refresh() after updating data to redraw.         ║
-- ╚═══════════════════════════════════════════════════════════════════╝

----------------------------------------------------------------------
-- § 0. NAMESPACE
----------------------------------------------------------------------
WuxiaGUI = WuxiaGUI or {}
WuxiaGUI.version = "2.0"

----------------------------------------------------------------------
-- § 1. THEME
----------------------------------------------------------------------
WuxiaGUI.theme = {
  -- Backgrounds
  bg          = "#0F0C0A",        -- deep ink
  bgPanel     = "#1E1914",        -- panel bg
  bgSection   = "#28221C",        -- section bg
  bgInput     = "#1A1510",        -- input area bg
  bgHover     = "#372F26",        -- hover

  -- Borders
  gold        = "#B49650",        -- antique gold
  goldDim     = "#64553C",        -- muted gold
  red         = "#A0281E",        -- seal red

  -- Text
  tGold       = "#C8A850",        -- gold labels
  tBright     = "#E8D8B0",        -- bright values
  tNormal     = "#B0A080",        -- body text
  tDim        = "#807060",        -- muted
  tRed        = "#D04040",
  tGreen      = "#50B050",
  tBlue       = "#5080D0",
  tCyan       = "#50B0B0",
  tYellow     = "#D0C050",
  tMagenta    = "#A064C8",

  -- Gauge pairs {front, back}
  gJing   = {"rgba(70,150,70,220)",  "rgba(35,60,35,150)"},
  gQi     = {"rgba(170,55,55,220)",  "rgba(55,28,28,150)"},
  gJingli = {"rgba(55,115,170,220)", "rgba(28,45,65,150)"},
  gNeili  = {"rgba(150,90,190,220)", "rgba(55,35,75,150)"},
  gFood   = {"rgba(170,140,55,220)", "rgba(65,55,28,150)"},
  gWater  = {"rgba(55,140,170,220)", "rgba(28,55,65,150)"},

  -- Tabs
  tabActive   = "#A0281E",        -- active tab bg
  tabInactive = "#28221C",        -- inactive tab bg
}

----------------------------------------------------------------------
-- § 2. LAYOUT DIMENSIONS (pixels, overridable)
----------------------------------------------------------------------
WuxiaGUI.layout = {
  rightW  = 300,    -- right panel width
  bottomH = 180,    -- chat panel height
  topH    = 0,      -- reserved for future toolbar
  leftW   = 0,      -- reserved for future map panel
  charSplitPct = 55, -- % of right panel for char sheet (rest = quest)
}

----------------------------------------------------------------------
-- § 3. DATA MODEL — single source of truth, GMCP fills this
----------------------------------------------------------------------
WuxiaGUI.data = WuxiaGUI.data or {
  -- Vitals (from hp / GMCP)
  jingqi  = {cur=0, max=0, pct=0},
  qixue   = {cur=0, max=0, pct=0},
  jingli  = {cur=0, max=0, regen=0},
  neili   = {cur=0, max=0, regen=0},
  food    = {cur=0, max=0},
  water   = {cur=0, max=0},
  pinghe  = "",
  qianneng = 0,
  tihui    = 0,
  jingyan  = 0,

  -- Identity (from score / GMCP)
  identity = {
    title = "", age = "", gender = "", personality = "",
    birthday = "", sect = "", master = "", gang = "",
    position = "", military = "", profession = "",
    yuanshen = "", residence = "", marriage = "",
    partner = "", children = "", sexuality = "",
    mount = "", bank = "", jianghu = "",
  },

  -- Combat
  combat = {attack=0, defense=0, damage=0, protection=0},

  -- Attributes
  attrs = {
    strength={cur=0,max=0}, perception={cur=0,max=0},
    constitution={cur=0,max=0}, agility={cur=0,max=0},
  },

  -- Skills
  skills = {unarmed="", weapon="", neigong="", qinggong=""},

  -- Extended stats
  stats = {
    exp=0, potential=0, zhengqi=0, tihui=0,
    gongji=0, linghui=0, weiwan=0, yueli=0,
    rongyu=0, liqi=0,
  },

  -- Mastery flags
  mastery = {
    wuxue=false, zhoutian=false, yuanying=false, shengsi=false,
  },

  -- Kill records
  kills = {
    total=0, player=0, murder=0, stun=0, good=0, evil=0,
    slaughter=0,
  },

  playtime = "",

  -- Quest data (stub for future)
  quests = {},
  activeQuest = nil,
}

----------------------------------------------------------------------
-- § 4. CSS HELPERS
----------------------------------------------------------------------
local T = WuxiaGUI.theme

local function css(props)
  local parts = {}
  for k,v in pairs(props) do
    parts[#parts+1] = k .. ": " .. v .. ";"
  end
  return table.concat(parts, " ")
end

local function panelCSS(extra)
  return css({
    ["background-color"] = T.bg,
    ["border"] = "0px",
  }) .. (extra or "")
end

local function sectionCSS()
  return css({
    ["background-color"] = T.bgSection,
    ["border"] = "1px solid " .. T.goldDim,
    ["border-radius"] = "3px",
    ["padding"] = "3px",
  })
end

local function gaugeCSS(fg, bg)
  local front = css({["background-color"]=fg, ["border-radius"]="2px"})
  local back = css({
    ["background-color"]=bg,
    ["border"]="1px solid " .. T.goldDim,
    ["border-radius"]="2px",
  })
  return front, back
end

----------------------------------------------------------------------
-- § 5. BUILD THE FULL LAYOUT
----------------------------------------------------------------------
function WuxiaGUI.setup()
  WuxiaGUI.teardown()

  local L = WuxiaGUI.layout

  -- Push main console borders to make room
  setBorderRight(L.rightW)
  setBorderBottom(L.bottomH)
  setBorderTop(L.topH)
  setBorderLeft(L.leftW)

  -- ── Right Panel (Character + Quest) ──
  WuxiaGUI.rightPanel = Geyser.Container:new({
    name = "WGUI.right",
    x = "-"..L.rightW.."px", y = 0,
    width = L.rightW, height = "-"..L.bottomH.."px",
  })

  local splitY = L.charSplitPct .. "%"
  local questY = (100 - L.charSplitPct) .. "%"

  -- Character Sheet area (top portion of right panel)
  WuxiaGUI.charContainer = Geyser.Container:new({
    name = "WGUI.char", x = 0, y = 0,
    width = "100%", height = splitY,
  }, WuxiaGUI.rightPanel)

  -- Quest Sheet area (bottom portion of right panel)
  WuxiaGUI.questContainer = Geyser.Container:new({
    name = "WGUI.quest", x = 0, y = splitY,
    width = "100%", height = questY,
  }, WuxiaGUI.rightPanel)

  -- ── Bottom Panel (Chat) ──
  WuxiaGUI.bottomPanel = Geyser.Container:new({
    name = "WGUI.bottom",
    x = 0, y = "-"..L.bottomH.."px",
    width = "100%", height = L.bottomH,
  })

  -- Build each section
  WuxiaGUI._buildCharSheet()
  WuxiaGUI._buildQuestSheet()
  WuxiaGUI._buildChat()

  WuxiaGUI.initialized = true
  WuxiaGUI.refresh()

  -- Handle window resize
  if WuxiaGUI._resizeHandler then
    killAnonymousEventHandler(WuxiaGUI._resizeHandler)
  end
  WuxiaGUI._resizeHandler = registerAnonymousEventHandler(
    "sysWindowResizeEvent", "WuxiaGUI._onResize")
end

function WuxiaGUI._onResize()
  -- borders stay fixed, Geyser handles the rest
  local L = WuxiaGUI.layout
  setBorderRight(L.rightW)
  setBorderBottom(L.bottomH)
end

function WuxiaGUI.teardown()
  if WuxiaGUI.rightPanel then WuxiaGUI.rightPanel:hide() end
  if WuxiaGUI.bottomPanel then WuxiaGUI.bottomPanel:hide() end
  WuxiaGUI.rightPanel = nil
  WuxiaGUI.bottomPanel = nil
  WuxiaGUI.initialized = false
  setBorderRight(0) setBorderBottom(0)
end

----------------------------------------------------------------------
-- § 6. CHARACTER SHEET
----------------------------------------------------------------------
function WuxiaGUI._buildCharSheet()
  local c = WuxiaGUI.charContainer

  -- Background
  WuxiaGUI.charBg = Geyser.Label:new({
    name="WGUI.charBg", x=0, y=0, width="100%", height="100%",
  }, c)
  WuxiaGUI.charBg:setStyleSheet(css({
    ["background-color"] = T.bg,
    ["border-left"] = "2px solid "..T.gold,
    ["border-bottom"] = "1px solid "..T.goldDim,
  }))

  -- Header
  WuxiaGUI.charHeader = Geyser.Label:new({
    name="WGUI.charHeader", x=0, y=0, width="100%", height="28px",
  }, c)
  WuxiaGUI.charHeader:setStyleSheet(css({
    ["background-color"] = T.red,
    ["border-bottom"] = "1px solid "..T.gold,
    ["qproperty-alignment"] = "'AlignCenter'",
  }))
  WuxiaGUI.charHeader:setFontSize(11)
  WuxiaGUI.charHeader:echo(
    "<center><font color='"..T.tGold.."'>╋ 人 物 ╋</font></center>")
  WuxiaGUI.charHeader:setClickCallback("WuxiaGUI._toggleCharMode")

  -- Scrollable content area
  WuxiaGUI.charScroll = Geyser.Label:new({
    name="WGUI.charScroll", x=0, y="28px",
    width="100%", height="-28px",
  }, c)
  WuxiaGUI.charScroll:setStyleSheet("background-color: "..T.bg..";")

  -- We use an inner container for the gauge/label layout
  WuxiaGUI.charInner = Geyser.Container:new({
    name="WGUI.charInner", x="4px", y="4px",
    width="-8px", height="-8px",
  }, WuxiaGUI.charScroll)

  -- Build gauge rows inside charInner
  WuxiaGUI._buildVitals()

  -- State: 'compact' or 'detail'
  WuxiaGUI.charMode = WuxiaGUI.charMode or "compact"
end

function WuxiaGUI._buildVitals()
  local ci = WuxiaGUI.charInner
  local y = 0
  local rowH = 32  -- label(14) + gauge(14) + gap(4)
  local lblH = 13
  local barH = 13
  local gap = 4

  local function mkGauge(id, label, gCol, yPos)
    local lbl = Geyser.Label:new({
      name="WGUI.v."..id..".lbl", x=0, y=yPos.."px",
      width="100%", height=lblH.."px",
    }, ci)
    lbl:setStyleSheet("background-color: transparent;")
    lbl:setFontSize(9)

    local g = Geyser.Gauge:new({
      name="WGUI.v."..id..".g", x=0, y=(yPos+lblH).."px",
      width="100%", height=barH.."px",
    }, ci)
    local f, b = gaugeCSS(gCol[1], gCol[2])
    g:setStyleSheet(f, b)

    return {label=lbl, gauge=g}
  end

  WuxiaGUI.vJingqi  = mkGauge("jingqi",  "精氣", T.gJing,   y); y=y+rowH
  WuxiaGUI.vQixue   = mkGauge("qixue",   "氣血", T.gQi,     y); y=y+rowH
  y = y + 2  -- extra spacer between vital pairs
  WuxiaGUI.vJingli  = mkGauge("jingli",  "精力", T.gJingli, y); y=y+rowH
  WuxiaGUI.vNeili   = mkGauge("neili",   "內力", T.gNeili,  y); y=y+rowH
  y = y + 4

  -- Separator
  WuxiaGUI.charSep1 = Geyser.Label:new({
    name="WGUI.charSep1", x=0, y=y.."px", width="100%", height="1px",
  }, ci)
  WuxiaGUI.charSep1:setStyleSheet("background-color:"..T.goldDim..";")
  y = y + 6

  -- Food + Water (side by side, smaller)
  WuxiaGUI.vFood = Geyser.Gauge:new({
    name="WGUI.v.food.g", x=0, y=y.."px",
    width="48%", height="10px",
  }, ci)
  do local f,b = gaugeCSS(T.gFood[1], T.gFood[2])
    WuxiaGUI.vFood:setStyleSheet(f, b) end

  WuxiaGUI.vWater = Geyser.Gauge:new({
    name="WGUI.v.water.g", x="52%", y=y.."px",
    width="48%", height="10px",
  }, ci)
  do local f,b = gaugeCSS(T.gWater[1], T.gWater[2])
    WuxiaGUI.vWater:setStyleSheet(f, b) end
  y = y + 14

  -- Food/Water labels
  WuxiaGUI.foodWaterLbl = Geyser.Label:new({
    name="WGUI.v.fw.lbl", x=0, y=y.."px",
    width="100%", height="13px",
  }, ci)
  WuxiaGUI.foodWaterLbl:setStyleSheet("background-color:transparent;")
  WuxiaGUI.foodWaterLbl:setFontSize(8)
  y = y + 16

  -- Pinghe bar
  WuxiaGUI.pingheLbl = Geyser.Label:new({
    name="WGUI.v.pinghe", x=0, y=y.."px",
    width="100%", height="13px",
  }, ci)
  WuxiaGUI.pingheLbl:setStyleSheet("background-color:transparent;")
  WuxiaGUI.pingheLbl:setFontSize(8)
  y = y + 16

  -- Separator
  WuxiaGUI.charSep2 = Geyser.Label:new({
    name="WGUI.charSep2", x=0, y=y.."px", width="100%", height="1px",
  }, ci)
  WuxiaGUI.charSep2:setStyleSheet("background-color:"..T.goldDim..";")
  y = y + 6

  -- Stats summary box
  WuxiaGUI.statsBox = Geyser.Label:new({
    name="WGUI.v.stats", x=0, y=y.."px",
    width="100%", height="48px",
  }, ci)
  WuxiaGUI.statsBox:setStyleSheet(sectionCSS())
  WuxiaGUI.statsBox:setFontSize(9)
  y = y + 54

  -- Detail mini-console (shown in detail mode)
  WuxiaGUI.detailCon = Geyser.MiniConsole:new({
    name="WGUI.detailCon", x=0, y=y.."px",
    width="100%", height="300px",
    fontSize=8, autoWrap=true, scrollBar=false,
  }, ci)
  WuxiaGUI.detailCon:setColor(15, 12, 10)
  WuxiaGUI.detailCon:setFontSize(8)
  WuxiaGUI.detailCon:hide()
end

----------------------------------------------------------------------
-- § 7. QUEST SHEET (stub - expandable later)
----------------------------------------------------------------------
function WuxiaGUI._buildQuestSheet()
  local q = WuxiaGUI.questContainer

  WuxiaGUI.questBg = Geyser.Label:new({
    name="WGUI.questBg", x=0, y=0, width="100%", height="100%",
  }, q)
  WuxiaGUI.questBg:setStyleSheet(css({
    ["background-color"] = T.bg,
    ["border-left"] = "2px solid "..T.gold,
  }))

  WuxiaGUI.questHeader = Geyser.Label:new({
    name="WGUI.questHeader", x=0, y=0, width="100%", height="24px",
  }, q)
  WuxiaGUI.questHeader:setStyleSheet(css({
    ["background-color"] = T.bgSection,
    ["border-bottom"] = "1px solid "..T.goldDim,
    ["border-left"] = "2px solid "..T.gold,
    ["qproperty-alignment"] = "'AlignCenter'",
  }))
  WuxiaGUI.questHeader:setFontSize(10)
  WuxiaGUI.questHeader:echo(
    "<center><font color='"..T.tGold.."'>╋ 任 務 ╋</font></center>")

  WuxiaGUI.questBody = Geyser.MiniConsole:new({
    name="WGUI.questBody", x="4px", y="28px",
    width="-8px", height="-32px",
    fontSize=9, autoWrap=true, scrollBar=true,
  }, q)
  WuxiaGUI.questBody:setColor(15, 12, 10)
  WuxiaGUI.questBody:setFontSize(9)
  WuxiaGUI.questBody:cecho("<DimGrey>尚無任務資訊。\n輸入 quest 或等待 GMCP 推送。<reset>\n")
end

----------------------------------------------------------------------
-- § 8. CHAT PANEL (tabbed, hand-rolled for theme control)
----------------------------------------------------------------------
WuxiaGUI.chatTabs = {"全部", "閒聊", "幫派", "私訊", "系統"}
WuxiaGUI.chatActive = WuxiaGUI.chatActive or "全部"

function WuxiaGUI._buildChat()
  local bp = WuxiaGUI.bottomPanel

  -- Background
  WuxiaGUI.chatBg = Geyser.Label:new({
    name="WGUI.chatBg", x=0, y=0, width="100%", height="100%",
  }, bp)
  WuxiaGUI.chatBg:setStyleSheet(css({
    ["background-color"] = T.bg,
    ["border-top"] = "2px solid "..T.gold,
  }))

  -- Tab bar
  WuxiaGUI.tabBar = Geyser.HBox:new({
    name="WGUI.tabBar", x=0, y=0,
    width="100%", height="22px",
  }, bp)

  WuxiaGUI.tabButtons = {}
  for _, tabName in ipairs(WuxiaGUI.chatTabs) do
    local btn = Geyser.Label:new({
      name="WGUI.tab."..tabName,
    }, WuxiaGUI.tabBar)
    btn:setFontSize(9)
    btn:setClickCallback("WuxiaGUI._switchChatTab", tabName)
    WuxiaGUI.tabButtons[tabName] = btn
  end

  -- Console area (one miniconsole per tab, stacked)
  WuxiaGUI.chatConsoles = {}
  for _, tabName in ipairs(WuxiaGUI.chatTabs) do
    local con = Geyser.MiniConsole:new({
      name="WGUI.chat."..tabName,
      x="4px", y="24px", width="-8px", height="-28px",
      fontSize=9, autoWrap=true, scrollBar=true,
    }, bp)
    con:setColor(15, 12, 10)
    con:setFontSize(9)
    con:hide()
    WuxiaGUI.chatConsoles[tabName] = con
  end

  WuxiaGUI._switchChatTab(WuxiaGUI.chatActive)
end

function WuxiaGUI._switchChatTab(tab)
  WuxiaGUI.chatActive = tab
  for _, name in ipairs(WuxiaGUI.chatTabs) do
    local btn = WuxiaGUI.tabButtons[name]
    local con = WuxiaGUI.chatConsoles[name]
    if name == tab then
      btn:setStyleSheet(css({
        ["background-color"] = T.tabActive,
        ["border-bottom"] = "2px solid "..T.gold,
        ["qproperty-alignment"] = "'AlignCenter'",
      }))
      btn:echo("<center><font color='"..T.tGold.."'>"..name.."</font></center>")
      con:show()
    else
      btn:setStyleSheet(css({
        ["background-color"] = T.tabInactive,
        ["border-bottom"] = "1px solid "..T.goldDim,
        ["qproperty-alignment"] = "'AlignCenter'",
      }))
      btn:echo("<center><font color='"..T.tDim.."'>"..name.."</font></center>")
      con:hide()
    end
  end
end

-- Public API: echo to a chat tab (and optionally mirror to 全部)
function WuxiaGUI.chat(tabName, text, mirror)
  if not WuxiaGUI.chatConsoles then return end
  local con = WuxiaGUI.chatConsoles[tabName]
  if con then con:cecho(text.."\n") end
  if mirror ~= false and tabName ~= "全部" then
    local all = WuxiaGUI.chatConsoles["全部"]
    if all then all:cecho(text.."\n") end
  end
end

-- Public API: append current MUD line to a chat tab
function WuxiaGUI.chatAppend(tabName, mirror)
  if not WuxiaGUI.chatConsoles then return end
  local con = WuxiaGUI.chatConsoles[tabName]
  if con then
    selectCurrentLine()
    copy()
    appendBuffer("WGUI.chat."..tabName)
    if mirror ~= false and tabName ~= "全部" then
      appendBuffer("WGUI.chat.全部")
    end
    deselect()
    resetFormat()
  end
end

----------------------------------------------------------------------
-- § 9. REFRESH / RENDER (call after data changes)
----------------------------------------------------------------------
function WuxiaGUI.refresh()
  if not WuxiaGUI.initialized then return end
  WuxiaGUI._renderVitals()
  if WuxiaGUI.charMode == "detail" then
    WuxiaGUI._renderDetail()
  end
end

function WuxiaGUI._renderVitals()
  local d = WuxiaGUI.data
  local g = T.tGold
  local b = T.tBright

  -- Helper: update one gauge row
  local function upd(widget, label, cur, max, extra)
    local extraStr = extra or ""
    widget.label:echo(string.format(
      "<font color='%s' size='2'>%s</font> <font color='%s' size='2'>%d/%d %s</font>",
      g, label, b, cur, max, extraStr))
    if max > 0 then widget.gauge:setValue(cur, max) end
  end

  upd(WuxiaGUI.vJingqi,  "【精氣】", d.jingqi.cur, d.jingqi.max,
      string.format("(%d%%)", d.jingqi.pct))
  upd(WuxiaGUI.vQixue,   "【氣血】", d.qixue.cur, d.qixue.max,
      string.format("(%d%%)", d.qixue.pct))
  upd(WuxiaGUI.vJingli,  "【精力】", d.jingli.cur, d.jingli.max,
      string.format("(%+d)", d.jingli.regen))
  upd(WuxiaGUI.vNeili,   "【內力】", d.neili.cur, d.neili.max,
      string.format("(%+d)", d.neili.regen))

  -- Food + Water gauges
  if d.food.max > 0 then WuxiaGUI.vFood:setValue(d.food.cur, d.food.max) end
  if d.water.max > 0 then WuxiaGUI.vWater:setValue(d.water.cur, d.water.max) end
  WuxiaGUI.foodWaterLbl:echo(string.format(
    "<font color='%s' size='2'>食 %d/%d</font>  <font color='%s' size='2'>水 %d/%d</font>",
    g, d.food.cur, d.food.max, T.tCyan, d.water.cur, d.water.max))

  -- Pinghe
  local ph = d.pinghe ~= "" and d.pinghe or "————————————"
  WuxiaGUI.pingheLbl:echo(string.format(
    "<font color='%s' size='2'>【平和】%s</font>", g, ph))

  -- Stats
  WuxiaGUI.statsBox:echo(string.format(
    "<font color='%s' size='2'>潛能</font> <font color='%s' size='2'>%s</font>"..
    "  <font color='%s' size='2'>體會</font> <font color='%s' size='2'>%s</font><br>"..
    "<font color='%s' size='2'>經驗</font> <font color='%s' size='2'>%s</font>",
    g, b, WuxiaGUI.formatNumber(d.qianneng),
    g, b, WuxiaGUI.formatNumber(d.tihui),
    g, T.tYellow, WuxiaGUI.formatNumber(d.jingyan)))
end

----------------------------------------------------------------------
-- § 10. DETAIL VIEW (expanded score info in miniconsole)
----------------------------------------------------------------------
function WuxiaGUI._toggleCharMode()
  if WuxiaGUI.charMode == "compact" then
    WuxiaGUI.charMode = "detail"
    WuxiaGUI.detailCon:show()
    WuxiaGUI.charHeader:echo(
      "<center><font color='"..T.tGold.."'>╋ 人 物 ╋ ▲</font></center>")
    WuxiaGUI._renderDetail()
  else
    WuxiaGUI.charMode = "compact"
    WuxiaGUI.detailCon:hide()
    WuxiaGUI.charHeader:echo(
      "<center><font color='"..T.tGold.."'>╋ 人 物 ╋</font></center>")
  end
end

function WuxiaGUI._renderDetail()
  local con = WuxiaGUI.detailCon
  if not con then return end
  con:clear()

  local d = WuxiaGUI.data
  local id = d.identity
  local cb = d.combat
  local at = d.attrs
  local sk = d.skills
  local st = d.stats
  local ms = d.mastery
  local kl = d.kills
  local fmt = WuxiaGUI.formatNumber

  local function w(t) con:cecho(t.."\n") end

  w("")
  if id.title ~= "" then w(" <gold>【天神】<reset>"..id.title) end
  w("")

  -- Two-column info
  local info = {
    {"年齡", id.age,       "攻擊", cb.attack},
    {"性別", id.gender,     "防禦", cb.defense},
    {"性格", id.personality, "傷害", cb.damage},
    {"生辰", id.birthday,   "保護", cb.protection},
  }
  for _, r in ipairs(info) do
    w(string.format(" <gold>【%s】<reset>%s", r[1], r[2]))
    w(string.format("           <gold>【%s】<reset>%s", r[3], tostring(r[4])))
  end

  w("")
  local fields = {
    {"門派", id.sect},   {"師承", id.master},
    {"幫派", id.gang},   {"職務", id.position},
    {"住宅", id.residence}, {"婚姻", id.marriage},
    {"江湖", id.jianghu},
  }
  for _, f in ipairs(fields) do
    w(string.format(" <gold>【%s】<reset>%s", f[1], f[2]))
  end

  w("")
  w(" <gold>─── 屬性 ───<reset>")
  w(string.format(" <gold>膂力<reset> %d/%d  <gold>悟性<reset> %d/%d",
    at.strength.cur, at.strength.max, at.perception.cur, at.perception.max))
  w(string.format(" <gold>根骨<reset> %d/%d  <gold>身法<reset> %d/%d",
    at.constitution.cur, at.constitution.max, at.agility.cur, at.agility.max))
  w(string.format(" <gold>拳腳<reset> %s    <gold>兵器<reset> %s", sk.unarmed, sk.weapon))
  w(string.format(" <gold>內功<reset> %s    <gold>輕功<reset> %s", sk.neigong, sk.qinggong))

  w("")
  w(" <gold>─── 數值 ───<reset>")
  w(string.format(" 經驗 <yellow>%s<reset>  潛能 %s", fmt(st.exp), fmt(st.potential)))
  w(string.format(" 正氣 %s  功績 %s", fmt(st.zhengqi), fmt(st.gongji)))
  w(string.format(" 威望 %s  榮譽 %s", fmt(st.weiwan), fmt(st.rongyu)))

  w("")
  local ck = function(v) return v and "<green>✓<reset>" or "<red>×<reset>" end
  w(string.format(" 武學宗師%s 大小周天%s 元嬰出世%s 生死玄關%s",
    ck(ms.wuxue), ck(ms.zhoutian), ck(ms.yuanying), ck(ms.shengsi)))

  if kl.total > 0 or kl.slaughter > 0 then
    w("")
    w(string.format(" 殺生 %d  殺玩家 %d  殺戮值 <yellow>%d<reset>",
      kl.total, kl.player, kl.slaughter))
  end

  if d.playtime ~= "" then
    w("")
    w(" <DimGrey>遊戲時間："..d.playtime.."<reset>")
  end
end

----------------------------------------------------------------------
-- § 11. UTILITY
----------------------------------------------------------------------
function WuxiaGUI.formatNumber(n)
  if type(n) ~= "number" then return tostring(n) end
  if n == 0 then return "0" end
  local s = tostring(math.floor(n))
  local f = s:reverse():gsub("(%d%d%d)", "%1,"):reverse()
  return f:sub(1,1) == "," and f:sub(2) or f
end

----------------------------------------------------------------------
-- § 12. TRIGGER REGISTRATION (text parsing fallback)
----------------------------------------------------------------------
function WuxiaGUI.registerTriggers()
  local function reg(name, patterns, code)
    if exists(name, "trigger") > 0 then killTrigger(name) end
    permRegexTrigger(name, "", patterns, code)
  end

  -- HP triggers
  reg("WGUI_HP1", {
    [[【 精 氣 】\s*(\d+)\s*/\s*(\d+)\s*\(\s*(\d+)%\)\s*【 精 力 】\s*(\d+)\s*/\s*(\d+)\s*\(([+-]?\d+)\)]]
  }, [[
    local d = WuxiaGUI.data
    d.jingqi.cur=tonumber(matches[2]) d.jingqi.max=tonumber(matches[3]) d.jingqi.pct=tonumber(matches[4])
    d.jingli.cur=tonumber(matches[5]) d.jingli.max=tonumber(matches[6]) d.jingli.regen=tonumber(matches[7])
    WuxiaGUI.refresh()
  ]])

  reg("WGUI_HP2", {
    [[【 氣 血 】\s*(\d+)\s*/\s*(\d+)\s*\(\s*(\d+)%\)\s*【 內 力 】\s*(\d+)\s*/\s*(\d+)\s*\(([+-]?\d+)\)]]
  }, [[
    local d = WuxiaGUI.data
    d.qixue.cur=tonumber(matches[2]) d.qixue.max=tonumber(matches[3]) d.qixue.pct=tonumber(matches[4])
    d.neili.cur=tonumber(matches[5]) d.neili.max=tonumber(matches[6]) d.neili.regen=tonumber(matches[7])
    WuxiaGUI.refresh()
  ]])

  reg("WGUI_HP3", {[[【 食 物 】\s*(\d+)\s*/\s*(\d+)\s*【 潛 能 】\s*(\d+)]]}, [[
    local d = WuxiaGUI.data
    d.food.cur=tonumber(matches[2]) d.food.max=tonumber(matches[3]) d.qianneng=tonumber(matches[4])
    WuxiaGUI.refresh()
  ]])

  reg("WGUI_HP4", {[[【 飲 水 】\s*(\d+)\s*/\s*(\d+)\s*【 體 會 】\s*(\d+)]]}, [[
    local d = WuxiaGUI.data
    d.water.cur=tonumber(matches[2]) d.water.max=tonumber(matches[3]) d.tihui=tonumber(matches[4])
    WuxiaGUI.refresh()
  ]])

  reg("WGUI_HP5", {[[【 平 和 】\s*(.-)\s*【 經 驗 】\s*(\d+)]]}, [[
    WuxiaGUI.data.pinghe=matches[2] WuxiaGUI.data.jingyan=tonumber(matches[3])
    WuxiaGUI.refresh()
  ]])

  echo("WGUI: HP 觸發器已註冊 ✓\n")
end

----------------------------------------------------------------------
-- § 13. ALIASES
----------------------------------------------------------------------
function WuxiaGUI.registerAliases()
  local function ali(name, pat, code)
    if exists(name, "alias") > 0 then killAlias(name) end
    permAlias(name, "", pat, code)
  end
  ali("WGUI_Reset",   [[^wuxia reset$]],   [[WuxiaGUI.setup() echo("WGUI: 重建完成 ✓\n")]])
  ali("WGUI_Refresh", [[^wuxia refresh$]], [[send("hp") send("score")]])
  ali("WGUI_Demo",    [[^wuxia demo$]],    [[WuxiaGUI.loadDemo()]])
  ali("WGUI_Detail",  [[^wuxia detail$]],  [[WuxiaGUI._toggleCharMode()]])
  echo("WGUI: 別名已註冊 ✓  (wuxia reset|refresh|demo|detail)\n")
end

----------------------------------------------------------------------
-- § 14. DEMO DATA
----------------------------------------------------------------------
function WuxiaGUI.loadDemo()
  local d = WuxiaGUI.data
  d.jingqi  = {cur=433, max=433, pct=49}
  d.qixue   = {cur=600, max=600, pct=62}
  d.jingli  = {cur=2000, max=2000, regen=0}
  d.neili   = {cur=3000, max=3000, regen=0}
  d.food    = {cur=0, max=300}
  d.water   = {cur=0, max=300}
  d.pinghe  = "————————————"
  d.qianneng = 100
  d.tihui    = 0
  d.jingyan  = 0

  d.identity = {
    title="普通百姓 管理員(admin)", age="十二歲七個月",
    gender="男性人類", personality="光明磊落",
    birthday="庚戌年一月十五日醜時三刻",
    sect="普通百姓", master="你還沒有拜師",
    gang="自由人士", position="無", military="0策",
    profession="無", yuanshen="無", residence="流浪街頭",
    marriage="單身", partner="沒有", children="沒有",
    sexuality="你還是童男。", mount="沒有",
    bank="沒有積蓄", jianghu="快意恩仇",
  }
  d.combat = {attack=1, defense=1, damage=0, protection=2}
  d.attrs = {
    strength={cur=20,max=20}, perception={cur=20,max=20},
    constitution={cur=20,max=20}, agility={cur=20,max=20},
  }
  d.skills = {unarmed="無評價", weapon="無評價", neigong="無評價", qinggong="無評價"}
  d.stats = {exp=0, potential=100, zhengqi=0, tihui=0, gongji=0, linghui=0, weiwan=0, yueli=0, rongyu=0, liqi=0}
  d.mastery = {wuxue=false, zhoutian=false, yuanying=false, shengsi=false}
  d.kills = {total=0, player=0, murder=0, stun=0, good=0, evil=0, slaughter=0}
  d.playtime = "九天六小時三十五分十五秒"

  WuxiaGUI.refresh()
  WuxiaGUI.chat("系統", "<gold>範例數據已載入。<reset>")
  echo("WGUI: 範例數據已載入 ✓\n")
end

----------------------------------------------------------------------
-- § 15. GMCP HOOKS (stubs — wire up when server sends GMCP)
----------------------------------------------------------------------
--[[
  When your server sends GMCP data, register event handlers like:

  registerAnonymousEventHandler("gmcp.Char.Vitals", function()
    local v = gmcp.Char.Vitals
    WuxiaGUI.data.jingqi.cur = tonumber(v.jingqi) or 0
    WuxiaGUI.data.jingqi.max = tonumber(v.jingqi_max) or 0
    -- ... etc
    WuxiaGUI.refresh()
  end)

  registerAnonymousEventHandler("gmcp.Char.Status", function()
    local s = gmcp.Char.Status
    WuxiaGUI.data.identity.title = s.title or ""
    -- ... etc
    WuxiaGUI.refresh()
  end)
]]

----------------------------------------------------------------------
-- § 16. START
----------------------------------------------------------------------
function WuxiaGUI.start()
  echo("\n")
  cecho("<gold>╔═══════════════════════════════════════════╗<reset>\n")
  cecho("<gold>║<reset>   武俠 MUD GUI v2.0 — 武林介面系統      <gold>║<reset>\n")
  cecho("<gold>╚═══════════════════════════════════════════╝<reset>\n")
  echo("\n")
  WuxiaGUI.setup()
  WuxiaGUI.registerTriggers()
  WuxiaGUI.registerAliases()
  echo("\n就緒。輸入 wuxia demo 預覽介面。\n\n")
end

WuxiaGUI.start()
