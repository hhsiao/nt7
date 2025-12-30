// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("終極彩民[2;37;0m[2;37;0m", ({"aaxlqx"}));        
        set("gender", "男性");                
        set("long", "終極彩民[2;37;0m
它是令狐星的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "axlqx");
        set("owner_name", "令狐星");
        set_temp("owner", "axlqx");
        set_temp("owner_name", "令狐星");
        ::setup();
}
