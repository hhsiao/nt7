// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔門[2;37;0m[2;37;0m", ({"axx"}));        
        set("gender", "男性");                
        set("long", "sad[2;37;0m
它是須彌的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "uranium");
        set("owner_name", "須彌");
        set_temp("owner", "uranium");
        set_temp("owner_name", "須彌");
        ::setup();
}
