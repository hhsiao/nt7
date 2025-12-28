// This program is a part of NITAN MudLIB 
// redl 2013/9
#include <ansi.h> 
#include <room.h> 
inherit __DIR__"normal.c"; 

void create()
{
        set("short", "山路");
        set("long", 
"前面已然是山路崎嶇，不知名發光的石頭鋪砌成彎彎曲折的小路，淡淡\n"
"的發出青色的光芒，整條路順山而上，遠遠望去如一條青色大蛇蜿蜒扭轉，\n"
"不知這山路盡頭是何去處。\n"
);
                set("outdoors", "dongtian");
                set("exits",([ /* sizeof() == 1 */
                        "south" : __DIR__"zoulang24",
                        "east" : __DIR__"shanlu2",
                ]));

        set("no_steal",1);
        set("no_beg",1);         
                set("no_rideto", 1);
                set("no_flyto", 1);
        set("no_drift", 1);
        set("no_sleep_room", 1); 
        set("max_carry_user" ,20);
        
        setup();
}



