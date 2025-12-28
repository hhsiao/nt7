// This program is a part of NITAN MudLIB 
// redl 2013/5
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 

void create()
{
        set("short", "青石小階");
        set("long", 
"這是一條青石板鋪就的路，半浸在湖水中，延伸向湖心的小島上。走\n"
"過間隔著的數十個青石橋墩之後，青石小階往東轉向上，漸漸可見密林間\n"
"有棟木屋。\n"
);
         //set("outdoors", "chengdu");
        set("exits",([ /* sizeof() == 1 */
                "eastup" : __DIR__"lakehouse",
                "west" : __DIR__"lake",
        ]));

                set("no_rideto", 1);
                set("no_flyto", 1);
                      set("no_magic", 1); 
        
        setup();
        
        
                remove_call_out("do_wave");
                call_out("do_wave", 10);        
}

int do_wave()
{
                switch(random(11)) {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                        tell_room(this_object(), CYN "≈≈"NOR HIG "一陣微風吹過，夢湖上面泛起了千百層粼粼碧波。\n" NOR);
                        break;
                        case 4:
                        case 5:
                        case 6:
                        tell_room(this_object(), CYN "≈≈"NOR HIW "湖水在沙灘邊慢漲漸落，竟也似潮信綿綿不絕。\n" NOR);
                        break;
                        case 7:
                        case 8:
                        tell_room(this_object(), CYN "≈≈"NOR HIC "碧浪輕輕拂過沙灘，就像情人溫柔地吻過你的腳趾。\n" NOR);
                        break;
                        case 9:
                        tell_room(this_object(), CYN "≈≈"NOR HIY "一個大浪打來，衝溼了青石小階，再悄悄退卻。\n" NOR);
                        break;
                case 10:
                        tell_room(this_object(), CYN "≈≈"NOR HIB "岸邊樹木搖曳沙沙作響，湖心島上的木屋卻安靜如初。\n" NOR);
                        break;
            }
        call_out("do_wave", 11 + random(5));              
        return 1;
}



