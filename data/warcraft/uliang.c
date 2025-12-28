// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m墨魚[2;37;0m[2;37;0m", ({"mql"}));        
        set("gender", "男性");                
        set("long", "墨魚噢[2;37;0m
它是冒牌紅手的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "uliang");
        set("owner_name", "冒牌紅手");
        set_temp("owner", "uliang");
        set_temp("owner_name", "冒牌紅手");
        ::setup();
}
