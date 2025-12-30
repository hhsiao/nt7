// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛飛[2;37;0m[2;37;0m", ({"flydd"}));        
        set("gender", "男性");                
        set("long", "飛飛[2;37;0m
它是飛寵物的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "testpata");
        set("owner_name", "飛寵物");
        set_temp("owner", "testpata");
        set_temp("owner_name", "飛寵物");
        ::setup();
}
