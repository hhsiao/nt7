// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"ddddd"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是蘭蘭的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lanxxxx");
        set("owner_name", "蘭蘭");
        set_temp("owner", "lanxxxx");
        set_temp("owner_name", "蘭蘭");
        ::setup();
}
