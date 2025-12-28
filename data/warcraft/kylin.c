// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("泥[2;37;0m[2;37;0m", ({"axx"}));        
        set("gender", "男性");                
        set("long", "sadadas[2;37;0m
它是胡蘿蔔的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kylin");
        set("owner_name", "胡蘿蔔");
        set_temp("owner", "kylin");
        set_temp("owner_name", "胡蘿蔔");
        ::setup();
}
