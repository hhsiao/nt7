// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("礦龍的[2;37;0m[2;37;0m", ({"huanlong"}));        
        set("gender", "男性");                
        set("long", "礦龍的[2;37;0m
它是衣服的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kub");
        set("owner_name", "衣服");
        set_temp("owner", "kub");
        set_temp("owner_name", "衣服");
        ::setup();
}
