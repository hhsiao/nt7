// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"choose"}));        
        set("gender", "女性");                
        set("long", "青龍[2;37;0m
它是菜農一的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tca");
        set("owner_name", "菜農一");
        set_temp("owner", "tca");
        set_temp("owner_name", "菜農一");
        ::setup();
}
