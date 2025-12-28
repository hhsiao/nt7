// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小龍[2;37;0m[2;37;0m", ({"xlong"}));        
        set("gender", "男性");                
        set("long", "小龍[2;37;0m
它是楊很過的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "shsjk");
        set("owner_name", "楊很過");
        set_temp("owner", "shsjk");
        set_temp("owner_name", "楊很過");
        ::setup();
}
