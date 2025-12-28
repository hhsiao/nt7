// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("無雙馬[2;37;0m[2;37;0m", ({"dmcp"}));        
        set("gender", "女性");                
        set("long", "無雙馬[2;37;0m
它是楓無雙的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "mapledmc");
        set("owner_name", "楓無雙");
        set_temp("owner", "mapledmc");
        set_temp("owner_name", "楓無雙");
        ::setup();
}
