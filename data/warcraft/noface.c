// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("沒臉騎[2;37;0m[2;37;0m", ({"nofaceride"}));        
        set("gender", "男性");                
        set("long", "沒臉騎[2;37;0m
它是無顏的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "noface");
        set("owner_name", "無顏");
        set_temp("owner", "noface");
        set_temp("owner_name", "無顏");
        ::setup();
}
