// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "這是一隻上古年間麒麟[2;37;0m
它是千水凝冰的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "qsnb");
        set("owner_name", "千水凝冰");
        set_temp("owner", "qsnb");
        set_temp("owner_name", "千水凝冰");
        ::setup();
}
