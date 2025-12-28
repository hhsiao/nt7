// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("某某某[2;37;0m[2;37;0m", ({"yaommm"}));        
        set("gender", "男性");                
        set("long", "某某某[2;37;0m
它是藥摸摸的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yaomm");
        set("owner_name", "藥摸摸");
        set_temp("owner", "yaomm");
        set_temp("owner_name", "藥摸摸");
        ::setup();
}
