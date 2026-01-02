// Room: /d/shaolin/wuxing0.c
// Date: YZC 96/02/06

#include <ansi.h>

inherit ROOM;

string* dirs = ({ "east", "south", "west", "north" });

void create() {
    set("short", HIY "五行洞" NOR);
    set("long", @LONG
[1；33m這是五行洞。四周一片亮晶晶的，定睛細看，卻是無數鋒利的刀
尖從牆上，地上，頂上，四面八方向你伸過來，稍不留神就會自己撞
到刀尖上去。刀光眩目，更添徹骨寒意。幾具血淋淋的斷肢殘骸掛在
刀尖上，看來已經有些時日了。牆壁黑乎乎的，似是鋼鐵鑄成。[2；37；0m
LONG );
    set("exits", ([
        "east": __DIR__"wuxing4",
        "south": __DIR__"wuxing3",
        "west": __DIR__"wuxing1",
        "north": __DIR__"wuxing2"
        ]));
    set("no_clean_up", 0);
    setup();
}

int check_out(object me) {
    int metal, wood, water, fire, earth;

    metal = query_temp("wuxing/金", me);
    wood = query_temp("wuxing/木", me);
    water = query_temp("wuxing/水", me);
    fire = query_temp("wuxing/火", me);
    earth = query_temp("wuxing/土", me);

    if (metal > 0 &&
        metal == wood && metal == water &&
        metal == fire && metal == earth )
    {
        delete_temp("wuxing", me);
        me->move(__DIR__"andao2");
        return 1;
    }
    return 0;
}

int valid_leave(object me, string dir) {
    int count;

    if (member_array(dir, dirs) != -1)
    {
        if (dir == "north")
        {
            //                        write("*金生水*\n");
            count = query_temp("wuxing/水", me);
            count++;
            set_temp("wuxing/水", count, me);
            if (check_out(me))
            {
                write("你順利地走出了五行迷宮。\n");
                return 1;
            }
        }
        else if (dir == "west")
        {
            //                        write("*金克木*\n");
            delete_temp("wuxing", me);
            me->move(__DIR__"jianyu1");
            write("你掉進機關，落入僧監。\n");
            return 1;
        }
    }
    return ::valid_leave(me, dir);
}
