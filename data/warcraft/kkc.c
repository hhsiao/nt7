// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("睡[2;37;0m[2;37;0m", ({"sleep_bag"}));        
        set("gender", "女性");                
        set("long", "袋[2;37;0m
它是滅雲的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kkc");
        set("owner_name", "滅雲");
        set_temp("owner", "kkc");
        set_temp("owner_name", "滅雲");
        ::setup();
}
