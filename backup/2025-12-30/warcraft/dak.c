// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"kad"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是尺素的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dak");
        set("owner_name", "尺素");
        set_temp("owner", "dak");
        set_temp("owner_name", "尺素");
        ::setup();
}
