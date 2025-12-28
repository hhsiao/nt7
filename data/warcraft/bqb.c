// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小壞蛋[2;37;0m[2;37;0m", ({"qll"}));        
        set("gender", "男性");                
        set("long", "小壞蛋[2;37;0m
它是獨孤二的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "bqb");
        set("owner_name", "獨孤二");
        set_temp("owner", "bqb");
        set_temp("owner_name", "獨孤二");
        ::setup();
}
