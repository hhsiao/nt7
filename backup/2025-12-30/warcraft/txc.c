// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("成[2;37;0m[2;37;0m", ({"ctx"}));        
        set("gender", "女性");                
        set("long", "成[2;37;0m
它是偷採成的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "txc");
        set("owner_name", "偷採成");
        set_temp("owner", "txc");
        set_temp("owner_name", "偷採成");
        ::setup();
}
