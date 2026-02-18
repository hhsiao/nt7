### Description

WuxiaGUI3 is a comprehensive graphical interface package for the **王者歸來** (King's Return) MUD. It replaces the traditional text-only experience with a modern, visually rich UI while preserving the classic MUD gameplay.

**Features:**

- **角色面板 (Character Panel)** — Five tabs: 總覽 (Overview), 屬性 (Attributes), 技能 (Skills), 天賦 (Talents), 裝備 (Equipment)
- **裝備系統 (Equipment System)** — Visual character sheet with slot-based equipment display, category toggle (裝備/飾品), quality color coding, and fullsuit bonus tracking
- **背包管理 (Inventory)** — Scrollable item list with custom scrollbar, item stacking with Chinese number display, equipment status tags, and English ID reference
- **聊天頻道 (Chat Channels)** — Channel selector dropdown with quick-switch gear button, supports all in-game chat channels
- **裝備效果 (Equipment Buffs)** — Real-time summary of all equipment stat bonuses with full Chinese translation
- **套裝組合 (Equipment Sets)** — Save and load up to 5 equipment presets with one click

All data is synchronized in real-time via **GMCP** (Generic MUD Communication Protocol). No polling, no command parsing — the server pushes updates directly to the client.

**Note:** This package is specifically designed for 王者歸來 and requires the server's GMCP implementation. It will not function on other MUDs.

The package supports auto-updating — updates are delivered automatically when connecting to the server.

### Usage

Simply install the package and connect to 王者歸來. The GUI will initialize automatically.

**介面操作 (Interface Controls):**

- **Tab 切換** — Click the tab headers (總覽/屬性/技能/天賦/裝備) to switch between character info panels
- **裝備/飾品 切換** — Click the toggle button on the equipment page to switch between armor slots and accessory slots
- **套裝組合** — Left-click a set number (1-5) to equip that set; right-click to save your current equipment to that slot
- **背包捲動** — Mouse wheel anywhere on the inventory panel, or drag the scrollbar thumb
- **頻道切換** — Click the ⚙ gear icon next to the chat input to select a chat channel

**Chat channel shortcuts:**

`> chat Hello everyone!` — sends to the currently selected channel

The channel selector remembers your last used channel across sessions.

### Technical Details

- Built with Mudlet's Geyser UI framework
- GMCP packages: `Char.Status`, `Char.Inventory`, `Char.Info`, `Char.Skills`
- Raw item database transmission for rich client-side features
- ANSI color preservation in item names and descriptions
- Responsive layout adapts to window resize

### Requirements

- **Mudlet 4.18+** (tested on Mudlet 4.18 and above)
- **王者歸來 MUD server** with GMCP support enabled

### See Also

- [Mudlet Package Best Practices](https://wiki.mudlet.org/w/Manual:Best_Practices#Package_and_Module_best_practices)
- [GMCP Protocol Reference](https://wiki.mudlet.org/w/Manual:Scripting#GMCP)
- [王者歸來 MUD](http://mud.wangzheguilai.com)
