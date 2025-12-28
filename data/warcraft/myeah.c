// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m太古小青龍[2;37;0m[2;37;0m", ({"dragon"}));        
        set("gender", "男性");                
        set("long", "太古小青龍[2;37;0m
它是邁越的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "myeah");
        set("owner_name", "邁越");
        set_temp("owner", "myeah");
        set_temp("owner_name", "邁越");
        ::setup();
}
