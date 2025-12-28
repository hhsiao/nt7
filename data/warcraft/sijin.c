// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("錦似[2;37;0m[2;37;0m", ({"jinsi"}));        
        set("gender", "女性");                
        set("long", "錦似[2;37;0m
它是似錦的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "sijin");
        set("owner_name", "似錦");
        set_temp("owner", "sijin");
        set_temp("owner_name", "似錦");
        ::setup();
}
