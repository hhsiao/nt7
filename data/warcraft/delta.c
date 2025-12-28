// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m獬豸[2;37;0m[2;37;0m", ({"judgement"}));        
        set("gender", "男性");                
        set("long", "體形或而大如牛，或而小如羊，雙目炯炯有神，額上朝天聳立一角！[2;37;0m
它是北斗的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "delta");
        set("owner_name", "北斗");
        set_temp("owner", "delta");
        set_temp("owner_name", "北斗");
        ::setup();
}
