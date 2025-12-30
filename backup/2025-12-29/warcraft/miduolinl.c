// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雲採[2;37;0m[2;37;0m", ({"mohuanshou"}));        
        set("gender", "男性");                
        set("long", "雲採[2;37;0m
它是米十二的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "miduolinl");
        set("owner_name", "米十二");
        set_temp("owner", "miduolinl");
        set_temp("owner_name", "米十二");
        ::setup();
}
