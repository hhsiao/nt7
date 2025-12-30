// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("好人[2;37;0m[2;37;0m", ({"hityou"}));        
        set("gender", "男性");                
        set("long", "好人[2;37;0m
它是一劍西風的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "pxue");
        set("owner_name", "一劍西風");
        set_temp("owner", "pxue");
        set_temp("owner_name", "一劍西風");
        ::setup();
}
