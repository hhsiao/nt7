// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是是網絡的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ashtest");
        set("owner_name", "是網絡");
        set_temp("owner", "ashtest");
        set_temp("owner_name", "是網絡");
        ::setup();
}
