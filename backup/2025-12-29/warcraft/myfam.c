// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白馬[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "女性");                
        set("long", "一匹馬[2;37;0m
它是大刀無敵的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "myfam");
        set("owner_name", "大刀無敵");
        set_temp("owner", "myfam");
        set_temp("owner_name", "大刀無敵");
        ::setup();
}
