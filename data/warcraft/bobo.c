// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("搖籃[2;37;0m[2;37;0m", ({"icq"}));        
        set("gender", "男性");                
        set("long", "愛睏[2;37;0m
它是淨寶的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "bobo");
        set("owner_name", "淨寶");
        set_temp("owner", "bobo");
        set_temp("owner_name", "淨寶");
        ::setup();
}
