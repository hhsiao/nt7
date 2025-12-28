// This program is a part of NITAN MudLIB 
// redl 2012/11/1 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "杏林小道");
        set("long", @LONG
這是林中小路，高大的杏樹密佈。濃霧飄繞五丈外不可見人，周圍
殺喊的聲音不時傳來。
LONG);
        set("no_magic", 1);
	set("no_sleep_room",1);
        set("exits", ([
                        "north"  : __DIR__"xxlin1",
                        "west" : __DIR__"road2",
        ]));

           set("objects", ([ 
                     "/clone/npc/walker"  : 3, 
           ])); 

setup();


}

int valid_leave(object me, string dir)
{
          if (dir == "west" && ! playerp(me)) return 0; //阻擋npc逃出區域
        return ::valid_leave(me, dir);
}

