// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是日月的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "riri");
        set("owner_name", "日月");
        set_temp("owner", "riri");
        set_temp("owner_name", "日月");
        ::setup();
}
