// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("士大夫[2;37;0m[2;37;0m", ({"wee"}));        
        set("gender", "男性");                
        set("long", "士大[2;37;0m
它是破頗的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "popo");
        set("owner_name", "破頗");
        set_temp("owner", "popo");
        set_temp("owner_name", "破頗");
        ::setup();
}
