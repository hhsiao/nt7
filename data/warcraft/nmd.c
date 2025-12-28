// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("坐騎[2;37;0m[2;37;0m", ({"nmride"}));        
        set("gender", "女性");                
        set("long", "@ridename[2;37;0m
它是清魚的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nmd");
        set("owner_name", "清魚");
        set_temp("owner", "nmd");
        set_temp("owner_name", "清魚");
        ::setup();
}
