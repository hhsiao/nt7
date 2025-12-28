// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("保濟[2;37;0m[2;37;0m", ({"swordblong"}));        
        set("gender", "男性");                
        set("long", "燃料油[2;37;0m
它是劍無量的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "swordb");
        set("owner_name", "劍無量");
        set_temp("owner", "swordb");
        set_temp("owner_name", "劍無量");
        ::setup();
}
