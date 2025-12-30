// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m陸雪[2;37;0m[2;37;0m", ({"matmpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是雪陸的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "matm");
        set("owner_name", "雪陸");
        set_temp("owner", "matm");
        set_temp("owner_name", "雪陸");
        ::setup();
}
