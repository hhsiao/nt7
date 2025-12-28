// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("寵物[2;37;0m[2;37;0m", ({"cwg"}));        
        set("gender", "女性");                
        set("long", "達到[2;37;0m
它是雲飛的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yfj");
        set("owner_name", "雲飛");
        set_temp("owner", "yfj");
        set_temp("owner_name", "雲飛");
        ::setup();
}
