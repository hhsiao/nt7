// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m獸獸[2;37;0m[2;37;0m", ({"sss"}));        
        set("gender", "男性");                
        set("long", "$RED$獸獸[2;37;0m
它是劍魔的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "pker");
        set("owner_name", "劍魔");
        set_temp("owner", "pker");
        set_temp("owner_name", "劍魔");
        ::setup();
}
