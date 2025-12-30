// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("柏芝[2;37;0m[2;37;0m", ({"bozi"}));        
        set("gender", "男性");                
        set("long", "柏芝[2;37;0m
它是天樞子的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xmdmc");
        set("owner_name", "天樞子");
        set_temp("owner", "xmdmc");
        set_temp("owner_name", "天樞子");
        ::setup();
}
