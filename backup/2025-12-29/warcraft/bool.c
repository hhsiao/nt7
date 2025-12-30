// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m血劍[2;37;0m[2;37;0m", ({"bloodsword"}));        
        set("gender", "男性");                
        set("long", "ll[2;37;0m
它是九陽真經的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "bool");
        set("owner_name", "九陽真經");
        set_temp("owner", "bool");
        set_temp("owner_name", "九陽真經");
        ::setup();
}
