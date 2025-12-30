// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("揹簍[2;37;0m[2;37;0m", ({"beiluo"}));        
        set("gender", "男性");                
        set("long", "揹簍[2;37;0m
它是撿破爛的的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "waiker");
        set("owner_name", "撿破爛的");
        set_temp("owner", "waiker");
        set_temp("owner_name", "撿破爛的");
        ::setup();
}
