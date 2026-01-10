// This program is a part of NT MudLIB

mixed valid_database(object ob, string action, mixed *info) {
    //DEBUG_CHANNEL("數據庫訪問檢查：action=" + action + " info=" + implode(info, ",") + "\n");
    if(!objectp(ob) || ((geteuid(ob) != ROOT_UID) && ! is_root(ob))) {
        DEBUG_CHANNEL(geteuid(ob) + "非法的數據庫訪問！\n");
        return 0;
    }
    else
    {
        if(action == "connect" ) {
            /*
             * 這裡演示的多站點數據庫互動
             * 協作的返回密碼寫法，單站點
             * 簡單返回密碼即可（by Find）
             */

            switch (info[1])
            {
            case "127.0.0.1":   // 其它站點的地址
                return "brandnewnitan";     // 這個站點的密碼
            case "localhost":
                return "brandnewnitan";     // 本地站點的密碼
            default:
                if(info[0]=="/adm/etc/userdb.db")
                    return 1;
                else
                    return 0;
            }

        }
        else
            return 1;
    }
}
