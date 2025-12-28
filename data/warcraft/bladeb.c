// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("媚兒[2;37;0m[2;37;0m", ({"bladeblong"}));        
        set("gender", "男性");                
        set("long", "焓秦遙[2;37;0m
它是刀疤強的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "bladeb");
        set("owner_name", "刀疤強");
        set_temp("owner", "bladeb");
        set_temp("owner_name", "刀疤強");
        ::setup();
}
