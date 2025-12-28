// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛龍在天[2;37;0m[2;37;0m", ({"xyadl"}));        
        set("gender", "男性");                
        set("long", "停權[2;37;0m
它是聖人的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xyad");
        set("owner_name", "聖人");
        set_temp("owner", "xyad");
        set_temp("owner_name", "聖人");
        ::setup();
}
