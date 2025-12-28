// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m雪[2;37;0m[2;37;0m", ({"bai"}));        
        set("gender", "男性");                
        set("long", "坐騎[2;37;0m
它是歐陽空的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "lakin");
        set("owner_name", "歐陽空");
        set_temp("owner", "lakin");
        set_temp("owner_name", "歐陽空");
        ::setup();
}
