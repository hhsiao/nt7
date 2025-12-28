// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m汗血寶馬[2;37;0m[2;37;0m", ({"bmw"}));        
        set("gender", "女性");                
        set("long", "氣死富二代，不讓官二代[2;37;0m
它是郭芙的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "guofu");
        set("owner_name", "郭芙");
        set_temp("owner", "guofu");
        set_temp("owner_name", "郭芙");
        ::setup();
}
