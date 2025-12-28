// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔龍[2;37;0m[2;37;0m", ({"drogn"}));        
        set("gender", "男性");                
        set("long", "魔龍[2;37;0m
它是那年風雨的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xiaole");
        set("owner_name", "那年風雨");
        set_temp("owner", "xiaole");
        set_temp("owner_name", "那年風雨");
        ::setup();
}
