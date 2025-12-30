// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("聖麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "這是一隻聖麒麟。[2;37;0m
它是一色的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yise");
        set("owner_name", "一色");
        set_temp("owner", "yise");
        set_temp("owner_name", "一色");
        ::setup();
}
