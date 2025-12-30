// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("跟飛翔[2;37;0m[2;37;0m", ({"xixiggg"}));        
        set("gender", "女性");                
        set("long", "自由的飛翔[2;37;0m
它是習跟的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xixig");
        set("owner_name", "習跟");
        set_temp("owner", "xixig");
        set_temp("owner_name", "習跟");
        ::setup();
}
