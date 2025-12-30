// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大鳥[2;37;0m[2;37;0m", ({"vlv"}));        
        set("gender", "女性");                
        set("long", "111[2;37;0m
它是斯巴魯的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "volvo");
        set("owner_name", "斯巴魯");
        set_temp("owner", "volvo");
        set_temp("owner_name", "斯巴魯");
        ::setup();
}
