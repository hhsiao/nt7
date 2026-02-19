// publishgui.c
// Build WuxiaGUI3.mpackage from /WuxiaGUI3/ and deploy to /www/static/
// Usage: publishgui [seturl <URL> | status]

#include <getconfig.h>

inherit F_CLEAN_UP;

#define GUI_DIR         "/WuxiaGUI3/"
#define GUI_SCRIPT      GUI_DIR "WuxiaGUI3.lua"
#define GUI_ONELINE     GUI_DIR "ONE_LINE.txt"
#define GUI_README      GUI_DIR "PACKAGE_README.md"
#define GUI_RES_DIR     GUI_DIR "WuxiaGUI3/"
#define OUTPUT_FILE     "/www/static/WuxiaGUI3.mpackage"
#define XML_TMP_FILE    "/www/static/_build_tmp.xml"
#define PKG_NAME        "WuxiaGUI3"
#define PKG_AUTHOR      "Henry Hsiao"

// XML-escape a small string: & < > "
string xml_escape(string s) {
    s = replace_string(s, "&", "&amp;");
    s = replace_string(s, "<", "&lt;");
    s = replace_string(s, ">", "&gt;");
    s = replace_string(s, "\"", "&quot;");
    return s;
}

// Escape ]] for Lua long string literals
string lua_bracket_escape(string s) {
    return replace_string(s, "]]", "] ]");
}

// Write large Lua source as XML-escaped text directly to a file,
// in chunks to avoid FluffOS maximum string length limit.
void write_escaped_lua_to_file(string dest, string src_file) {
    int start, nlines;
    string chunk;

    nlines = 200;
    start = 1;
    while (1) {
        chunk = read_file(src_file, start, nlines);
        if (!chunk || chunk == "") break;
        write_file(dest, xml_escape(chunk));
        start += nlines;
    }
}

// Re-send all GMCP data after GUI has time to install
void _delayed_send_burst(object ob) {
    if (!ob || !interactive(ob) || !has_gmcp(ob)) return;
    ob->gmcp_init_burst();
}

int main(object me, string arg) {
    string one_line, readme;
    string config_content;
    string version;
    string *res_files;
    mapping zip_entries;
    int result;
    string err;

    if (!SECURITY_D->valid_grant(me, "(admin)")) {
        write("你沒有權限發佈GUI套件。\n");
        return 1;
    }

    if (arg && sscanf(arg, "seturl %s", arg)) {
        object gmcp_d = find_object("/adm/daemons/gmcp_d");
        if (!gmcp_d) gmcp_d = load_object("/adm/daemons/gmcp_d");
        if (gmcp_d) {
            gmcp_d->set_gui_url(arg);
            write(sprintf("GUI URL 已設定為: %s\n", arg));
            write(sprintf("目前版本: %s\n", gmcp_d->query_gui_version()));
        }
        return 1;
    }

    if (arg == "status") {
        object gmcp_d = find_object("/adm/daemons/gmcp_d");
        if (!gmcp_d) gmcp_d = load_object("/adm/daemons/gmcp_d");
        if (gmcp_d) {
            write(sprintf("GUI URL:     %s\n", gmcp_d->query_gui_url()));
            write(sprintf("GUI 版本:    %s\n", gmcp_d->query_gui_version()));
            int sz = file_size(OUTPUT_FILE);
            write(sprintf("mpackage:    %s (%s)\n", OUTPUT_FILE,
                sz > 0 ? sprintf("%d bytes", sz) : "不存在"));
        }
        return 1;
    }

    // Verify Lua source exists
    if (file_size(GUI_SCRIPT) <= 0) {
        write("錯誤：無法讀取 " + GUI_SCRIPT + "\n");
        return 1;
    }

    one_line = read_file(GUI_ONELINE);
    if (one_line) one_line = trim(one_line);
    else one_line = PKG_NAME;

    readme = read_file(GUI_README);
    if (!readme) readme = "";

    // Always use timestamp as version — guarantees Mudlet sees a new version
    version = sprintf("%d", time());

    write(sprintf("正在建構 %s.mpackage (版本: %s)...\n", PKG_NAME, version));

    // ── Build config.lua ──
    config_content =
        "mpackage = [[" + PKG_NAME + "]]\n"
        "author = [[" + PKG_AUTHOR + "]]\n"
        "icon = [[wuxia_icon.png]]\n"
        "title = [[" + lua_bracket_escape(one_line) + "]]\n"
        "description = [[" + lua_bracket_escape(readme) + "]]\n"
        "version = [[" + version + "]]\n"
        "created = \"" + TIME_D->replace_ctime(time()) + "\"\n";

    // ── Build XML via temp file ──
    // Write XML header, then escaped Lua in chunks, then XML footer.
    // This avoids assembling a 200KB+ string in memory.
    rm(XML_TMP_FILE);

    write_file(XML_TMP_FILE,
        "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
        "<!DOCTYPE MudletPackage>\n"
        "<MudletPackage version=\"1.001\">\n"
        "\t<TriggerPackage />\n"
        "\t<TimerPackage />\n"
        "\t<AliasPackage />\n"
        "\t<ActionPackage />\n"
        "\t<ScriptPackage>\n"
        "\t\t<Script isActive=\"yes\" isFolder=\"no\">\n"
        "\t\t\t<n>" + PKG_NAME + "</n>\n"
        "\t\t\t<packageName></packageName>\n"
        "\t\t\t<script>");

    // Append XML-escaped Lua source in 200-line chunks
    write_escaped_lua_to_file(XML_TMP_FILE, GUI_SCRIPT);

    write_file(XML_TMP_FILE,
        "</script>\n"
        "\t\t\t<eventHandlerList />\n"
        "\t\t</Script>\n"
        "\t</ScriptPackage>\n"
        "\t<KeyPackage />\n"
        "</MudletPackage>\n");

    write(sprintf("  XML: %d bytes\n", file_size(XML_TMP_FILE)));

    // ── Build ZIP entries ──
    // XML entry uses file path — create_zip reads it directly from disk
    zip_entries = ([
        "config.lua"         : to_buffer(config_content),
        PKG_NAME + ".xml"    : XML_TMP_FILE,
    ]);

    // Add resource files (images etc.) directly from disk
    res_files = get_dir(GUI_RES_DIR);
    if (arrayp(res_files)) {
        foreach (string fname in res_files) {
            string fpath = GUI_RES_DIR + fname;
            if (file_size(fpath) > 0)
                zip_entries[fname] = fpath;
        }
    }

    // Add icon from .mudlet/Icon/ (Mudlet convention)
    string icon_path = GUI_RES_DIR + ".mudlet/Icon/wuxia_icon.png";
    if (file_size(icon_path) > 0)
        zip_entries[".mudlet/Icon/wuxia_icon.png"] = icon_path;

    write(sprintf("  包含 %d 個檔案，正在壓縮...\n", sizeof(zip_entries)));

    // ── Create mpackage ──
    err = catch(result = create_zip(OUTPUT_FILE, zip_entries));

    // Clean up temp file
    rm(XML_TMP_FILE);

    if (err) {
        write("錯誤：" + err + "\n");
        return 1;
    }

    if (result) {
        int sz = file_size(OUTPUT_FILE);
        int count = 0;
        write(sprintf("✓ 成功建構 %s (%d bytes)\n", OUTPUT_FILE, sz));
        write(sprintf("  版本: %s\n", version));

        // Update GMCP daemon so new connections get the latest version
        object gmcp_d = find_object("/adm/daemons/gmcp_d");
        if (!gmcp_d) gmcp_d = load_object("/adm/daemons/gmcp_d");
        if (gmcp_d) {
            gmcp_d->set_gui_version(version);
            write(sprintf("  已更新 GMCP_D GUI 版本為 %s\n", version));

            // Push to all online GMCP users
            // Timestamp version always differs → Mudlet auto-uninstalls old + installs new
            foreach (object ob in users()) {
                if (ob && interactive(ob) && has_gmcp(ob)) {
                    gmcp_d->send_gui(ob);
                    call_out("_delayed_send_burst", 5, ob);
                    count++;
                }
            }
            write(sprintf("  已推送更新至 %d 位在線玩家。\n", count));
        }
    } else {
        write("錯誤：create_zip 返回 0，無法寫入 " + OUTPUT_FILE + "\n");
        write("  請在 SECURITY_D 中為 /www/static/ 新增 (admin) 的 trusted_write 權限。\n");
    }

    return 1;
}

int help(object me) {
    write(@HELP
指令格式: publishgui [seturl <URL> | status]

建構 WuxiaGUI3.mpackage 並部署至 /www/static/。
每次建構使用時間戳版本號，Mudlet 自動卸載舊版並安裝新版。

publishgui               建構並推送至所有在線玩家
publishgui seturl <URL>  設定 Mudlet 下載 URL
publishgui status        顯示目前設定

來源檔案:
  /WuxiaGUI3/WuxiaGUI3.lua        Lua 腳本
  /WuxiaGUI3/ONE_LINE.txt          一行描述
  /WuxiaGUI3/PACKAGE_README.md     詳細說明
  /WuxiaGUI3/WuxiaGUI3/            資源檔案 (圖示等)

輸出:
  /www/static/WuxiaGUI3.mpackage   Mudlet 套件

初次設定:
  publishgui seturl http://yourhost:port/static/WuxiaGUI3.mpackage

之後每次修改 Lua 後只需:
  publishgui

HELP );
    return 1;
}
