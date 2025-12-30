// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛星[2;37;0m[2;37;0m", ({"flo"}));        
        set("gender", "女性");                
        set("long", "no[2;37;0m
它是空懷的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "toro");
        set("owner_name", "空懷");
        set_temp("owner", "toro");
        set_temp("owner_name", "空懷");
        ::setup();
}
