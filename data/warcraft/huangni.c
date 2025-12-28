// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("黃土[2;37;0m[2;37;0m", ({"huangnitu"}));        
        set("gender", "男性");                
        set("long", "塵沙飛揚黃土地[2;37;0m
它是黃泥的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "huangni");
        set("owner_name", "黃泥");
        set_temp("owner", "huangni");
        set_temp("owner_name", "黃泥");
        ::setup();
}
