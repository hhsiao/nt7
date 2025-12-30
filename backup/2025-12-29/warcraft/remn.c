// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("二大爺[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "女性");                
        set("long", "二大爺[2;37;0m
它是紅鹿的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "remn");
        set("owner_name", "紅鹿");
        set_temp("owner", "remn");
        set_temp("owner_name", "紅鹿");
        ::setup();
}
