// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "劍仙的座騎[2;37;0m
它是劍仙的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "jianxian");
        set("owner_name", "劍仙");
        set_temp("owner", "jianxian");
        set_temp("owner_name", "劍仙");
        ::setup();
}
