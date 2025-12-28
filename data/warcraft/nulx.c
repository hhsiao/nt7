// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("玉麒麟[2;37;0m[2;37;0m", ({"qiling"}));        
        set("gender", "男性");                
        set("long", "蒼茫的天涯是我的愛，好大一隻麒麟跑過來。[2;37;0m
它是三問魚的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nulx");
        set("owner_name", "三問魚");
        set_temp("owner", "nulx");
        set_temp("owner_name", "三問魚");
        ::setup();
}
