// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;35m小[1;31m鳥[2;37;0m[2;37;0m", ({"niao"}));        
        set("gender", "男性");                
        set("long", "一隻小小鳥[2;37;0m
它是鳥人的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "bird");
        set("owner_name", "鳥人");
        set_temp("owner", "bird");
        set_temp("owner_name", "鳥人");
        ::setup();
}
