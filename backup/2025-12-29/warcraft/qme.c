// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m翱翔鳳凰[2;37;0m[2;37;0m", ({"qmee"}));        
        set("gender", "女性");                
        set("long", "翱翔鳳凰[2;37;0m
它是草原清風的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "qme");
        set("owner_name", "草原清風");
        set_temp("owner", "qme");
        set_temp("owner_name", "草原清風");
        ::setup();
}
