// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("偷[2;37;0m[2;37;0m", ({"atx"}));        
        set("gender", "女性");                
        set("long", "偷[2;37;0m
它是偷採啊的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "txa");
        set("owner_name", "偷採啊");
        set_temp("owner", "txa");
        set_temp("owner_name", "偷採啊");
        ::setup();
}
