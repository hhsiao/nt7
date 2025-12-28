// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"wudanglong"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是張烏當的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wudangxz");
        set("owner_name", "張烏當");
        set_temp("owner", "wudangxz");
        set_temp("owner_name", "張烏當");
        ::setup();
}
