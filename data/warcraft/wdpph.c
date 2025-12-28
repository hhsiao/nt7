// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("都[2;37;0m[2;37;0m", ({"mygift"}));        
        set("gender", "女性");                
        set("long", "都[2;37;0m
它是武當師八的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wdpph");
        set("owner_name", "武當師八");
        set_temp("owner", "wdpph");
        set_temp("owner_name", "武當師八");
        ::setup();
}
