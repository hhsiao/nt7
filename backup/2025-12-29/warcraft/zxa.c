// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("毛蟲[2;37;0m[2;37;0m", ({"mao"}));        
        set("gender", "男性");                
        set("long", "毛蟲[2;37;0m
它是墨眉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "zxa");
        set("owner_name", "墨眉");
        set_temp("owner", "zxa");
        set_temp("owner_name", "墨眉");
        ::setup();
}
