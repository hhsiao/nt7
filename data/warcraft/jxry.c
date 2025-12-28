// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("金鱗瑞獸[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "金鱗瑞獸 御風而來[2;37;0m
它是吉祥如意的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "jxry");
        set("owner_name", "吉祥如意");
        set_temp("owner", "jxry");
        set_temp("owner_name", "吉祥如意");
        ::setup();
}
