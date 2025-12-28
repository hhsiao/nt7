// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("快車[2;37;0m[2;37;0m", ({"kkkkk"}));        
        set("gender", "男性");                
        set("long", "快車[2;37;0m
它是俊俊的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "junchen");
        set("owner_name", "俊俊");
        set_temp("owner", "junchen");
        set_temp("owner_name", "俊俊");
        ::setup();
}
