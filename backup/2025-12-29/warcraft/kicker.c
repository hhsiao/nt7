// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大馬[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "大馬[2;37;0m
它是踢腳的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kicker");
        set("owner_name", "踢腳");
        set_temp("owner", "kicker");
        set_temp("owner_name", "踢腳");
        ::setup();
}
