// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m捌學[2;37;0m[2;37;0m", ({"kosxxhpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是學捌的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosxxh");
        set("owner_name", "學捌");
        set_temp("owner", "kosxxh");
        set_temp("owner_name", "學捌");
        ::setup();
}
