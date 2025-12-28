// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("幾乎都是[2;37;0m[2;37;0m", ({"cib"}));        
        set("gender", "男性");                
        set("long", "幾乎都是[2;37;0m
它是櫻桃酒號的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lys");
        set("owner_name", "櫻桃酒號");
        set_temp("owner", "lys");
        set_temp("owner_name", "櫻桃酒號");
        ::setup();
}
