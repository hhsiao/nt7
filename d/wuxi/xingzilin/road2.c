// This program is a part of NITAN MudLIB
// redl 2012/11/1
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create() {
    set("short", "杏林小道");
    set("long", @LONG
這是一條黃土小路，兩旁的杏樹薄霧飄繞。遙望東面又是一片茂密
的杏樹林，隱約有人馬的聲音傳來。
LONG);
    set("no_sleep_room", 1);
    set("no_magic", 1);
    set("exits", ([
        "east": __FILE__,
        "west": __FILE__
        ]));


}

void init() {
    object me = this_player();
    object killer;

    if (playerp(me) && random(3)==0 && ! objectp(present("wu shi", this_object())) && (time() - query_temp("enter_xzz_road2", me) > 30 ))
    {
        tell_object(me, CYN"兩個人影突然從路邊跳出來攔住你喝到：一品堂辦事，給我留下來吧！\n"NOR);
        killer = new(__DIR__"npc/wushi9");
        killer->move(this_object());
        killer = new(__DIR__"npc/wushi9");
        killer->move(this_object());
        set_temp("enter_xzz_road2", time(), me);
    }
}

int valid_leave(object me, string dir) {
    //戰鬥不可逃
    if (me->is_fighting())
    {
        tell_object(me, NOR"你還是先解決目前的敵人吧！\n"NOR);
        return 0;
    }

    if (dir == "west")
    {
        if (random(4) == 0)
        {
            me->move(__DIR__"road");
            tell_object(me, YEL"你慌不擇路地逃出杏子林......\n"NOR);
            return 1;
        }
    }

    if (dir == "east")
    {
        if (random(8) == 0)
        {
            me->move(__DIR__"road3");
            tell_object(me, YEL"你衝進了東面的杏子林中......\n"NOR);
            return 1;
        }
    }

    return ::valid_leave(me, dir);
}
