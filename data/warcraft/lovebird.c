// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m雷龍[2;37;0m[2;37;0m", ({"birdbird"}));        
        set("gender", "男性");                
        set("long", "雷龍[2;37;0m
它是慕鳥飛的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lovebird");
        set("owner_name", "慕鳥飛");
        set_temp("owner", "lovebird");
        set_temp("owner_name", "慕鳥飛");
        ::setup();
}
