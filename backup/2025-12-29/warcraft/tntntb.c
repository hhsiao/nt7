// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("柏芝[2;37;0m[2;37;0m", ({"bozi"}));        
        set("gender", "男性");                
        set("long", "柏芝[2;37;0m
它是鍾離權的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tntntb");
        set("owner_name", "鍾離權");
        set_temp("owner", "tntntb");
        set_temp("owner_name", "鍾離權");
        ::setup();
}
