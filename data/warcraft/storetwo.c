// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("倉庫車[2;37;0m[2;37;0m", ({"store"}));        
        set("gender", "男性");                
        set("long", "倉庫車[2;37;0m
它是符石倉庫的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "storetwo");
        set("owner_name", "符石倉庫");
        set_temp("owner", "storetwo");
        set_temp("owner_name", "符石倉庫");
        ::setup();
}
