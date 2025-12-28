// This program is a part of NITAN MudLIB 
// redl 2015/2
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 
void create()
{
        set("short", "天神走廊");
        set("long", 
"這條長廊優雅精緻，盤龍小柱頂著一個個的蓋子，連接著各個去處，一\n"
"個個的蓋子上面都是一幅精美的畫卷，從盤古開天，到封神之戰，讓人走在\n"
"這長廊之上，也能感受上古之戰的地裂天崩。\n"
);
                set("exits",([ /* sizeof() == 1 */
                                "down" : "/u/redl/teleport/teleport",
                        "east" : "/u/lonely/workroom",
                          "south" : "/u/mud/workroom", 
                        "northwest" : __DIR__"workroom",
                ]));

      /*  set("no_fight",1);         
        set("no_steal",1);
        set("no_beg",1);         
        set("no_flyto", 1);*/
        set("no_drift", 1);
        setup();
}

int discmds() 
{ 
        tell_object(this_player(), "你不能在這裡做這個動作。\n");  
        return -1;  
} 


void init()
{
        object me = this_player();
        
                        if (wiz_level(me) < 2) 
                                add_action("discmds", ({  
                                        "ride", "stab", /*"save", "ansuan", "touxi", 
                                        "steal", "cast", "conjure", "array", "fight", "hit",   
                                        "surrender", "exert", "team",  
                                        "array", "battle", "accept", "swear",*/
                        }));  
                

}

int valid_leave(object me, string dir)
{
        object room, *inv;
        int countp;
        
        if (wiz_level(me) < 2 && dir!="down") 
                {
                        tell_object(me, NOR "那不是你可以進去的地方。\n" NOR);  
                        return -1;      
                }
        
        return ::valid_leave(me, dir);
}

