// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("易語言[2;37;0m[2;37;0m", ({"goldyyy"}));        
        set("gender", "男性");                
        set("long", "易語言[2;37;0m
它是金原的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "goldyy");
        set("owner_name", "金原");
        set_temp("owner", "goldyy");
        set_temp("owner_name", "金原");
        ::setup();
}
