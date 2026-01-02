// This program is a part of NITAN MudLIB
// redl 2013/9
#include <ansi.h>
#include <room.h>
inherit __DIR__"normal.c";

void create() {
    set("short", "後山");
    set("long",
        "這是後山，山崖上光禿禿的寸草不生，更無一株樹木。山風呼嘯而過，\n"
        "顯得分外的荒涼。\n"
    );
    set("outdoors", "yangzhou");
    set("exits", ([ /* sizeof() == 1 */
        "south": __DIR__"shanlu2",
        "west": __DIR__"teleport"
        ]));

    set("no_steal", 1);
    set("no_beg", 1);
    set("no_rideto", 1);
    set("no_flyto", 1);
    set("no_drift", 1);
    set("no_sleep_room", 1);
    set("max_carry_user" , 20);
    set("owner_level", 1);

    setup();
}


void init() {
    object me = this_player();
    object gcroom = get_object(__DIR__"guangchang.c");

    if (gcroom->owner_level(me)>0) {
        //tell_room(this_object(), "is_owner!\n");
        set_temp("dongtian/invite/hold_time", query("hold_time", gcroom), me);
    } else {
        //tell_room(this_object(), "not_owner!\n");
        if (query("online_time", me) < 86400) {
            tell_object(me, NOR "你在線時間還不足一天玩什麼洞天，一邊玩新手幫助去。\n" NOR);
            me->command("go west");
            return;
        }
        set_temp("dongtian/houshan/hold_time", query("hold_time", gcroom), me);
        tell_object(me, NOR "小心這裡的防衛力量，你如果往西溜走還來得及。\n" NOR);
        if (query_temp("dongtian/houshan/chat_time") < time()) {
            set_temp("dongtian/houshan/chat_time", time() + 60);
            CHANNEL_D->channel_broadcast("dt", NOR + HIW + "據說有人悄悄潛入了" + NOR + HIC + __DIR__"guangchang.c"->load_name() + NOR + HIW + "洞天仙府。\n" + NOR);
        }
    }
    //tell_room(this_object(), "init end!\n");

    me->start_busy(3);

    ::init();
}

int valid_leave(object me, string dir) {
    object gcroom = get_object(__DIR__"guangchang.c");

    if(query("hold_time", gcroom) < 2 && wiz_level(me) < 5 && dir=="south") {
        tell_object(me, NOR "你發現對面是個未知的洞天，不敢潛入。\n" NOR);
        me->start_busy(2);
        return -1;
    }

    return ::valid_leave(me, dir);
}
