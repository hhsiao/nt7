// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("坐騎[2;37;0m[2;37;0m", ({"zuoqie"}));        
        set("gender", "男性");                
        set("long", "坐騎[2;37;0m
它是藥師五的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yaoshie");
        set("owner_name", "藥師五");
        set_temp("owner", "yaoshie");
        set_temp("owner_name", "藥師五");
        ::setup();
}
