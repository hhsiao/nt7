// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("冰鳥[2;37;0m[2;37;0m", ({"phoenix"}));        
        set("gender", "女性");                
        set("long", "冰鳥[2;37;0m
它是陽焰的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "frey");
        set("owner_name", "陽焰");
        set_temp("owner", "frey");
        set_temp("owner_name", "陽焰");
        ::setup();
}
