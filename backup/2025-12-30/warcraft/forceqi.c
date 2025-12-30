// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("從二飛翔[2;37;0m[2;37;0m", ({"forcebb"}));        
        set("gender", "女性");                
        set("long", "自由的飛翔[2;37;0m
它是內力從七的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "forceqi");
        set("owner_name", "內力從七");
        set_temp("owner", "forceqi");
        set_temp("owner_name", "內力從七");
        ::setup();
}
