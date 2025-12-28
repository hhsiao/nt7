// This program is a part of NITAN MudLIB 
// redl 2013/9
#include <ansi.h> 
#include <room.h> 
inherit __DIR__"normal.c"; 


void create()
{
        set("short", "石磕山");
        set("long", 
"這是七十二福地裡的石磕山，漫山遍野的大小石頭嶙峋亂砌。偶\n"
"爾在一些石縫處，看得見好像有礦脈的微微紋理，顏色黑黃不清。\n"
);
                //set("outdoors", "yangzhou");
                set("exits",([ /* sizeof() == 1 */
                        "out" : __DIR__"teleport",
                ]));
                set("objects", ([ 
                        __DIR__"/npc/tie" : 1, 
                        __DIR__"/npc/shi" : 2, 
        ])); 

        //set("no_dazuo",1);
        //set("no_kill",1);
        //set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);         
                set("no_rideto", 1);
                set("no_flyto", 1);
                //set("no_magic", 1); 
        set("no_sleep_room", 1); 
        set("no_get", 1);
        set("no_user_kill", 1);
        set("max_carry_user" ,5);
        set("max_carry_exit" ,"out");
    set("no_protect", 1);
        
        setup();
}

int discmds() 
{ 
        tell_object(this_player(), "你不能在這裡毛手毛腳地亂來。\n");  
        return 1;  
} 

int init() 
{ 
        object me = this_player();
        if (!interactive(me) || !playerp(me)) return 1;
        if ( wiz_level(me) > 5 ) return 1;

        add_action("discmds", ({  
                "steal", "cast", "conjure", "array", "fight",    
                "quit", "exit", "recall", "kill", "ansuan", "touxi", 
                "surrender", "team", "chatroom", "rideto",
        }));  
        return 1;
} 




