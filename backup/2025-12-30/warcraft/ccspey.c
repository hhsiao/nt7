// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m風塵[2;37;0m[2;37;0m", ({"ccss"}));        
        set("gender", "男性");                
        set("long", "$HIR$風塵[2;37;0m
它是南無的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ccspey");
        set("owner_name", "南無");
        set_temp("owner", "ccspey");
        set_temp("owner_name", "南無");
        ::setup();
}
