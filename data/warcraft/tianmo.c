// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火鳳凰[2;37;0m[2;37;0m", ({"phonix"}));        
        set("gender", "女性");                
        set("long", "浴火重生的鳳凰神獸。[2;37;0m
它是天魔的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tianmo");
        set("owner_name", "天魔");
        set_temp("owner", "tianmo");
        set_temp("owner_name", "天魔");
        ::setup();
}
