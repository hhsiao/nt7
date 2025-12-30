// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[36m淺[1;31m斟[33m低[1;37m唱[2;37;0m[2;37;0m", ({"sigh"}));        
        set("gender", "女性");                
        set("long", "天地第一獸[2;37;0m
它是視界的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xyaa");
        set("owner_name", "視界");
        set_temp("owner", "xyaa");
        set_temp("owner_name", "視界");
        ::setup();
}
