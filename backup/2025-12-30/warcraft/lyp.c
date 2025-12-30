// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("扣籃對決[2;37;0m[2;37;0m", ({"cib"}));        
        set("gender", "男性");                
        set("long", "扣籃對決[2;37;0m
它是櫻桃六號的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lyp");
        set("owner_name", "櫻桃六號");
        set_temp("owner", "lyp");
        set_temp("owner_name", "櫻桃六號");
        ::setup();
}
