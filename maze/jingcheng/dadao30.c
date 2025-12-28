#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"京城大道"NOR);
        set("long", @LONG
你走在紫金城大道上，感到這裡的街道比比別處的開闊，潔淨。可能是因為
靠近天子腳下的緣故，尋常很少有人在這裡走動。可是對武林人物來說，卻似乎
根本沒有把這裡當什麼禁地，時常有不少的幫派為了擴張自己勢力，在此發生械
鬥，這裡反而成了解決江湖恩怨的絕佳場所。
LONG
        );
        set("outdoors", "jingcheng"); 
        set("exits", ([
                "east"  :  __DIR__"dadao24",
                "west"  :  __DIR__"dadao36",
                "south":  __DIR__"dadao25",
                "north" :  __DIR__"dadao29",
        ]));

        set("no_fly",1);
        setup();
        replace_program(ROOM);
}

