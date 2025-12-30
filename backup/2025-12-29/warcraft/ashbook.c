// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是四庫全書的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ashbook");
        set("owner_name", "四庫全書");
        set_temp("owner", "ashbook");
        set_temp("owner_name", "四庫全書");
        ::setup();
}
