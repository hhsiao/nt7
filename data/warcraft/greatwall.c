// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("城長[2;37;0m[2;37;0m", ({"wallgreat"}));        
        set("gender", "女性");                
        set("long", "城長[2;37;0m
它是長城的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "greatwall");
        set("owner_name", "長城");
        set_temp("owner", "greatwall");
        set_temp("owner_name", "長城");
        ::setup();
}
