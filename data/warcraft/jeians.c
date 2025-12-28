// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m寶騰蓮花[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "$HIR$寶騰蓮花[2;37;0m
它是慧電的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "jeians");
        set("owner_name", "慧電");
        set_temp("owner", "jeians");
        set_temp("owner_name", "慧電");
        ::setup();
}
