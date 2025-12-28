// This program is a part of NITAN MudLIB 
// redl 2013/4
#include <ansi.h> 
#include <room.h> 
inherit ROOM; 

void create() 
{ 
                set("short", "山脊小道"); 
                        set("long", @LONG
這是條山脊上的迂迴盤折的小道，雲蒸霞蔚中蜿蜒而上，兩旁卻
是深不見底的絕壁峽谷。路邊的石縫林間，不經意地盛開著一叢叢豔
麗而悽絕的高山杜鵑花。
LONG );
                                

                set("exits", ([ /* sizeof() == */ 
                        "eastdown" : __DIR__"suiroad2",
                        "northup" : __DIR__"suistone",
                ])); 

                set("no_rideto", 1);
                set("no_flyto", 1);
                setup(); 
} 


