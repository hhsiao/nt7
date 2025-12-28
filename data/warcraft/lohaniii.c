// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m萬[1;31m年[1;32m神木[2;37;0m[2;37;0m", ({"doggy"}));        
        set("gender", "女性");                
        set("long", "doddy[2;37;0m
它是華山小生的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lohaniii");
        set("owner_name", "華山小生");
        set_temp("owner", "lohaniii");
        set_temp("owner_name", "華山小生");
        ::setup();
}
