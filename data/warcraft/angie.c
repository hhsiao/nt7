// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m太古金焱鳳[2;37;0m[2;37;0m", ({"slash"}));        
        set("gender", "女性");                
        set("long", "太古金焱鳳[2;37;0m
它是白素貞的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "angie");
        set("owner_name", "白素貞");
        set_temp("owner", "angie");
        set_temp("owner_name", "白素貞");
        ::setup();
}
