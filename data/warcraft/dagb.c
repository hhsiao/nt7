// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("火鳳凰[2;37;0m[2;37;0m", ({"xiaoq"}));        
        set("gender", "女性");                
        set("long", "火鳳凰[2;37;0m
它是丹書的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dagb");
        set("owner_name", "丹書");
        set_temp("owner", "dagb");
        set_temp("owner_name", "丹書");
        ::setup();
}
