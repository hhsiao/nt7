// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("血刀玄武獸[2;37;0m[2;37;0m", ({"xuedaomiride"}));        
        set("gender", "男性");                
        set("long", "血刀玄武獸[2;37;0m
它是張雪米的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "xuedaomi");
        set("owner_name", "張雪米");
        set_temp("owner", "xuedaomi");
        set_temp("owner_name", "張雪米");
        ::setup();
}
