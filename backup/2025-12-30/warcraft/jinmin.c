// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("金龍[2;37;0m[2;37;0m", ({"jmlong"}));        
        set("gender", "男性");                
        set("long", "金皿的龍 [2;37;0m
它是金皿的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jinmin");
        set("owner_name", "金皿");
        set_temp("owner", "jinmin");
        set_temp("owner_name", "金皿");
        ::setup();
}
