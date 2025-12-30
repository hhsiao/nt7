// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"sss"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是海豹的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "haibao");
        set("owner_name", "海豹");
        set_temp("owner", "haibao");
        set_temp("owner_name", "海豹");
        ::setup();
}
