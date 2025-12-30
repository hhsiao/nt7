// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("睡袋[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "                  [2;37;0m
它是綿羊的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "sheep");
        set("owner_name", "綿羊");
        set_temp("owner", "sheep");
        set_temp("owner_name", "綿羊");
        ::setup();
}
