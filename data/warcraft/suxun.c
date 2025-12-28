// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是蘇洵的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "suxun");
        set("owner_name", "蘇洵");
        set_temp("owner", "suxun");
        set_temp("owner_name", "蘇洵");
        ::setup();
}
