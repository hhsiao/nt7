// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("張麗華[2;37;0m[2;37;0m", ({"wenlong"}));        
        set("gender", "男性");                
        set("long", "窩藏[2;37;0m
它是文鴦的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wenyang");
        set("owner_name", "文鴦");
        set_temp("owner", "wenyang");
        set_temp("owner_name", "文鴦");
        ::setup();
}
