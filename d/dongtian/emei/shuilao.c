// This program is a part of NITAN MudLIB
// redl 2013/9
#include <ansi.h>
#include <room.h>
inherit ROOM;

int clean_up() { return 1;}

int do_cantsave() {
    object me = this_player();
    tell_object(me, NOR "這是牢裡，你老實點吧。\n" NOR);
    return -1;
}

int do_action(string arg) {
    string action = query_verb();
    object me = this_player();

    if (me->is_busy() && action!="stat") {
        tell_object(me, NOR "你還是忙完手頭上的事情再說吧。\n" NOR);
        return -1;
    }

    if (query("dongtian/prison/time", me) > query("online_time", me) && action!="tell" && action!="reply" && action!="look" && action!="say" && action!="stat") {
        me->start_busy(2);
        if (action=="chat" || action=="rumor" || action=="ask1") tell_object(me, NOR "你張口欲喊，牆壁上射出幾股臭水噴了你一臉。\n" NOR);
        else tell_object(me, NOR "你胡亂扭擺身體，陷在齊腰深的水裡卻動不了。\n" NOR);
        return -1;
    }

    if (action=="tell" || action=="reply") {
        me->start_busy(60);     //遠處說話避免持續騷擾
    }

    return 0;
}

int throwing(object me, int i) {
    int c, p = query("dongtian/prison/num", me);

    if (undefinedp(p) || !p) p = 0;

    c = (60 * i) * (10 + p) / 10;
    if (c > 86400) c = 86400;
    set("dongtian/prison/ti", i, me);
    set("dongtian/prison/time", query("online_time", me) + c , me);
    set("dongtian/prison/num", p + 1, me);

    message_vision(append_color(NOR + YEL + "虛空中穿過來一隻大如山嶽的巨掌，對著$N" + NOR + YEL + "攔腰一撈，再縮回去就此不見了。\n" + NOR, YEL), me);
    me->move(this_object());
    return 1;
}

int delay_msg(string msg, object me) {
    message_vision(msg, me);
    return 1;
}

void init() {
    object *prisoners, me = this_player();
    string cti;

    add_action("do_cantsave", ({
        "push", "save", "get", "uget", "drop", "quit",
        "home", "exit", "recall", "team", "chatroom",
        "rideto", "array", "battle", "accept"}));

    if (wiz_level(me) > 6 ) {
        //add_action("do_free", "fr");
        return;
    }
    if (query("dongtian/prison/time", me)) {
        set("dtname", __DIR__"guangchang.c"->load_name());
        set("short", query("dtname") + "水牢");
        me->start_busy(30);
        prisoners = query("prisonerlist");
        if (undefinedp(prisoners) || !prisoners || !sizeof(prisoners))
            set("prisonerlist", ({me}));
        else if (member_array(me, prisoners) < 0)
            set("prisonerlist", prisoners + ({me}));
        cti = chinese_number(abs((query("dongtian/prison/time", me) - query("online_time", me))) / 60) + "分鐘";
        if (query("startroom", me)!=base_name(this_object())) {
            CHANNEL_D->channel_broadcast("rumor", NOR + MAG + "聽說" + filter_color(query("name", me), 1) + "被抓進" + query("dtname") + "禁閉" + cti + "。\n" + NOR);
        }
        call_out("delay_msg", 2, append_color(NOR + YEL + "$N" + NOR + YEL + "像只死狗樣被扔了進來，一個陰森的聲音說道：" +  cti + "後自己滾出去。\n" + NOR, YEL), me);
        set("startroom", base_name(this_object()), me);
        set("in_prison", base_name(this_object()), me);
        me->save();
    }
    if (playerp(me) && !__DIR__"guangchang.c"->owner_level(me)) {
        add_action("do_action", "");
    }

}

void create() {
    set("dtname", __DIR__"guangchang.c"->load_name());
    set("short", query("dtname") + "水牢");
    set("long",
        "這是洞天裡黑幽幽的水牢，一米多深的水浸滿了整個房間，臭不可聞。\n"
    );
    //set("outdoors", "dongtian");
    set("exits", ([ /* sizeof() == 1 */
        "north": __DIR__"zoulang21"
        ]));

    set("no_dazuo", 1);
    set("no_kill", 1);
    set("no_fight", 1);
    set("no_steal", 1);
    set("no_beg", 1);
    set("no_rideto", 1);
    set("no_flyto", 1);
    set("no_drift", 1);
    set("no_magic", 1);
    set("no_sleep_room", 1);
    set("valid_startroom", 1);

    set("owner_level", 1);  //不能成為外來者避風港

    set_heart_beat(15);

    setup();
}

int valid_leave(object me, string dir) {
    if (query("dongtian/prison/time", me) && dir == "north") {
        message_vision(append_color(NOR YEL "$N" NOR YEL "彷彿想起什麼提示，狼狽不堪地逃出了水牢。\n" NOR, YEL), me);
        delete("dongtian/prison/time", me);
        me->start_busy(3);
        me->move(__DIR__"teleport");
        message_vision(append_color(NOR YEL "$N" NOR YEL "狼狽不堪地從" + query("dtname") +  NOR YEL "水牢逃了出來。\n" NOR, YEL), me);
        set("startroom", "/d/city/wumiao", me);
        delete("in_prison", me);
        me->save();
        return -1;
    }
    return ::valid_leave(me, dir);
}

void heart_beat() {
    object prisoner, *prisoners, where;
    int ti;

    prisoners = query("prisonerlist");
    if (!undefinedp(prisoners) && prisoners && sizeof(prisoners)) {
        foreach (prisoner in prisoners) {
            if (!prisoner || !objectp(where = environment(prisoner)) || !query("dongtian/prison/time", prisoner)) {
                prisoners -= ({ prisoner });
                continue;
            }
            if (this_object() != where) {
                ti = query("dongtian/prison/ti", prisoner);
                if (ti < 1) ti = 1;
                throwing(prisoner, ti);
            }
        }
        set("prisonerlist", prisoners);
    }
}
