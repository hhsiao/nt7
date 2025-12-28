// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龍[2;37;0m[2;37;0m", ({"eris"}));        
        set("gender", "男性");                
        set("long", "龍[2;37;0m
它是滅驚的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "sire");
        set("owner_name", "滅驚");
        set_temp("owner", "sire");
        set_temp("owner_name", "滅驚");
        ::setup();
}
