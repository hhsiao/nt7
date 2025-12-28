// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("追風獸[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "追風獸[2;37;0m
它是戰衣倉的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "clothck");
        set("owner_name", "戰衣倉");
        set_temp("owner", "clothck");
        set_temp("owner_name", "戰衣倉");
        ::setup();
}
