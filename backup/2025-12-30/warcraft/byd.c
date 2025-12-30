// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是比亞迪的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "byd");
        set("owner_name", "比亞迪");
        set_temp("owner", "byd");
        set_temp("owner_name", "比亞迪");
        ::setup();
}
