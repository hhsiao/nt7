// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m本體[1;31m五嗚[2;37;0m[2;37;0m", ({"wwee"}));        
        set("gender", "女性");                
        set("long", "嗚嗚[2;37;0m
它是五嗚嗚的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wwe");
        set("owner_name", "五嗚嗚");
        set_temp("owner", "wwe");
        set_temp("owner_name", "五嗚嗚");
        ::setup();
}
