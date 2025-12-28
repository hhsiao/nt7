// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m陸學[2;37;0m[2;37;0m", ({"kosxxfpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是學陸的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosxxf");
        set("owner_name", "學陸");
        set_temp("owner", "kosxxf");
        set_temp("owner_name", "學陸");
        ::setup();
}
