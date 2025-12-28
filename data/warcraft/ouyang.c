// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("騾子[2;37;0m[2;37;0m", ({"luozi"}));        
        set("gender", "男性");                
        set("long", "面向黃土，背向天，一天就知道幹活[2;37;0m
它是歐陽殺的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ouyang");
        set("owner_name", "歐陽殺");
        set_temp("owner", "ouyang");
        set_temp("owner_name", "歐陽殺");
        ::setup();
}
