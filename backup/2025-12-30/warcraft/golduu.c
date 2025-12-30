// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("嗚嗚嗚[2;37;0m[2;37;0m", ({"golduuu"}));        
        set("gender", "男性");                
        set("long", "嗚嗚嗚[2;37;0m
它是金又的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "golduu");
        set("owner_name", "金又");
        set_temp("owner", "golduu");
        set_temp("owner_name", "金又");
        ::setup();
}
