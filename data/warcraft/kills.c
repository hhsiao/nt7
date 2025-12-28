// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("碧水晶晶獸[2;37;0m[2;37;0m", ({"superstart"}));        
        set("gender", "男性");                
        set("long", "懶洋洋，暖洋洋[2;37;0m
它是蝦米的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kills");
        set("owner_name", "蝦米");
        set_temp("owner", "kills");
        set_temp("owner_name", "蝦米");
        ::setup();
}
