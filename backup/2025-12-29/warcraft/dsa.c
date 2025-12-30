// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("太極鳥[2;37;0m[2;37;0m", ({"dgg"}));        
        set("gender", "男性");                
        set("long", "一隻鳥[2;37;0m
它是連枷獸魔的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dsa");
        set("owner_name", "連枷獸魔");
        set_temp("owner", "dsa");
        set_temp("owner_name", "連枷獸魔");
        ::setup();
}
