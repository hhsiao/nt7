// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("柏芝[2;37;0m[2;37;0m", ({"bozi"}));        
        set("gender", "男性");                
        set("long", "柏芝[2;37;0m
它是龍八的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tntntl");
        set("owner_name", "龍八");
        set_temp("owner", "tntntl");
        set_temp("owner_name", "龍八");
        ::setup();
}
