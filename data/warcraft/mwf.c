// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("無風龍[2;37;0m[2;37;0m", ({"wufeng"}));        
        set("gender", "男性");                
        set("long", "無風龍[2;37;0m
它是魔無風的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "mwf");
        set("owner_name", "魔無風");
        set_temp("owner", "mwf");
        set_temp("owner_name", "魔無風");
        ::setup();
}
