// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m鳳飛[2;37;0m[2;37;0m", ({"flying"}));        
        set("gender", "女性");                
        set("long", "$RED$鳳飛[2;37;0m
它是楚雪的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xsckr");
        set("owner_name", "楚雪");
        set_temp("owner", "xsckr");
        set_temp("owner_name", "楚雪");
        ::setup();
}
