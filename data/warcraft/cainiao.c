// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小飛俠[2;37;0m[2;37;0m", ({"apple"}));        
        set("gender", "男性");                
        set("long", "常回家看看[2;37;0m
它是菜鳥的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "cainiao");
        set("owner_name", "菜鳥");
        set_temp("owner", "cainiao");
        set_temp("owner_name", "菜鳥");
        ::setup();
}
