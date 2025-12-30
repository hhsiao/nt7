// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白馬[2;37;0m[2;37;0m", ({"myhorse"}));        
        set("gender", "男性");                
        set("long", "白馬[2;37;0m
它是挖寶甲的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yuanbao");
        set("owner_name", "挖寶甲");
        set_temp("owner", "yuanbao");
        set_temp("owner_name", "挖寶甲");
        ::setup();
}
