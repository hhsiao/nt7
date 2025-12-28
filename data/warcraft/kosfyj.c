// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m拾緣福[2;37;0m[2;37;0m", ({"kosfyjpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是福緣拾的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosfyj");
        set("owner_name", "福緣拾");
        set_temp("owner", "kosfyj");
        set_temp("owner_name", "福緣拾");
        ::setup();
}
