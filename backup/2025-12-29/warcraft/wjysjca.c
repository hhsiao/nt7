// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("座機[2;37;0m[2;37;0m", ({"zuoji"}));        
        set("gender", "男性");                
        set("long", "座機[2;37;0m
它是啊餓的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "wjysjca");
        set("owner_name", "啊餓");
        set_temp("owner", "wjysjca");
        set_temp("owner_name", "啊餓");
        ::setup();
}
