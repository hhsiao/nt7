// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[33m麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "女性");                
        set("long", "這是一隻大麒麟。[2;37;0m
它是風瘋的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "fengfeng");
        set("owner_name", "風瘋");
        set_temp("owner", "fengfeng");
        set_temp("owner_name", "風瘋");
        ::setup();
}
