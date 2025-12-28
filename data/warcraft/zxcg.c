// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m柒錢[2;37;0m[2;37;0m", ({"zxcgpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是錢柒的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zxcg");
        set("owner_name", "錢柒");
        set_temp("owner", "zxcg");
        set_temp("owner_name", "錢柒");
        ::setup();
}
