// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老馬[2;37;0m[2;37;0m", ({"laoma"}));        
        set("gender", "男性");                
        set("long", "老馬[2;37;0m
它是蕾絲的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "kkasvw");
        set("owner_name", "蕾絲");
        set_temp("owner", "kkasvw");
        set_temp("owner_name", "蕾絲");
        ::setup();
}
