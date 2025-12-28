// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m鋼索[2;37;0m[2;37;0m", ({"gang"}));        
        set("gender", "女性");                
        set("long", "$HIC$鋼索[2;37;0m
它是龍飛的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "sdckr");
        set("owner_name", "龍飛");
        set_temp("owner", "sdckr");
        set_temp("owner_name", "龍飛");
        ::setup();
}
