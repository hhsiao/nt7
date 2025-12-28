// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("仙鶴[2;37;0m[2;37;0m", ({"xianhe"}));        
        set("gender", "男性");                
        set("long", "一隻雪白的仙鶴，自由的飛翔[2;37;0m
它是萱鴯的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xuaner");
        set("owner_name", "萱鴯");
        set_temp("owner", "xuaner");
        set_temp("owner_name", "萱鴯");
        ::setup();
}
