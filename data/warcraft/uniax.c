// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("兔兔[2;37;0m[2;37;0m", ({"tutu"}));        
        set("gender", "男性");                
        set("long", "這是一隻可愛的小白兔[2;37;0m
它是風千越的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "uniax");
        set("owner_name", "風千越");
        set_temp("owner", "uniax");
        set_temp("owner_name", "風千越");
        ::setup();
}
