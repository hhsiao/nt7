// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m叄武[2;37;0m[2;37;0m", ({"matjpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是武叄的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "matj");
        set("owner_name", "武叄");
        set_temp("owner", "matj");
        set_temp("owner_name", "武叄");
        ::setup();
}
