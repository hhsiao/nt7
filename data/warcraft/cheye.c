// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("火車王[2;37;0m[2;37;0m", ({"help_nick"}));        
        set("gender", "女性");                
        set("long", "火車王[2;37;0m
它是徹夜的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "cheye");
        set("owner_name", "徹夜");
        set_temp("owner", "cheye");
        set_temp("owner_name", "徹夜");
        ::setup();
}
