// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("諾特[2;37;0m[2;37;0m", ({"nott"}));        
        set("gender", "男性");                
        set("long", "一條小蛇[2;37;0m
它是江山如畫的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "picland");
        set("owner_name", "江山如畫");
        set_temp("owner", "picland");
        set_temp("owner_name", "江山如畫");
        ::setup();
}
