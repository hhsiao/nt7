// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m捌福緣[2;37;0m[2;37;0m", ({"kosfyhpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是福緣捌的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosfyh");
        set("owner_name", "福緣捌");
        set_temp("owner", "kosfyh");
        set_temp("owner_name", "福緣捌");
        ::setup();
}
