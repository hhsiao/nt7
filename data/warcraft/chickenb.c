// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("阿狸愛國[2;37;0m[2;37;0m", ({"adsl"}));        
        set("gender", "男性");                
        set("long", "阿狸愛國[2;37;0m
它是啊二的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "chickenb");
        set("owner_name", "啊二");
        set_temp("owner", "chickenb");
        set_temp("owner_name", "啊二");
        ::setup();
}
