// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("足球[2;37;0m[2;37;0m", ({"zhuqiu"}));        
        set("gender", "男性");                
        set("long", "這是一隻足球。[2;37;0m
它是西帥的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "verdisha");
        set("owner_name", "西帥");
        set_temp("owner", "verdisha");
        set_temp("owner_name", "西帥");
        ::setup();
}
