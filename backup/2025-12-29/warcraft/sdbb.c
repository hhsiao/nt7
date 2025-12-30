// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("潛龍[2;37;0m[2;37;0m", ({"sdbaa"}));        
        set("gender", "男性");                
        set("long", "無所不及[2;37;0m
它是天空二號的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "sdbb");
        set("owner_name", "天空二號");
        set_temp("owner", "sdbb");
        set_temp("owner_name", "天空二號");
        ::setup();
}
