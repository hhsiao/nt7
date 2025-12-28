// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛兒鳥[2;37;0m[2;37;0m", ({"flyqueque"}));        
        set("gender", "女性");                
        set("long", "飛[2;37;0m
它是風冰凝的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lxddongtwo");
        set("owner_name", "風冰凝");
        set_temp("owner", "lxddongtwo");
        set_temp("owner_name", "風冰凝");
        ::setup();
}
