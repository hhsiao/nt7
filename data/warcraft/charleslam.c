// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("獨角獸[2;37;0m[2;37;0m", ({"unicorn"}));        
        set("gender", "男性");                
        set("long", "這是一隻獨角獸[2;37;0m
它是布朗的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "charleslam");
        set("owner_name", "布朗");
        set_temp("owner", "charleslam");
        set_temp("owner_name", "布朗");
        ::setup();
}
