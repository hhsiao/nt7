// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("醜醜[2;37;0m[2;37;0m", ({"maomao"}));        
        set("gender", "女性");                
        set("long", "傻傻的寵物，估計東南西北都分不清楚[2;37;0m
它是獨孤劍的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "itch");
        set("owner_name", "獨孤劍");
        set_temp("owner", "itch");
        set_temp("owner_name", "獨孤劍");
        ::setup();
}
