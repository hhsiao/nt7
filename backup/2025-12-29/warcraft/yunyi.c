// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m赤風[2;37;0m[2;37;0m", ({"windy"}));        
        set("gender", "男性");                
        set("long", "四足踏火的異獸[2;37;0m
它是雲翼的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yunyi");
        set("owner_name", "雲翼");
        set_temp("owner", "yunyi");
        set_temp("owner_name", "雲翼");
        ::setup();
}
