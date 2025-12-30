// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("俄日[2;37;0m[2;37;0m", ({"abcdef"}));        
        set("gender", "男性");                
        set("long", "為日[2;37;0m
它是天的的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "asdfl");
        set("owner_name", "天的");
        set_temp("owner", "asdfl");
        set_temp("owner_name", "天的");
        ::setup();
}
