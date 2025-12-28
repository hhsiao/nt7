// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火鳳凰[1;31m[2;37;0m[2;37;0m", ({"businiao"}));        
        set("gender", "女性");                
        set("long", "火鳳凰[2;37;0m
它是粽五的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "zrze");
        set("owner_name", "粽五");
        set_temp("owner", "zrze");
        set_temp("owner_name", "粽五");
        ::setup();
}
