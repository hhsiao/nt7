// This program is a part of NITAN MudLIB 
// redl 2012/11/1 
#include <ansi.h>
inherit DEMONROOM;

void create()
{
        set("short", "杏子林");
        set("long",@LONG
林裡密密麻麻地全是杏樹，在粉白滲金的花的海洋裡一片濃香撲鼻。
杏子樹上的花瓣時有往人的頭頂飄落，似乎醞釀著某種陰鬱情緒。
LONG);
                                set("ngroup", 2); 
                                set("no_sleep_room",1);
                                set("no_magic", 1);
                set("n_time", 15); 
                set("n_npc", 1); 
                set("n_max_npc", random(2));
                set("s_npc", __DIR__"npc/wushi2345");
        setup();
}


#include "../leavelin.h";
