// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("寶寶[2;37;0m[2;37;0m", ({"baobao"}));        
        set("gender", "男性");                
        set("long", "我心愛的[2;37;0m
它是沈三兒的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "supbaby");
        set("owner_name", "沈三兒");
        set_temp("owner", "supbaby");
        set_temp("owner_name", "沈三兒");
        ::setup();
}
