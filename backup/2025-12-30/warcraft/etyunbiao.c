// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"yumao"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是運鏢戊的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "etyunbiao");
        set("owner_name", "運鏢戊");
        set_temp("owner", "etyunbiao");
        set_temp("owner_name", "運鏢戊");
        ::setup();
}
