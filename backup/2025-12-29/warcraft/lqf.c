// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小貓[2;37;0m[2;37;0m", ({"xmao"}));        
        set("gender", "男性");                
        set("long", "一隻貓[2;37;0m
它是李秋風的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "lqf");
        set("owner_name", "李秋風");
        set_temp("owner", "lqf");
        set_temp("owner_name", "李秋風");
        ::setup();
}
