// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("終生之盟友[2;37;0m[2;37;0m", ({"xiaoq"}));        
        set("gender", "男性");                
        set("long", "終生之盟友[2;37;0m
它是試煙的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "wwxx");
        set("owner_name", "試煙");
        set_temp("owner", "wwxx");
        set_temp("owner_name", "試煙");
        ::setup();
}
