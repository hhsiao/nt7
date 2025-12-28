// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m閃電[2;37;0m[2;37;0m", ({"rainbow"}));        
        set("gender", "男性");                
        set("long", "一隻黑色高又冷漠的戰龍[2;37;0m
它是夏雨的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "rain");
        set("owner_name", "夏雨");
        set_temp("owner", "rain");
        set_temp("owner_name", "夏雨");
        ::setup();
}
