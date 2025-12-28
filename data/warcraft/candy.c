// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("寶貝[2;37;0m[2;37;0m", ({"baobei"}));        
        set("gender", "男性");                
        set("long", "寶貝[2;37;0m
它是反璞歸真的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "candy");
        set("owner_name", "反璞歸真");
        set_temp("owner", "candy");
        set_temp("owner_name", "反璞歸真");
        ::setup();
}
