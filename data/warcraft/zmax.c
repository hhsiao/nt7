// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m曉風[2;37;0m[2;37;0m", ({"zen"}));        
        set("gender", "男性");                
        set("long", "[2;37;0m
它是無明氏的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zmax");
        set("owner_name", "無明氏");
        set_temp("owner", "zmax");
        set_temp("owner_name", "無明氏");
        ::setup();
}
