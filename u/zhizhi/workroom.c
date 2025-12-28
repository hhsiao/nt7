// This program is a part of NITAN MudLIB

#include <ansi.h>
#include <room.h>
inherit CREATE_CHAT_ROOM;

int is_chat_room() { return 1; }

void create()
{
      set("short", "菩提樹下");
        set("long", @LONG
菩提本無樹，明鏡亦非臺；本來無一物，何處惹塵埃。
LONG );

        set("exits", ([ /* sizeof() == 1 */
                 "塵埃":"/d/city/swing",
        ]));

        set("valid_startroom", 1);
        set("no_fight", "1");
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" && ! wizardp(me))
                return notify_fail("那裡只有巫師才能進去。\n");

        return ::valid_leave(me, dir);
}

void init()
{
        add_all_action();
}
