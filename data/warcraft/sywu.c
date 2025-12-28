// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("馬兒跑[2;37;0m[2;37;0m", ({"maerpao"}));        
        set("gender", "男性");                
        set("long", "馬兒跑[2;37;0m
它是皇太后的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "sywu");
        set("owner_name", "皇太后");
        set_temp("owner", "sywu");
        set_temp("owner_name", "皇太后");
        ::setup();
}
