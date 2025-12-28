// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("劍鞘[2;37;0m[2;37;0m", ({"baoma"}));        
        set("gender", "男性");                
        set("long", "劍鞘[2;37;0m
它是劍九孤獨的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "jjguiji");
        set("owner_name", "劍九孤獨");
        set_temp("owner", "jjguiji");
        set_temp("owner_name", "劍九孤獨");
        ::setup();
}
