// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m本體[1;31m大嗚[2;37;0m[2;37;0m", ({"wwaa"}));        
        set("gender", "女性");                
        set("long", "嗚嗚[2;37;0m
它是大嗚嗚的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wwa");
        set("owner_name", "大嗚嗚");
        set_temp("owner", "wwa");
        set_temp("owner_name", "大嗚嗚");
        ::setup();
}
