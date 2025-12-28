// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("啊粗大[2;37;0m[2;37;0m", ({"zxcc"}));        
        set("gender", "男性");                
        set("long", "啊粗大[2;37;0m
它是奧術這些的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "zxc");
        set("owner_name", "奧術這些");
        set_temp("owner", "zxc");
        set_temp("owner_name", "奧術這些");
        ::setup();
}
