// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m青龍牙[2;37;0m[2;37;0m", ({"maburahoaa"}));        
        set("gender", "男性");                
        set("long", "$HIM$青龍牙[2;37;0m
它是陽光的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "maburahoa");
        set("owner_name", "陽光");
        set_temp("owner", "maburahoa");
        set_temp("owner_name", "陽光");
        ::setup();
}
