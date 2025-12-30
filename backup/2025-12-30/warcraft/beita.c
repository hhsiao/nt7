// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小馬[2;37;0m[2;37;0m", ({"xiaoma"}));        
        set("gender", "男性");                
        set("long", "一匹小馬[2;37;0m
它是貝塔的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "beita");
        set("owner_name", "貝塔");
        set_temp("owner", "beita");
        set_temp("owner_name", "貝塔");
        ::setup();
}
