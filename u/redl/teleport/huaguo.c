// This program is a part of NITAN MudLIB  
// redl 2014/8
#include <ansi.h>  
#include <room.h>  
inherit "/u/redl/teleport/normal.c";  

void create()
{
        set("short","水簾洞");
        set("long", @LONG
寬闊的瀑布衝貫掩蓋著洞門，內裡一個大石窟。虛窗靜室，滑凳
板生花。乳窟龍珠倚掛，縈迴滿地奇葩。鍋灶傍崖存火跡，石座石床
真可愛，石盆石碗更堪誇。又見那一竿兩竿修竹，三點五點梅花。正
當中有一石碣。碣上楷書大字鐫著“花果山福地，水簾洞洞天”。        
LONG );
        set("outdoors", "yangzhou");
        set("exits",([ /* sizeof() == 1 */
            "out"  : "/u/redl/teleport/teleport",
        ]));

        set("no_rideto", 1);
        set("no_flyto", 1);
        set("no_protect", 1); 
        set("no_fly", 1);
        set("no_sleep_room", 1); 
        set("no_magic", 1); 

        set("no_user_yanjiu",1);
        set("no_user_kill", 1); 
        set("max_carry_user" ,99);
        set("max_carry_exit" ,"out");

        setup();
}

int valid_leave(object me, string dir)
{
        if (!interactive(me) || !playerp(me)) return 0;
        return ::valid_leave(me, dir);
}
