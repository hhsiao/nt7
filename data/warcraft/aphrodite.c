// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小野狼[2;37;0m[2;37;0m", ({"wolf"}));        
        set("gender", "女性");                
        set("long", "奔馳吧，小野狼~[2;37;0m
它是紫嫣兒的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "aphrodite");
        set("owner_name", "紫嫣兒");
        set_temp("owner", "aphrodite");
        set_temp("owner_name", "紫嫣兒");
        ::setup();
}
