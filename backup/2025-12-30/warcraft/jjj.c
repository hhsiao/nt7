// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("華山小[2;37;0m[2;37;0m", ({"sss"}));        
        set("gender", "女性");                
        set("long", "華山小[2;37;0m
它是華山大的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "jjj");
        set("owner_name", "華山大");
        set_temp("owner", "jjj");
        set_temp("owner_name", "華山大");
        ::setup();
}
