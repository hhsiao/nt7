// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛龍[2;37;0m[2;37;0m", ({"dra"}));        
        set("gender", "男性");                
        set("long", "飛龍在天[2;37;0m
它是飛韻的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "flyear");
        set("owner_name", "飛韻");
        set_temp("owner", "flyear");
        set_temp("owner_name", "飛韻");
        ::setup();
}
