// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老馬[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "老馬[2;37;0m
它是隨緣的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "looker");
        set("owner_name", "隨緣");
        set_temp("owner", "looker");
        set_temp("owner_name", "隨緣");
        ::setup();
}
