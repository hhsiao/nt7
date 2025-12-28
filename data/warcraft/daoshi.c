// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m藥[1;33m丸[2;37;0m[2;37;0m", ({"yaowan"}));        
        set("gender", "男性");                
        set("long", "丹藥[2;37;0m
它是道士的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "daoshi");
        set("owner_name", "道士");
        set_temp("owner", "daoshi");
        set_temp("owner_name", "道士");
        ::setup();
}
