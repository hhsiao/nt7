// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("傅立葉[2;37;0m[2;37;0m", ({"fourier"}));        
        set("gender", "男性");                
        set("long", "一隻朱雀[2;37;0m
它是陳雪的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "signal");
        set("owner_name", "陳雪");
        set_temp("owner", "signal");
        set_temp("owner_name", "陳雪");
        ::setup();
}
