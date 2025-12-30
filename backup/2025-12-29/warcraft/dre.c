// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火鳥[2;37;0m[2;37;0m", ({"bird"}));        
        set("gender", "男性");                
        set("long", "鳥一隻[2;37;0m
它是段米的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dre");
        set("owner_name", "段米");
        set_temp("owner", "dre");
        set_temp("owner_name", "段米");
        ::setup();
}
