// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m雅馬哈[5m[1;37m迅鷹[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "男性");                
        set("long", "kick[2;37;0m
它是櫻木花道的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "bally");
        set("owner_name", "櫻木花道");
        set_temp("owner", "bally");
        set_temp("owner_name", "櫻木花道");
        ::setup();
}
