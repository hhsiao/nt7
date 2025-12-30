// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m熾羽[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "朱鳥、朱雀，南方神也。[2;37;0m
它是陸羽的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "jhpzwxb");
        set("owner_name", "陸羽");
        set_temp("owner", "jhpzwxb");
        set_temp("owner_name", "陸羽");
        ::setup();
}
