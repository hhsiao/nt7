// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("互動[2;37;0m[2;37;0m", ({"oko"}));        
        set("gender", "男性");                
        set("long", "人[2;37;0m
它是合得來的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "lntv");
        set("owner_name", "合得來");
        set_temp("owner", "lntv");
        set_temp("owner_name", "合得來");
        ::setup();
}
