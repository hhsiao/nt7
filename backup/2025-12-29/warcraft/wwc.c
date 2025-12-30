// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m本體[1;31m三嗚[2;37;0m[2;37;0m", ({"wwcc"}));        
        set("gender", "女性");                
        set("long", "嗚嗚[2;37;0m
它是三嗚嗚的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wwc");
        set("owner_name", "三嗚嗚");
        set_temp("owner", "wwc");
        set_temp("owner_name", "三嗚嗚");
        ::setup();
}
