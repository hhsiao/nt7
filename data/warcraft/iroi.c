// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火鳥[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "女性");                
        set("long", "一隻小小鳥。。。。。。[2;37;0m
它是劍道的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "iroi");
        set("owner_name", "劍道");
        set_temp("owner", "iroi");
        set_temp("owner_name", "劍道");
        ::setup();
}
