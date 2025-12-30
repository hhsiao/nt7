// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m華山破騎士[2;37;0m[2;37;0m", ({"qmff"}));        
        set("gender", "女性");                
        set("long", "華山破騎士[2;37;0m
它是華山清風的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "qmf");
        set("owner_name", "華山清風");
        set_temp("owner", "qmf");
        set_temp("owner_name", "華山清風");
        ::setup();
}
