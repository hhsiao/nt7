// This program is a part of NT MudLIB

#define TRACE_DETAIL_LENGTH_LIMIT       300
#define SPRINTF_OVERFLOW                65535

// 處理錯誤訊息的函式
string tracert_error(mapping error, int caught)
{
        int count;
        string err_msg;
        mapping trace;

        err_msg = "\n"+sprintf(@ERR
──────────────<Bugs Report>──────────────
[ 錯誤時間 ]: %-s
[ 錯誤內容 ]: %-s[m
[ 錯誤檔案 ]: %-s
[ 錯誤行數 ]: %-d[m
[ 資料回溯 ]:
ERR,
        ctime(time()),
        replace_string(error["error"], "\n", " "),
        error["file"],
        error["line"]);

        foreach( trace in error["trace"] )
        {
                count++;
                err_msg +=sprintf(@ERR
    -- 第 %|3d 筆 --
        [ 觸動物件 ]: %O
        [ 程式檔案 ]: %s
        [ 函式名稱 ]: %s(%s)
        [ 呼叫行數 ]: %s
ERR,
                count,
                trace["object"],
                trace["program"]||"",
                trace["function"]||"",
                trace["arguments"] ? implode(map(trace["arguments"], (:typeof($1):)), ", ") : "",
                (trace["line"] || "未知")+"");

                if( trace["arguments"] )
                {
                        err_msg += "        [ 傳入參數 ]:\n";
                        err_msg += implode(map(trace["arguments"], (: "                   ** ("+typeof($1)+")"+implode(explode(sprintf("%."+TRACE_DETAIL_LENGTH_LIMIT+"O\n", $1)+(strlen(sprintf("%O", $1)) > TRACE_DETAIL_LENGTH_LIMIT ? "... 訊息過長省略\n" : ""), "\n"),"\n                      ") :)), "\n")+"\n";
                }
                if( trace["locals"] )
                {
                        err_msg += "        [ 程式變數 ]:\n";
                        err_msg += implode(map(trace["locals"], (: "                   ** ("+typeof($1)+")"+implode(explode(sprintf("%."+TRACE_DETAIL_LENGTH_LIMIT+"O\n", $1)+(strlen(sprintf("%O", $1)) > TRACE_DETAIL_LENGTH_LIMIT ? "... 訊息過長省略\n" : ""), "\n"),"\n                      ") :)), "\n")+"\n";
                }
        }
        err_msg += "──────────────<Bugs Report>──────────────\n\n";
        return err_msg;
}

// simulate the old behavior of the driver
string standard_trace(mapping error, int caught)
{
        int i, s;
        string res;
        object me;
        mixed *cmds;

        /* keep track of number of errors per object...if you're into that */

        res = (caught) ? "錯誤訊息被攔截：" : "";
        res = sprintf("%s\n執行時段錯誤：%s\n程式：%s 第 %i 行\n物件：%s\n",
                      res, error["error"],
                      error["program"], error["line"],
                      error["object"] ? file_name(error["object"]) : "0");

        if( !error["object"] && (me = this_player()) ) {
                res += sprintf("當前玩家：%s(%s) - %O  所在環境：%O\n",
                               me->name(1), query("id", me), me, environment(me));
                cmds = me->query_commands();
                res += me->name(1) + "身上及四周的物品與所在的環境提供以下指令：\n";
                for(i = 0; i<sizeof(cmds); i++)
                        res += sprintf("%-15s  %2d %O\n",
                                       cmds[i][0], cmds[i][1], cmds[i][2]);

                res += sprintf("當前的命令：%O\n", me->query_last_input());
        }

        i = 0;
        s = sizeof(error["trace"]);
        if( !this_player(1) && this_player() ) {
                // filter error trace of messaged & chat command
                for (; i < s; i++)
                {
                        string prog;
                        prog = "/" + error["trace"][i]["program"];
                        if( prog != MESSAGE_D + ".c" &&
                            ! sscanf(prog, "/cmds/chat/%*s") &&
                            prog != "/clone/user/chatter.c" &&
                            prog != F_COMMAND )
                                break;
                }
        }

        for (; i < s; i++)
        {
                res = sprintf("%s呼叫來自：%s 的 %s() 第 %i 行，物件： %O\n",
                              res,
                              error["trace"][i]["program"],
                              error["trace"][i]["function"],
                              error["trace"][i]["line"],
                              error["trace"][i]["object"]);
        }
        return res;
}

void error_handler(mapping error, int caught)
{
        string msg;
        object user;

        /*
        user = this_player(1);
        if( !objectp(user) ) user = this_player();
        if( !objectp(user) ) user = previous_object();
        */
        user = this_interactive() || this_player() || previous_object();

        efun::write_file(LOG_DIR + "debug.log", standard_trace(error, caught));

        // 避免陷入無限錯誤回報迴圈
        if( previous_object() == this_object() )
        {
                if( find_object(CHANNEL_D) )
                        CHANNEL_D->channel_broadcast("debug", "Master object 發生無限錯誤迴圈，"+error["file"]+" 第 "+error["line"]+" 行，錯誤："+error["error"]+"，已強制中止。");
                return;
        }

        msg = tracert_error(error, caught);
        efun::write_file(LOG_DIR + "error_handler", msg);

        if( objectp(user) && userp(user) )
        {
                if( strlen(msg) >= SPRINTF_OVERFLOW-50000 ) msg = msg[0..SPRINTF_OVERFLOW-50000] + "\n\n[訊息過長省略...]\n";
                user->set_temp("bug_msg", msg);

                if( !wizardp(user) )
                {
                        tell_object(user, "[1;5;33mWARNING[m 這裡發現了臭蟲，請用 bug 指令將詳細情況報告給巫師或相關人員...\n");

                        if( find_object(CHANNEL_D) )
                        {
                                CHANNEL_D->channel_broadcast("debug", user->query_idname()+"執行時段錯誤"+(caught ? "(Catch)" : "")+"："+error["file"]+" 第 "+error["line"]+" 行。");
                                CHANNEL_D->channel_broadcast("debug", "錯誤："+replace_string(error["error"],"\n", " ")+"。");
                        }
                }
                else
                        tell_object(user, "[1;33m執行時段錯誤[m：請執行 bug 檢查詳細錯誤回溯。\n"+
                                "[1;33m........檔案[m："+error["file"]+"\n[1;33m........行數[m：第 "+error["line"]+" 行\n[1;33m........錯誤[m："+replace_string(error["error"],"\n", " ")+"\n");
        }
        else
        {
                if( find_object(CHANNEL_D) )
                {
                        CHANNEL_D->channel_broadcast("debug", (objectp(user) ? base_name(user)+" " : "")+"執行時段錯誤"+(caught ? "(Catch)" : "")+"："+error["file"]+" 第 "+error["line"]+" 行。");
                        CHANNEL_D->channel_broadcast("debug", "錯誤："+replace_string(error["error"],"\n", " ")+"。");
                }
        }

        return;
}


// Write an error message into a log file. The error occured in the object
// 'file', giving the error message 'message'.
// 紀錄顯示編譯錯誤之訊息
void log_error(string file, string message)
{
        string error_type;
        // string name, home;
        object user;
        /*
        user = this_player(1);
        if( !objectp(user) ) user = this_player();
        if( !objectp(user) ) user = previous_object();
        */
        user = this_interactive() || this_player() || previous_object();

        error_type = strsrch(message, "Warning") == -1 ? "錯誤" : "警告";

        if( objectp(user) && userp(user) )
        {
                if (find_object(CHANNEL_D))
                        CHANNEL_D->channel_broadcast("debug", user->query_idname() + "編譯時段" + error_type + "：" + message);
        }
        else
        {
                if( find_object(CHANNEL_D) )
                        CHANNEL_D->channel_broadcast("debug", (objectp(user) ? base_name(user)+" " : "")+"編譯時段"+error_type+"："+message);
        }
        if (error_type == "錯誤")
        {
                efun::write_file(LOG_DIR + "log_error", message);
        }
        else
        {
                efun::write_file(LOG_DIR + "log", message);
        }
}
