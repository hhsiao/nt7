// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m遠[1;37m古[1;33m聖[1;31m麒麟[1;34m王[2;37;0m[2;37;0m", ({"myth"}));        
        set("gender", "男性");                
        set("long", "遠古聖麒麟王· 麒麟中的遠古王者。[2;37;0m
它是狂野猛男的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "hunk");
        set("owner_name", "狂野猛男");
        set_temp("owner", "hunk");
        set_temp("owner_name", "狂野猛男");
        ::setup();
}
