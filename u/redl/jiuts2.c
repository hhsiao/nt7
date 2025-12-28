#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "九頭蛇領地");
        set("long",@LONG
這是九頭蛇的領地，周圍盡是潮溼陰深的溼地，恐怖之極。(scheme、research)
LONG);


        set("exits", ([
                "out"    : "/maze/jiutoushe/haitan",
                
        ]));

        set("no_kill",1);
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);         
        set("no_rideto", 1);
        set("no_flyto", 1);
        set("no_user_kill", 1); 
        set("dongtianfudi", 999999); 

        set("sleep_room", 1); 

        setup();
}
