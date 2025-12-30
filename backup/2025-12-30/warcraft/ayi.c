// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("意義[2;37;0m[2;37;0m", ({"yiyi"}));        
        set("gender", "男性");                
        set("long", "意義[2;37;0m
它是阿乙的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ayi");
        set("owner_name", "阿乙");
        set_temp("owner", "ayi");
        set_temp("owner_name", "阿乙");
        ::setup();
}
