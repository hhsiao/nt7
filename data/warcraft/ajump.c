// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大青龍[2;37;0m[2;37;0m", ({"ajumper"}));        
        set("gender", "男性");                
        set("long", "鍾離漢的大青龍[2;37;0m
它是鍾離漢的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ajump");
        set("owner_name", "鍾離漢");
        set_temp("owner", "ajump");
        set_temp("owner_name", "鍾離漢");
        ::setup();
}
