// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m狂[1;37m風[1;31m驟[1;32m雨[2;37;0m[2;37;0m", ({"kuangfeng"}));        
        set("gender", "男性");                
        set("long", "狂風驟雨[2;37;0m
它是笑傲江湖的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "pking");
        set("owner_name", "笑傲江湖");
        set_temp("owner", "pking");
        set_temp("owner_name", "笑傲江湖");
        ::setup();
}
