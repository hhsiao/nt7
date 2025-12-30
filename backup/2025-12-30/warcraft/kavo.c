// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("初現[2;37;0m[2;37;0m", ({"kavk"}));        
        set("gender", "女性");                
        set("long", "初現[2;37;0m
它是初見的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kavo");
        set("owner_name", "初見");
        set_temp("owner", "kavo");
        set_temp("owner_name", "初見");
        ::setup();
}
