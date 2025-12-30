// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("追風獸[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "追風獸[2;37;0m
它是披風倉的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "surcoatck");
        set("owner_name", "披風倉");
        set_temp("owner", "surcoatck");
        set_temp("owner_name", "披風倉");
        ::setup();
}
