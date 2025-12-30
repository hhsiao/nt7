// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("挖火[2;37;0m[2;37;0m", ({"along"}));        
        set("gender", "男性");                
        set("long", "燸國[2;37;0m
它是加藤鷹的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "fingera");
        set("owner_name", "加藤鷹");
        set_temp("owner", "fingera");
        set_temp("owner_name", "加藤鷹");
        ::setup();
}
