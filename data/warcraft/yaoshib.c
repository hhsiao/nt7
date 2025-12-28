// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("坐騎[2;37;0m[2;37;0m", ({"zuoqib"}));        
        set("gender", "男性");                
        set("long", "坐騎[2;37;0m
它是藥師二的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yaoshib");
        set("owner_name", "藥師二");
        set_temp("owner", "yaoshib");
        set_temp("owner_name", "藥師二");
        ::setup();
}
