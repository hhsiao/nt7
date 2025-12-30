// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("多達麒麟[2;37;0m[2;37;0m", ({"miduowride"}));        
        set("gender", "男性");                
        set("long", "多達麒麟[2;37;0m
它是米多達的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "miduolinw");
        set("owner_name", "米多達");
        set_temp("owner", "miduolinw");
        set_temp("owner_name", "米多達");
        ::setup();
}
