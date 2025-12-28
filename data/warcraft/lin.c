// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("請文[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "請文[2;37;0m
它是水月的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lin");
        set("owner_name", "水月");
        set_temp("owner", "lin");
        set_temp("owner_name", "水月");
        ::setup();
}
