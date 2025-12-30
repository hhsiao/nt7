// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小青[2;37;0m[2;37;0m", ({"ebeb"}));        
        set("gender", "男性");                
        set("long", "一條小青龍[2;37;0m
它是透視的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ebebeb");
        set("owner_name", "透視");
        set_temp("owner", "ebebeb");
        set_temp("owner_name", "透視");
        ::setup();
}
