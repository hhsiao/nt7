// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[35m龍三太子[2;37;0m[2;37;0m", ({"dragon"}));        
        set("gender", "男性");                
        set("long", "一隻小青龍[2;37;0m
它是明月的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "mingy");
        set("owner_name", "明月");
        set_temp("owner", "mingy");
        set_temp("owner_name", "明月");
        ::setup();
}
