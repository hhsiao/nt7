// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;32m青龍[2;37;0m[2;37;0m", ({"gdragon"}));        
        set("gender", "男性");                
        set("long", "一條青龍。[2;37;0m
它是武貳狼的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "notwo");
        set("owner_name", "武貳狼");
        set_temp("owner", "notwo");
        set_temp("owner_name", "武貳狼");
        ::setup();
}
