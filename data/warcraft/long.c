// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"longg"}));        
        set("gender", "女性");                
        set("long", "朱雀[2;37;0m
它是龍太子的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "long");
        set("owner_name", "龍太子");
        set_temp("owner", "long");
        set_temp("owner_name", "龍太子");
        ::setup();
}
