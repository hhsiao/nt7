#include <ansi.h>

inherit DEMONROOM;

void create()
{
        set("short", "九頭蛇領地");
        set("long",@LONG
這是九頭蛇的領地，周圍盡是潮溼陰深的溼地，恐怖之極。
LONG);


        set("exits", ([
                "out"    : "/maze/jiutoushe/haitan",
                    "enter"    : "/u/redl/jiuts2", 
                
        ]));
                set("no_rideto", 1);         // 設置不能騎馬到其他地方
                set("no_flyto", 1);          // 設置不能從起來地方騎馬來這裡
                set("n_time", 3);
                set("n_npc",30); 
                set("n_max_npc", 30);
                set("s_npc", "/clone/dream_npc/shenlongdao/snake/jiutoushe");

        setup();
}


