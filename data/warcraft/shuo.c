// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"out"}));        
        set("gender", "男性");                
        set("long", "龍是一種善變化能興雲雨利萬物的神異動物，為鱗蟲之長[2;37;0m
它是朔風的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "shuo");
        set("owner_name", "朔風");
        set_temp("owner", "shuo");
        set_temp("owner_name", "朔風");
        ::setup();
}
