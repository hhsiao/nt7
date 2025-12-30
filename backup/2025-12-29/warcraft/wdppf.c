// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("的了[2;37;0m[2;37;0m", ({"mygift"}));        
        set("gender", "女性");                
        set("long", "的了[2;37;0m
它是武當師六的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wdppf");
        set("owner_name", "武當師六");
        set_temp("owner", "wdppf");
        set_temp("owner_name", "武當師六");
        ::setup();
}
