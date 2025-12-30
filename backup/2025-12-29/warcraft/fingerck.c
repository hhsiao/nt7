// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("追風獸[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "追風獸[2;37;0m
它是指倉的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "fingerck");
        set("owner_name", "指倉");
        set_temp("owner", "fingerck");
        set_temp("owner_name", "指倉");
        ::setup();
}
