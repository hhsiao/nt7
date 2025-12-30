// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m黃金神龍[2;37;0m[2;37;0m", ({"shenlong"}));        
        set("gender", "男性");                
        set("long", "就是一條龍而已[2;37;0m
它是重小樓的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "woacs");
        set("owner_name", "重小樓");
        set_temp("owner", "woacs");
        set_temp("owner_name", "重小樓");
        ::setup();
}
