// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m本體[1;31m二嗚[2;37;0m[2;37;0m", ({"wwbb"}));        
        set("gender", "女性");                
        set("long", "嗚嗚[2;37;0m
它是二嗚嗚的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wwb");
        set("owner_name", "二嗚嗚");
        set_temp("owner", "wwb");
        set_temp("owner_name", "二嗚嗚");
        ::setup();
}
