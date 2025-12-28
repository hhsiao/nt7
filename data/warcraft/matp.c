// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m貳雪[2;37;0m[2;37;0m", ({"matppet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是雪貳的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "matp");
        set("owner_name", "雪貳");
        set_temp("owner", "matp");
        set_temp("owner_name", "雪貳");
        ::setup();
}
