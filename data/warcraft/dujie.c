// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m達摩[2;37;0m[2;37;0m[2;37;0m", ({"wuming"}));        
        set("gender", "女性");                
        set("long", "呵呵[2;37;0m
它是劫難的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "dujie");
        set("owner_name", "劫難");
        set_temp("owner", "dujie");
        set_temp("owner_name", "劫難");
        ::setup();
}
