// This program is a part of NITAN MudLIB
// redl 2013/9
#include <ansi.h>
#include <room.h>
inherit __DIR__"normal.c";

void create() {
    set("short", "練功房");
    set("long",
        "這是洞天裡的練功房，收羅了各處極品的練功對象在此供人鍛鍊。\n"
    );
    //set("outdoors", "yangzhou");
    set("exits",([ /* sizeof() == 1 */
        "down": __DIR__"liangongfang"
        ]));

    set("objects", ([
        __DIR__"npc/shi2" : 1
        ]));

    set("no_steal", 1);
    set("no_beg", 1);
    set("no_rideto", 1);
    set("no_flyto", 1);
    set("no_drift", 1);
    set("no_sleep_room", 1);
    set("max_carry_user" , 1);

    //set("owner_level", 1);        //不能成為外來者避風港

    setup();
}

void init() {
    object me = this_player();
    if (playerp(me)) {
        me->start_busy(2);
        me->command("kill shi moxiang");
    }

    set("zhen_type", query("zhen_type", get_object(__DIR__"guangchang")));
    set("max_carry_user", 1 + (query("zhen_type") + 1) / 3);

    ::init();
}
