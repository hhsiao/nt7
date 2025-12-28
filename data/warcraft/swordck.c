// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("追風獸[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "追風獸[2;37;0m
它是劍倉的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "swordck");
        set("owner_name", "劍倉");
        set_temp("owner", "swordck");
        set_temp("owner_name", "劍倉");
        ::setup();
}
