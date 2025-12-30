// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("考慮到健[2;37;0m[2;37;0m", ({"cib"}));        
        set("gender", "男性");                
        set("long", "考慮到健[2;37;0m
它是櫻桃七號的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lyq");
        set("owner_name", "櫻桃七號");
        set_temp("owner", "lyq");
        set_temp("owner_name", "櫻桃七號");
        ::setup();
}
