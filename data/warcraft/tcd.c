// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qingiii"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是菜農四的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tcd");
        set("owner_name", "菜農四");
        set_temp("owner", "tcd");
        set_temp("owner_name", "菜農四");
        ::setup();
}
