// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m禮品都是[2;37;0m[2;37;0m", ({"lpds"}));        
        set("gender", "男性");                
        set("long", "呵呵[2;37;0m
它是禮品的的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lpd");
        set("owner_name", "禮品的");
        set_temp("owner", "lpd");
        set_temp("owner_name", "禮品的");
        ::setup();
}
