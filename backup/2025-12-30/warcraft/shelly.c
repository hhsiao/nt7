// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白色聖誕[2;37;0m[2;37;0m", ({"christmas"}));        
        set("gender", "女性");                
        set("long", "上主，憐憫我這卑微的罪人。 [2;37;0m
它是甜姊兒的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "shelly");
        set("owner_name", "甜姊兒");
        set_temp("owner", "shelly");
        set_temp("owner_name", "甜姊兒");
        ::setup();
}
