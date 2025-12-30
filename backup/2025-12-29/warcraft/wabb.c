// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小開心[2;37;0m[2;37;0m", ({"wacc"}));        
        set("gender", "男性");                
        set("long", "很威猛[2;37;0m
它是開新人的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wabb");
        set("owner_name", "開新人");
        set_temp("owner", "wabb");
        set_temp("owner_name", "開新人");
        ::setup();
}
