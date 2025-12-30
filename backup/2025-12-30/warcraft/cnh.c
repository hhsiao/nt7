// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qingvii"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是菜農八的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "cnh");
        set("owner_name", "菜農八");
        set_temp("owner", "cnh");
        set_temp("owner_name", "菜農八");
        ::setup();
}
