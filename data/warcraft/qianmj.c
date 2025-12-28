// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老馬[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "老馬[2;37;0m
它是獨醉天明的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "qianmj");
        set("owner_name", "獨醉天明");
        set_temp("owner", "qianmj");
        set_temp("owner_name", "獨醉天明");
        ::setup();
}
