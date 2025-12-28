// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("隨意[2;37;0m[2;37;0m", ({"sll"}));        
        set("gender", "男性");                
        set("long", "隨便[2;37;0m
它是隨風的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "sleep");
        set("owner_name", "隨風");
        set_temp("owner", "sleep");
        set_temp("owner_name", "隨風");
        ::setup();
}
