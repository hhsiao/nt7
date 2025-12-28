// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青青青青青龍[2;37;0m[2;37;0m", ({"xiee"}));        
        set("gender", "男性");                
        set("long", "一條青龍[2;37;0m
它是伯賞坤瑜的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "scdyxiee");
        set("owner_name", "伯賞坤瑜");
        set_temp("owner", "scdyxiee");
        set_temp("owner_name", "伯賞坤瑜");
        ::setup();
}
