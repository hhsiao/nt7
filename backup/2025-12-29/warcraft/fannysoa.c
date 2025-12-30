// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("勇氣[2;37;0m[2;37;0m", ({"fannysoamm"}));        
        set("gender", "男性");                
        set("long", "美麗於一身的強大生物[2;37;0m
它是北風的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "fannysoa");
        set("owner_name", "北風");
        set_temp("owner", "fannysoa");
        set_temp("owner_name", "北風");
        ::setup();
}
