// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[30m青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是烏當貳的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "warrierg");
        set("owner_name", "烏當貳");
        set_temp("owner", "warrierg");
        set_temp("owner_name", "烏當貳");
        ::setup();
}
