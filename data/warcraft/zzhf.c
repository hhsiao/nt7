// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"lop"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是恆七的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "zzhf");
        set("owner_name", "恆七");
        set_temp("owner", "zzhf");
        set_temp("owner_name", "恆七");
        ::setup();
}
