// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("藥箱[2;37;0m[2;37;0m", ({"yaoxiang"}));        
        set("gender", "男性");                
        set("long", "一藥箱[2;37;0m
它是璋天是的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "tiansi");
        set("owner_name", "璋天是");
        set_temp("owner", "tiansi");
        set_temp("owner_name", "璋天是");
        ::setup();
}
