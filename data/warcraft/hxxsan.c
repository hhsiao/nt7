// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小馬[2;37;0m[2;37;0m", ({"xiaoma"}));        
        set("gender", "女性");                
        set("long", "小馬[2;37;0m
它是華清散的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hxxsan");
        set("owner_name", "華清散");
        set_temp("owner", "hxxsan");
        set_temp("owner_name", "華清散");
        ::setup();
}
