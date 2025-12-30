// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"yewens"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是燁雯的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yewen");
        set("owner_name", "燁雯");
        set_temp("owner", "yewen");
        set_temp("owner_name", "燁雯");
        ::setup();
}
