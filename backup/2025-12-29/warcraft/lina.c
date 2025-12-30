// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神龍[2;37;0m[2;37;0m", ({"linag"}));        
        set("gender", "男性");                
        set("long", "神龍[2;37;0m
它是聖文的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lina");
        set("owner_name", "聖文");
        set_temp("owner", "lina");
        set_temp("owner_name", "聖文");
        ::setup();
}
