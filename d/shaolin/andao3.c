// Room: /d/shaolin/andao3.c
// Date: YZC 96/02/06
// redl 2014

#include <login.h>
#include <ansi.h>

inherit ROOM;

void create() {
    set("short", "暗道");
    set("long", @LONG
這是一個陰暗潮溼的地道，四壁用粗糙的片岩壘垛而成，一顆顆
水珠沿著牆壁滾下來，濺在地上。也許是因為長時間無人通行的緣故，
整個地道瀰漫著一股腐屍般的惡臭。
LONG );
    set("exits", ([
    //"up" : __DIR__"zhonglou1",
        "enter": __DIR__"bagua0"
        ]));
    set("no_clean_up", 0);
    set("no_protect", 1);
    set("no_rideto", 1);
    set("no_flyto", 1);
    set("no_fly", 1);
    set("no_sleep_room", 1);
    set("no_magic", 1);
    setup();
}

void init() {
    object me = this_player();
    if (query_temp("hantan/done", me) &&
        !query("exits/up")
        ) {
        /*
         * if ( query("level", me) < 80 )
         * {
         * return notify_fail("你試著推了推頂上的磚蓋，觸手冰涼，紋絲不動。\n"
         * + "看來已被鐵汁澆透，堅如鐵板一般。看來你只能另想辦法了。\n");
         * me->start_busy(3);
         * } */
        message_vision(HIY
            "$N全身琉璃真氣運轉，拔身錯步，嘿地一聲，舉起雙掌向上猛擊。\n"
            "只見一股白氣自$N掌心而出，迅猛無比地擊中頂上的鐵鑄磚蓋。\n"
            "克剌剌一聲巨響，磚蓋被震成無數小碎片四散飄飛。露出一個向上的洞口。\n" NOR, me );
        set("exits/up", __DIR__"zhonglou1");
    }

}
