// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m龜龜[2;37;0m[2;37;0m", ({"asd"}));        
        set("gender", "男性");                
        set("long", "$HIG$龜龜[2;37;0m
它是四道風的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "sdf");
        set("owner_name", "四道風");
        set_temp("owner", "sdf");
        set_temp("owner_name", "四道風");
        ::setup();
}
