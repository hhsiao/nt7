// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟怪[2;37;0m[2;37;0m", ({"kiringwai"}));        
        set("gender", "男性");                
        set("long", "這是傳說中的神獸麒麟怪。[2;37;0m
它是樂海的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kychung");
        set("owner_name", "樂海");
        set_temp("owner", "kychung");
        set_temp("owner_name", "樂海");
        ::setup();
}
