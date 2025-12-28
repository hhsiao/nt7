// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m陸錢[2;37;0m[2;37;0m", ({"zxcfpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是錢陸的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zxcf");
        set("owner_name", "錢陸");
        set_temp("owner", "zxcf");
        set_temp("owner_name", "錢陸");
        ::setup();
}
