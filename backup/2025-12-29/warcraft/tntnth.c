// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("柏芝[2;37;0m[2;37;0m", ({"bozi"}));        
        set("gender", "男性");                
        set("long", "柏芝[2;37;0m
它是韓翔子的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tntnth");
        set("owner_name", "韓翔子");
        set_temp("owner", "tntnth");
        set_temp("owner_name", "韓翔子");
        ::setup();
}
