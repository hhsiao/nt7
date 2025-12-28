// This program is a part of NITAN MudLIB 
// redl 2013/9
#include <ansi.h> 
#include <room.h> 
inherit __DIR__"normal.c"; 

void create()
{
        set("short", "睡房");
        set("long", 
"這是洞天裡的睡房，環境舒適，透過木窗隱約可見走廊，窗外的青青竹\n"
"影搖曳，沙沙作響。練功辛苦了的人可以在此小憩。\n"
);
                //set("outdoors", "dongtian");
                set("exits",([ /* sizeof() == 1 */
                                "north" : __DIR__"zoulang11",
                ]));

        set("sleep_room",1);
        set("no_fight",1);
        set("no_clean_up",1);

        set("no_steal",1);
        set("no_beg",1);         
                set("no_rideto", 1);
                set("no_flyto", 1);
        set("no_drift", 1);
        //set("no_sleep_room", 1); 
        //set("max_carry_user" ,20);
        set("owner_level", 1);
       
        setup();
}

int disscheme() 
{ 
        tell_object(this_player(), "一聲奸笑令你毛骨悚然..。\n");  
        return -1;  
} 

void init()
{
        add_action("disscheme", ({"scheme"})); 
        ::init();
}



