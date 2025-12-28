// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"hell"}));        
        set("gender", "女性");                
        set("long", "龍[2;37;0m
它是江南一劍的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "zhai");
        set("owner_name", "江南一劍");
        set_temp("owner", "zhai");
        set_temp("owner_name", "江南一劍");
        ::setup();
}
