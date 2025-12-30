// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("蟲子[2;37;0m[2;37;0m", ({"chong"}));        
        set("gender", "男性");                
        set("long", "蟲子[2;37;0m
它是木頭的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tou");
        set("owner_name", "木頭");
        set_temp("owner", "tou");
        set_temp("owner_name", "木頭");
        ::setup();
}
