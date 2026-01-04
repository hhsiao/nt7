// walk.c

inherit F_CLEAN_UP;

#define PATH_D  "/adm/daemons/pathd.c"

int main(object me, string arg) {
    mixed a;
    mixed br;
    string str = "", action = "do ";

    if(uptime() < 2100 )
        return notify_fail("系統氣喘噓地嘆道：重啟不到2100秒，請稍後再試 ....\n");

    if(time() - query_temp("last_walk", me) < 10 )
        return notify_fail("系統氣喘噓地嘆道：慢慢來 ....\n");

    if(!arg ) return notify_fail("你想得到去哪兒的路徑？\n");
    if(environment(me)->is_chat_room() ) return notify_fail("聊天室內不能使用尋路功能！\n");

    if(sscanf(base_name(environment(me)), "/f/%*s") )
        return notify_fail("副本里禁止使用walk尋路功能 ....\n");

    if(!is_chinese(arg) )
        return notify_fail("指令格式：walk <中文地址>\n");

    set_temp("last_walk", time(), me);
    a = PATH_D->search_for_path(me, arg);
    if(!a || a == 1) {
        set_temp("last_walk", time() + 10, me);
        write("沒有這個地方，或者這個地方離這裡超過規定的距離限制。\n");
        return 1;
    }
    write(arg + "路徑搜索完成，共"+sizeof(a[1]) + "步，路線為：\n");
    for(int i = 0;i < sizeof(a[1]);i++ )
    {
        str += a[1][i] + ";";
        action += a[1][i] + ",";
    }
    str = str[0..<2];
    action = action[0..<2];
    str += "\n";
    write(str);
    br = query("env/brief", me);
    set("env/brief", 1, me);
    me->command(me->process_input(action));
    set("env/brief", br, me);
    write("你已經到達"+arg + "。\n");
    return 1;
}
