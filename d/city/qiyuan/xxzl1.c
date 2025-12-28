//休閒走廊
// redl 2013/2

#include <ansi.h>
#include <transmsg.h> 
inherit  ROOM;

string look_string();

void  create  ()
{
    set  ("short",  "休閒走廊");
        set("long", @LONG
這裡是一條走廊，通向各個休閒娛樂活動的房間。
LONG );

        set("no_dazuo",1);
        set("no_kill",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);         

        set("objects", ([ 
                        "/adm/npc/changzi" : 1, 
                                                "/u/redl/npc/yangyong" : 1,
                        "/adm/npc/huangdaxian" : 1,
        ])); 
        
    set("exits",  ([
    "east"  :  __DIR__"xxzl2",
        "southwest" :  "/d/city/swing",
        "northwest" :  "/u/redl/teleport/teleport",
    "south"  :  __DIR__"xq1",
//    "north"  :  __DIR__"qiyuan2",
    "west" : "/d/city/kedian4",
    ]));

   setup();
                ("/adm/npc/obj/caipiao_ban")->come_here(); 
}


