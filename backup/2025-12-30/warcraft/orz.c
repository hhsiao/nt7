// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[44;1m冷月[2;37;0m[2;37;0m", ({"lengyue"}));        
        set("gender", "男性");                
        set("long", "$HBBLU$冷月[2;37;0m
它是八魯叼的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "orz");
        set("owner_name", "八魯叼");
        set_temp("owner", "orz");
        set_temp("owner_name", "八魯叼");
        ::setup();
}
