// This program is a part of NITAN MudLIB 
// redl 2013/8
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 

int clean_up() { return 1;}

void create()
{
        set("short", "學堂教室");
        set("long", 
"這是一間嶄新整潔的教室，明亮的陽光從玻璃窗外透射進來。教室正\n"
"前方牆壁上是塊高大結實的黑板，黑板上寫著一排大字“治世道，亂世佛\n"
"，由治到亂是儒家”。教室中間隨意擺放著幾排書桌和凳子，桌子上散落\n"
"著各種筆墨紙硯。\n"
);
                //set("outdoors", "yangzhou");
                set("exits",([ /* sizeof() == 1 */
                        "south" : __DIR__"caochang",
                ]));
                set("objects", ([ 
                        __DIR__"npc/xue" : 1,
        ])); 

        set("no_dazuo",1);
        set("no_kill",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);         
                set("no_rideto", 1);
                set("no_flyto", 1);
                set("no_magic", 1); 
        set("no_sleep_room", 1); 
        
        setup();
}

void init()
{
        object ob = this_player();
        if (base_name(ob)=="/clone/user/baby") {
                ob->command("halt");
                message_vision(CYN + "$N" + CYN + "緊張地左右張望了一陣，找了個書桌空位坐下。\n" + NOR, ob);
        }
}

  
