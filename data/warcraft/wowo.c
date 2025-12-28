// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[34m淵魚叢雀[2;37;0m[2;37;0m", ({"woo"}));        
        set("gender", "男性");                
        set("long", "淵魚叢雀!!![2;37;0m
它是夜無道的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wowo");
        set("owner_name", "夜無道");
        set_temp("owner", "wowo");
        set_temp("owner_name", "夜無道");
        ::setup();
}
