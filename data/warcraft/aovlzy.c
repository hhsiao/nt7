// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老馬[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "老馬[2;37;0m
它是張大膽的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "aovlzy");
        set("owner_name", "張大膽");
        set_temp("owner", "aovlzy");
        set_temp("owner_name", "張大膽");
        ::setup();
}
