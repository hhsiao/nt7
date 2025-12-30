// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龍龍[2;37;0m[2;37;0m", ({"ttt"}));        
        set("gender", "男性");                
        set("long", "龍龍[2;37;0m
它是通不痛的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tbt");
        set("owner_name", "通不痛");
        set_temp("owner", "tbt");
        set_temp("owner_name", "通不痛");
        ::setup();
}
