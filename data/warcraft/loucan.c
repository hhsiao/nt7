// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("風捲[2;37;0m[2;37;0m", ({"fengjuan"}));        
        set("gender", "女性");                
        set("long", "風捲[2;37;0m
它是風捲樓殘的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "loucan");
        set("owner_name", "風捲樓殘");
        set_temp("owner", "loucan");
        set_temp("owner_name", "風捲樓殘");
        ::setup();
}
