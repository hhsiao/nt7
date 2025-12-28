// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("從一飛翔[2;37;0m[2;37;0m", ({"forceaa"}));        
        set("gender", "女性");                
        set("long", "自由的飛翔[2;37;0m
它是內力從六的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "forceliu");
        set("owner_name", "內力從六");
        set_temp("owner", "forceliu");
        set_temp("owner_name", "內力從六");
        ::setup();
}
