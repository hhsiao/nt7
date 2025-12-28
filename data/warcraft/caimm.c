// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m輸出文字中[2;37;0m[2;37;0m", ({"bmw"}));        
        set("gender", "男性");                
        set("long", "bmw[2;37;0m
它是擦臉明媚的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "caimm");
        set("owner_name", "擦臉明媚");
        set_temp("owner", "caimm");
        set_temp("owner_name", "擦臉明媚");
        ::setup();
}
