// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m小青龍[2;37;0m[2;37;0m", ({"myshou"}));        
        set("gender", "男性");                
        set("long", "四大神獸之一[2;37;0m
它是海納的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "minixx");
        set("owner_name", "海納");
        set_temp("owner", "minixx");
        set_temp("owner_name", "海納");
        ::setup();
}
