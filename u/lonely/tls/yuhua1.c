#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", MAG"雨花閣"NOR);
        set("long",@LONG
雨花閣是寺中三閣之一，為藏經存書之處。四壁靠牆都立滿了竹
架，架上經書文獻不計其數。因天龍寺乃是帝王出家之地，每到節日
必有世俗子弟到寺中朝拜，每朝拜一次，必有奉獻裝修。北面有個小
門通向寺院後面的松林。
LONG);
        set("exits", ([
                "out" : __DIR__"yuhua",
                "north" : __DIR__"road7",

	]));

        set("objects",([
                __DIR__"npc/liao-si" : 1,
    //            __DIR__"obj/fojing2"+random(2) : 1
        ]));

        setup();
}
