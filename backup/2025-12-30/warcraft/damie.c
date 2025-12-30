// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("騾子[2;37;0m[2;37;0m", ({"damiee"}));        
        set("gender", "男性");                
        set("long", "df[2;37;0m
它是藥販子五的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "damie");
        set("owner_name", "藥販子五");
        set_temp("owner", "damie");
        set_temp("owner_name", "藥販子五");
        ::setup();
}
