// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m驢子他媽[2;37;0m[2;37;0m", ({"lvzib"}));        
        set("gender", "女性");                
        set("long", "驢子他媽[2;37;0m
它是冥月禿驢的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ywub");
        set("owner_name", "冥月禿驢");
        set_temp("owner", "ywub");
        set_temp("owner_name", "冥月禿驢");
        ::setup();
}
