// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("舒化奶[2;37;0m[2;37;0m", ({"cakel"}));        
        set("gender", "男性");                
        set("long", "傭兵焓[2;37;0m
它是生日蛋糕的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "cake");
        set("owner_name", "生日蛋糕");
        set_temp("owner", "cake");
        set_temp("owner_name", "生日蛋糕");
        ::setup();
}
