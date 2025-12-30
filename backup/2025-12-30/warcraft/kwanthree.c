// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("關關[2;37;0m[2;37;0m", ({"kwankwan"}));        
        set("gender", "男性");                
        set("long", "關關[2;37;0m
它是奴才三號的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kwanthree");
        set("owner_name", "奴才三號");
        set_temp("owner", "kwanthree");
        set_temp("owner_name", "奴才三號");
        ::setup();
}
