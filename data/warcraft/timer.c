// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m鳳[1;31m凰[2;37;0m[2;37;0m", ({"time"}));        
        set("gender", "女性");                
        set("long", "飛[2;37;0m
它是荊無命的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "timer");
        set("owner_name", "荊無命");
        set_temp("owner", "timer");
        set_temp("owner_name", "荊無命");
        ::setup();
}
