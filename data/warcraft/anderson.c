// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("火車[2;37;0m[2;37;0m", ({"uub"}));        
        set("gender", "男性");                
        set("long", "火車[2;37;0m
它是可愛薯條的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "anderson");
        set("owner_name", "可愛薯條");
        set_temp("owner", "anderson");
        set_temp("owner_name", "可愛薯條");
        ::setup();
}
