// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟獸[2;37;0m[2;37;0m", ({"qls"}));        
        set("gender", "女性");                
        set("long", "麒麟獸[2;37;0m
它是美眉互博的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "qzmm");
        set("owner_name", "美眉互博");
        set_temp("owner", "qzmm");
        set_temp("owner_name", "美眉互博");
        ::setup();
}
