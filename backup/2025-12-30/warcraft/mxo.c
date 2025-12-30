// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("啾啾擠擠[2;37;0m[2;37;0m", ({"myzuoqi"}));        
        set("gender", "女性");                
        set("long", "mygift[2;37;0m
它是滿血復活的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "mxo");
        set("owner_name", "滿血復活");
        set_temp("owner", "mxo");
        set_temp("owner_name", "滿血復活");
        ::setup();
}
