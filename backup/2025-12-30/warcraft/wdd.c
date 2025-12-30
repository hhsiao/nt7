// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"long"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是武當二號的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wdd");
        set("owner_name", "武當二號");
        set_temp("owner", "wdd");
        set_temp("owner_name", "武當二號");
        ::setup();
}
