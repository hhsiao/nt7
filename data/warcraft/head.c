// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m頭魔[2;37;0m[2;37;0m", ({"headhead"}));        
        set("gender", "男性");                
        set("long", "$HIR$頭魔[2;37;0m
它是魔頭的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "head");
        set("owner_name", "魔頭");
        set_temp("owner", "head");
        set_temp("owner_name", "魔頭");
        ::setup();
}
