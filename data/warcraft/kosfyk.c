// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m勾緣福[2;37;0m[2;37;0m", ({"kosfykpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是福緣勾的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosfyk");
        set("owner_name", "福緣勾");
        set_temp("owner", "kosfyk");
        set_temp("owner_name", "福緣勾");
        ::setup();
}
