// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"tou"}));        
        set("gender", "男性");                
        set("long", "一條青龍[2;37;0m
它是鵑鵬的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hervour");
        set("owner_name", "鵑鵬");
        set_temp("owner", "hervour");
        set_temp("owner_name", "鵑鵬");
        ::setup();
}
