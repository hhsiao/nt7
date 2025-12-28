// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"long"}));        
        set("gender", "男性");                
        set("long", "一頭若隱若現的巨龍[2;37;0m
它是仇恕的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "choushu");
        set("owner_name", "仇恕");
        set_temp("owner", "choushu");
        set_temp("owner_name", "仇恕");
        ::setup();
}
