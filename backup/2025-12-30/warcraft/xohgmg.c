// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老馬[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "老馬[2;37;0m
它是小財神的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xohgmg");
        set("owner_name", "小財神");
        set_temp("owner", "xohgmg");
        set_temp("owner_name", "小財神");
        ::setup();
}
