// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("蜀犬吠日[2;37;0m[2;37;0m", ({"kdkdk"}));        
        set("gender", "男性");                
        set("long", "地三輪車[2;37;0m
它是在軒在的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wacaia");
        set("owner_name", "在軒在");
        set_temp("owner", "wacaia");
        set_temp("owner_name", "在軒在");
        ::setup();
}
