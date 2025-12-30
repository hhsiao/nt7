// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小倉優子[2;37;0m[2;37;0m", ({"plgp"}));        
        set("gender", "男性");                
        set("long", "@miaoshu[2;37;0m
它是歐陽無敵的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wudi");
        set("owner_name", "歐陽無敵");
        set_temp("owner", "wudi");
        set_temp("owner_name", "歐陽無敵");
        ::setup();
}
