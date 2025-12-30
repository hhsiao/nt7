// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("上官蕭青[2;37;0m[2;37;0m", ({"cors"}));        
        set("gender", "女性");                
        set("long", "曾大戰王者大陸中最頂級的四位高手，最終寡不敵眾隕落在上官府中[2;37;0m
它是上官蕭戰的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "corw");
        set("owner_name", "上官蕭戰");
        set_temp("owner", "corw");
        set_temp("owner_name", "上官蕭戰");
        ::setup();
}
