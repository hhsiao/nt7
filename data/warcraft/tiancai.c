// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神仙龍[2;37;0m[2;37;0m", ({"shengou"}));        
        set("gender", "女性");                
        set("long", "神仙龍[2;37;0m
它是天才的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tiancai");
        set("owner_name", "天才");
        set_temp("owner", "tiancai");
        set_temp("owner_name", "天才");
        ::setup();
}
