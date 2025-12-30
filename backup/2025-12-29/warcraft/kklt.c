// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("路過[2;37;0m[2;37;0m", ({"jiji"}));        
        set("gender", "男性");                
        set("long", "路過[2;37;0m
它是卡卡羅特的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kklt");
        set("owner_name", "卡卡羅特");
        set_temp("owner", "kklt");
        set_temp("owner_name", "卡卡羅特");
        ::setup();
}
