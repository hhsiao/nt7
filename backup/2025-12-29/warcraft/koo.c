// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m不準打臉[2;37;0m[2;37;0m", ({"gooo"}));        
        set("gender", "男性");                
        set("long", "$HIY$不準打臉[2;37;0m
它是板凳的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "koo");
        set("owner_name", "板凳");
        set_temp("owner", "koo");
        set_temp("owner_name", "板凳");
        ::setup();
}
