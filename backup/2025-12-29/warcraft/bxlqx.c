// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("撿垃圾[2;37;0m[2;37;0m", ({"bbxlqx"}));        
        set("gender", "男性");                
        set("long", "撿垃圾[2;37;0m
它是東方星的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "bxlqx");
        set("owner_name", "東方星");
        set_temp("owner", "bxlqx");
        set_temp("owner_name", "東方星");
        ::setup();
}
