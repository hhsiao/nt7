# 泥潭7 — 王者歸來

繁體中文武俠 MUD，基於 [fluffos/nt7](https://github.com/fluffos/nt7) 分叉，運行於 [FluffOS v2025.1205.0](https://github.com/fluffos/fluffos/releases/tag/v2025.1205.0)。

本分叉在原版基礎上進行了大量現代化改造，包括 GMCP 客戶端協議支援、Mudlet GUI 自動安裝、PostgreSQL 資料庫後端、程式碼品質整理等。

## 與上游的主要差異

### 🖥️ GMCP 協議與 Mudlet GUI

完整實現了 GMCP（Generic MUD Communication Protocol）協議棧，讓 Mudlet 客戶端可以即時接收結構化遊戲資料，而非依賴文字解析。

- **`adm/daemons/gmcp_d.c`**（新增，691 行）— GMCP 核心守護程序，負責向客戶端推送角色狀態、生命值、技能、裝備、聊天等資料
- **`inherit/user/gmcp.c`**（新增，396 行）— 玩家物件的 GMCP 模組，監控 dbase 變動並即時推送 Buffs、Inventory 等更新
- **`clone/user/login.c`** — 登入流程整合 GMCP，連線時即推送 `Client.GUI` 觸發 Mudlet 自動下載安裝 GUI 套件
- **`include/equip.h`** — 新增裝備欄位定義（飾品、勳章等），供 GMCP Inventory 使用
- **`adm/daemons/channeld.c`** — 頻道系統整合 GMCP `Chat.Line`、`Chat.Channels`，支援客戶端聊天面板

### 🎨 WuxiaGUI3 — Mudlet 客戶端 GUI

全新的 Mudlet 介面套件（5,100+ 行 Lua），透過 GMCP `Client.GUI` 自動推送安裝。

- **五大分頁**：總覽（生命值/狀態條）、屬性（六大屬性/等級/附加屬性）、技能（武功技能條）、天賦、裝備（可視化裝備欄/套裝/背包）
- **聊天面板**：GMCP 驅動，支援分頁、釘選、拖拽排序、頻道開關、未讀通知
- **裝備系統**：裝備/飾品雙頁切換、套裝快速切換（含冷卻動畫）、裝備效果總覽、背包捲軸瀏覽
- **附加屬性**：即時顯示各來源（裝備/技能/經脈/元神/天賦/暫時）的加成明細
- **自動安裝**：`publishgui` 指令一鍵建構 `.mpackage`，推送至所有在線玩家

### 📦 GUI 發佈系統

- **`cmds/adm/publishgui.c`**（新增，215 行）— 管理員指令，從原始碼建構 `.mpackage` ZIP，自動更新版本並推送
- **`adm/daemons/securityd.c`** — 為 `create_zip` efun 新增安全權限檢查
- 每次建構使用時間戳版本號，Mudlet 自動偵測版本差異並更新

### 🗄️ PostgreSQL 資料庫支援

將遊戲資料從純檔案系統遷移至 PostgreSQL，利用 FluffOS 內建的 `db_exec` / `db_fetch` 介面。

### 🔧 FluffOS 現代化

- 修正大量函式呼叫簽章（參數數量匹配），消除 FluffOS 最新版的警告
- 移除過時的 Big5/GBK 編碼轉換邏輯及相關指令
- 移除舊版記憶體優化（現代 FluffOS 已不需要）
- 停用部分不需要的管理員指令
- 效能調整：加大 hash table、object table、living hash table
- 啟用 `sane sorting`，關閉 swap（`time to swap: 0`）

### 🧹 程式碼品質

- 全面的程式碼格式化（`.clang-format` 規範）
- 清理未使用的變數、移除測試檔案
- `.gitignore` 完善：排除資料目錄、備份、日誌等不應追蹤的檔案
- 移除掌門資料、不需要的任務檔案等過時內容
- 新增 `.github/copilot-instructions.md` 作為專案開發指南

### 📝 內容修正

- 全面繁體中文化（原版為簡體）
- 完善 BOSS 介紹並補充挑戰路徑與獎勵
- 修正物品交易的括號問題、成員查詢等 bug

## 快速開始

### 環境需求

- [FluffOS v2025.1205.0](https://github.com/fluffos/fluffos/releases/tag/v2025.1205.0)
- PostgreSQL（選用，檔案系統仍可運作）
- [Mudlet](https://www.mudlet.org/)（推薦客戶端）

### 啟動

```bash
driver config.ini
```

### 連接埠

| 埠號 | 用途 |
|------|------|
| 4444 | Telnet |
| 5555 | Telnet |
| 6666 | Telnet (UTF-8) |
| 8888 | WebSocket / HTTP |

### 管理員

註冊 ID 為 `admin` 的帳號即為管理員。

### GUI 發佈

```
publishgui seturl http://yourhost:8888/static/WuxiaGUI3.mpackage
publishgui
```

Mudlet 連線時自動下載安裝 GUI，管理員執行 `publishgui` 即可更新所有在線玩家。

## 目錄結構

```
adm/daemons/        守護程序（gmcp_d, channeld, combatd 等）
clone/               物件藍圖（武器、防具、NPC、道具）
cmds/                玩家/管理員指令
d/                   遊戲世界房間（按地區分）
feature/             功能模組
include/             標頭檔
inherit/             基底類別（char/, item/, room/, skill/）
kungfu/              武功技能系統
WuxiaGUI3/           Mudlet GUI 原始碼及資源
www/                 WebSocket/HTTP 靜態檔案
```

## 致謝

- 原始 [泥潭7](https://github.com/fluffos/nt7) 由 lonely 開發
- [FluffOS](https://github.com/fluffos/fluffos) 驅動引擎
- [Mudlet](https://www.mudlet.org/) 客戶端
