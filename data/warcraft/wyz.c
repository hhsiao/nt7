// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("中彩票[2;37;0m[2;37;0m", ({"tooly"}));        
        set("gender", "男性");                
        set("long", "中彩票[2;37;0m
它是腦殼昏的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "wyz");
        set("owner_name", "腦殼昏");
        set_temp("owner", "wyz");
        set_temp("owner_name", "腦殼昏");
        ::setup();
}
