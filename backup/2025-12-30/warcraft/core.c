// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("雲朵[2;37;0m[2;37;0m", ({"horse"}));        
        set("gender", "男性");                
        set("long", "unset no_accept[2;37;0m
它是莎娜的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "core");
        set("owner_name", "莎娜");
        set_temp("owner", "core");
        set_temp("owner_name", "莎娜");
        ::setup();
}
