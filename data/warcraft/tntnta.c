// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("柏芝[2;37;0m[2;37;0m", ({"bozi"}));        
        set("gender", "男性");                
        set("long", "柏芝[2;37;0m
它是鐵柺李的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tntnta");
        set("owner_name", "鐵柺李");
        set_temp("owner", "tntnta");
        set_temp("owner_name", "鐵柺李");
        ::setup();
}
