// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("費飛翔[2;37;0m[2;37;0m", ({"xixifff"}));        
        set("gender", "女性");                
        set("long", "自由的飛翔[2;37;0m
它是習費的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xixif");
        set("owner_name", "習費");
        set_temp("owner", "xixif");
        set_temp("owner_name", "習費");
        ::setup();
}
