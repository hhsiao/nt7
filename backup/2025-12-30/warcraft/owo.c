// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m藥袋[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "藥袋[2;37;0m
它是聖丹師的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "owo");
        set("owner_name", "聖丹師");
        set_temp("owner", "owo");
        set_temp("owner_name", "聖丹師");
        ::setup();
}
