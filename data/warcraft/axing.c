// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"xing"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是冰曉的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "axing");
        set("owner_name", "冰曉");
        set_temp("owner", "axing");
        set_temp("owner_name", "冰曉");
        ::setup();
}
