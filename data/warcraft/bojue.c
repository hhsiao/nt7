// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛鷹[2;37;0m[2;37;0m", ({"feiying"}));        
        set("gender", "男性");                
        set("long", "...[2;37;0m
它是伯爵的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "bojue");
        set("owner_name", "伯爵");
        set_temp("owner", "bojue");
        set_temp("owner_name", "伯爵");
        ::setup();
}
