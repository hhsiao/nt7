// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("坐騎[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "1111[2;37;0m
它是刀劍簫的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "crazya");
        set("owner_name", "刀劍簫");
        set_temp("owner", "crazya");
        set_temp("owner_name", "刀劍簫");
        ::setup();
}
