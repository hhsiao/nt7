// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("無敵中[2;37;0m[2;37;0m", ({"waistblong"}));        
        set("gender", "男性");                
        set("long", "八粉[2;37;0m
它是腰帶倉二的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "waistb");
        set("owner_name", "腰帶倉二");
        set_temp("owner", "waistb");
        set_temp("owner_name", "腰帶倉二");
        ::setup();
}
