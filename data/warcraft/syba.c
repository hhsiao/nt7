// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("腰帶[2;37;0m[2;37;0m", ({"yaodei"}));        
        set("gender", "女性");                
        set("long", "腰帶[2;37;0m
它是藥太極的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "syba");
        set("owner_name", "藥太極");
        set_temp("owner", "syba");
        set_temp("owner_name", "藥太極");
        ::setup();
}
