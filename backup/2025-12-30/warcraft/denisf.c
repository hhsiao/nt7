// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("寶馬[2;37;0m[2;37;0m", ({"ziqiang"}));        
        set("gender", "男性");                
        set("long", "寶馬[2;37;0m
它是自強不息的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "denisf");
        set("owner_name", "自強不息");
        set_temp("owner", "denisf");
        set_temp("owner_name", "自強不息");
        ::setup();
}
