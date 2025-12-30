// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m青龍[2;37;0m[2;37;0m", ({"qlong"}));        
        set("gender", "男性");                
        set("long", "$HIW$青龍[2;37;0m
它是藍精靈的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "smash");
        set("owner_name", "藍精靈");
        set_temp("owner", "smash");
        set_temp("owner_name", "藍精靈");
        ::setup();
}
