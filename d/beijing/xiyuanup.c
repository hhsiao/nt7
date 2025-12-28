#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "戲院後臺");
        set("long", @LONG
這裡是長安戲院的後臺，後臺不大，卻打掃得很乾淨。幾個戲子
正在後臺化妝，看見你來了，都用很奇怪的眼神盯著你。
LONG );
        set("exits", ([
                "south" : __DIR__"xiyuan",
        ]));
        set("objects", ([
                __DIR__"npc/xizi1" : 2,
                __DIR__"npc/xizi2" : 1,
                __DIR__"npc/xizi3" : 1,
        ]));

	set("coor/x", -2760);
	set("coor/y", 7730);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        int i;
        
        if (dir == "south")
        {
                message_vision(
                        "\n$N一曲唱罷，一揖作禮，身子平飛，從臺上躍出，雙手兀自\n"+
                        "抱拳向觀眾行禮，姿態美妙，眾人齊聲喝采。\n", me);
                        
                i=query("meili", me);
                if (i < 20) 
                {
                        i = i + 10;
                        set("meili", i, me);
                        message_vision(HIC "\n$N的魅力值提高了。\n" NOR, me);
                }
        }
        return ::valid_leave(me, dir);
}