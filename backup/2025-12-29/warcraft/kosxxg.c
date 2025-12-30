// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m柒學[2;37;0m[2;37;0m", ({"kosxxgpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是學柒的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kosxxg");
        set("owner_name", "學柒");
        set_temp("owner", "kosxxg");
        set_temp("owner_name", "學柒");
        ::setup();
}
