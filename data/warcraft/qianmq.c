// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老馬[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "老馬[2;37;0m
它是夏花依舊的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "qianmq");
        set("owner_name", "夏花依舊");
        set_temp("owner", "qianmq");
        set_temp("owner_name", "夏花依舊");
        ::setup();
}
