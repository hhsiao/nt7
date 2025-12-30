// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龍大[2;37;0m[2;37;0m", ({"longda"}));        
        set("gender", "男性");                
        set("long", "威猛[2;37;0m
它是長大安的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "changanwd");
        set("owner_name", "長大安");
        set_temp("owner", "changanwd");
        set_temp("owner_name", "長大安");
        ::setup();
}
