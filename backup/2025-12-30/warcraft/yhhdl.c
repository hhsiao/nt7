// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("東北[2;37;0m[2;37;0m", ({"oko"}));        
        set("gender", "男性");                
        set("long", "純種東北虎[2;37;0m
它是天天的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yhhdl");
        set("owner_name", "天天");
        set_temp("owner", "yhhdl");
        set_temp("owner_name", "天天");
        ::setup();
}
