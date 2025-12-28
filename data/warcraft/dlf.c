// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神仙鳥[2;37;0m[2;37;0m", ({"shengou"}));        
        set("gender", "女性");                
        set("long", "神仙鳥[2;37;0m
它是劍人的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dlf");
        set("owner_name", "劍人");
        set_temp("owner", "dlf");
        set_temp("owner_name", "劍人");
        ::setup();
}
