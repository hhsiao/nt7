// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("愛騎[2;37;0m[2;37;0m", ({"ilovelong"}));        
        set("gender", "男性");                
        set("long", "愛騎[2;37;0m
它是彭娟的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "pengjuan");
        set("owner_name", "彭娟");
        set_temp("owner", "pengjuan");
        set_temp("owner_name", "彭娟");
        ::setup();
}
