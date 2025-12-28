// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m鼠標[2;37;0m[2;37;0m", ({"mouse"}));        
        set("gender", "男性");                
        set("long", "一隻無線鼠標。[2;37;0m
它是比爾蓋茨的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "jojo");
        set("owner_name", "比爾蓋茨");
        set_temp("owner", "jojo");
        set_temp("owner_name", "比爾蓋茨");
        ::setup();
}
