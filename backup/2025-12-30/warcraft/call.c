// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟玉[2;37;0m[2;37;0m", ({"callme"}));        
        set("gender", "女性");                
        set("long", "沒得[2;37;0m
它是龍龍酒的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "call");
        set("owner_name", "龍龍酒");
        set_temp("owner", "call");
        set_temp("owner_name", "龍龍酒");
        ::setup();
}
