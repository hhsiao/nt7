// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("著騎[2;37;0m[2;37;0m", ({"along"}));        
        set("gender", "男性");                
        set("long", "一八[2;37;0m
它是狂意淫的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kuangy");
        set("owner_name", "狂意淫");
        set_temp("owner", "kuangy");
        set_temp("owner_name", "狂意淫");
        ::setup();
}
