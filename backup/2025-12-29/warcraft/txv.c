// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("豬雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "女性");                
        set("long", "朱[2;37;0m
它是太虛的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "txv");
        set("owner_name", "太虛");
        set_temp("owner", "txv");
        set_temp("owner_name", "太虛");
        ::setup();
}
