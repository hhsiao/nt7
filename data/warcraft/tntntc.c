// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("柏芝[2;37;0m[2;37;0m", ({"bozi"}));        
        set("gender", "男性");                
        set("long", "柏芝[2;37;0m
它是呂東賓的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tntntc");
        set("owner_name", "呂東賓");
        set_temp("owner", "tntntc");
        set_temp("owner_name", "呂東賓");
        ::setup();
}
