// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m圓圓[2;37;0m[2;37;0m", ({"chenyys"}));        
        set("gender", "男性");                
        set("long", "呵呵[2;37;0m
它是陳圓圓的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "chenyy");
        set("owner_name", "陳圓圓");
        set_temp("owner", "chenyy");
        set_temp("owner_name", "陳圓圓");
        ::setup();
}
