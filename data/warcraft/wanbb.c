// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是丸嗶嗶的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wanbb");
        set("owner_name", "丸嗶嗶");
        set_temp("owner", "wanbb");
        set_temp("owner_name", "丸嗶嗶");
        ::setup();
}
