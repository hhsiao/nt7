// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"idc"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是孫夢的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "aidc");
        set("owner_name", "孫夢");
        set_temp("owner", "aidc");
        set_temp("owner_name", "孫夢");
        ::setup();
}
