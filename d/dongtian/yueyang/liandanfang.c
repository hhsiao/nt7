// This program is a part of NITAN MudLIB
// redl 2013/9
#include <ansi.h>
#include <room.h>
inherit __DIR__"normal.c";

void create() {
    set("short", "煉丹房");
    set("long",
        "這是煉丹房，四周堆放著煉丹的藥材，一個流光溢彩的煉丹爐聳立在中\n"
        "央，爐身盤繞著九條金龍，吞吐著汩汩氤氳藥香。房間裡瀰漫著一股散不盡\n"
        "的淡青色煙霧，長時間的丹藥煉製已經讓這個房間充滿了神秘的色彩。\n"
    );
    //set("outdoors", "dongtian");
    set("exits",([ /* sizeof() == 1 */
        "south": __DIR__"yaopu"
        ]));

    set("objects", ([
        __DIR__"npc/yaotong" : 1,
        "/clone/misc/zhujingchan" : (!random(4) ? 1 : 0),
        "/clone/medicine/jiuhua" : random(2),
        "/clone/medicine/sanhuang" : random(2),
        "/clone/medicine/shengsheng" : random(2),
        "/clone/medicine/tianmo" : random(2)
        ]));

    set("no_steal", 1);
    set("no_beg", 1);
    set("no_rideto", 1);
    set("no_flyto", 1);
    set("no_drift", 1);
    set("no_sleep_room", 1);
    set("max_carry_user" , 3);

    setup();
}

void init() {
    set("zhen_type", query("zhen_type", get_object(__DIR__"guangchang")));
    set("max_carry_user", 3 + query("zhen_type") / 2);

    ::init();
}
