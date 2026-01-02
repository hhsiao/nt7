// Room: /d/shaolin/wuxing2.c
// Date: YZC 96/02/06

#include <ansi.h>

inherit ROOM;

string* dirs = ({ "east", "south", "west", "north" });

void create() {
    set("short", HIB "五行洞" NOR);
    set("long", @LONG
[1；34m這是五行洞。一進這裡，你就陷在齊腰深的水裡，腳底是厚厚的
淤泥，一踩上去就鬆鬆地散開，還帶出一大串氣泡冒出水面。最可怖
的是水面上不時飄過來一兩具浸得發腫的浮屍，幾隻老鼠在上面爬上
爬下，把屍體咬得面木全非。四壁用粗糙的片岩壘垛而成，一顆顆水
珠沿著牆壁滾下來，濺在水中．[2；37；0m
LONG );
    set("exits", ([
        "east": __DIR__"wuxing1",
        "south": __DIR__"wuxing4",
        "west": __DIR__"wuxing0",
        "north": __DIR__"wuxing3"
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
        return (1);
    }
    return (0);
}

int valid_leave(object me, string dir) {
    int count;

    if (member_array(dir, dirs) != -1)
    {
        if (dir == "east")
        {
            //                        write("*水生木*\n");
            count = query_temp("wuxing/木", me);
            count++;
            set_temp("wuxing/木", count, me);
            if (check_out(me))
            {
                write("你順利地走出了五行迷宮。\n");
                return 1;
            }
        }
        else if (dir == "north")
        {
            //                        write("*水克火*\n");
            delete_temp("wuxing", me);
            me->move(__DIR__"jianyu1");
            write("你掉進機關，落入僧監。\n");
            return 1;
        }
    }
    return ::valid_leave(me, dir);
}
