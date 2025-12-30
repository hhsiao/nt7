// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("光速[2;37;0m[2;37;0m", ({"jin"}));        
        set("gender", "女性");                
        set("long", "快速無比[2;37;0m
它是琴兒的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "qiner");
        set("owner_name", "琴兒");
        set_temp("owner", "qiner");
        set_temp("owner_name", "琴兒");
        ::setup();
}
