// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("二號[2;37;0m[2;37;0m", ({"tonya"}));        
        set("gender", "男性");                
        set("long", "二號[2;37;0m
它是咖啡二號的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "limpaper");
        set("owner_name", "咖啡二號");
        set_temp("owner", "limpaper");
        set_temp("owner_name", "咖啡二號");
        ::setup();
}
