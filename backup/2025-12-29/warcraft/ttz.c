// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("菊花圓[2;37;0m[2;37;0m", ({"juhua"}));        
        set("gender", "男性");                
        set("long", "菊花圓[2;37;0m
它是囤囤轉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ttz");
        set("owner_name", "囤囤轉");
        set_temp("owner", "ttz");
        set_temp("owner_name", "囤囤轉");
        ::setup();
}
