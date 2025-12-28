// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("又鳥[2;37;0m[2;37;0m", ({"mypet"}));        
        set("gender", "女性");                
        set("long", "又鳥[2;37;0m
它是吳月娘的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yueniang");
        set("owner_name", "吳月娘");
        set_temp("owner", "yueniang");
        set_temp("owner_name", "吳月娘");
        ::setup();
}
