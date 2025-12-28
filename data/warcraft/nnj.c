// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小眼[2;37;0m[2;37;0m", ({"myzuoqi"}));        
        set("gender", "女性");                
        set("long", "小眼[2;37;0m
它是闌額娘個的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nnj");
        set("owner_name", "闌額娘個");
        set_temp("owner", "nnj");
        set_temp("owner_name", "闌額娘個");
        ::setup();
}
