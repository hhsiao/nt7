// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("壹[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "壹[2;37;0m
它是風一的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ianka");
        set("owner_name", "風一");
        set_temp("owner", "ianka");
        set_temp("owner_name", "風一");
        ::setup();
}
