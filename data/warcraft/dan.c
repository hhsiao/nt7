// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m淡定[2;37;0m[2;37;0m", ({"danding"}));        
        set("gender", "女性");                
        set("long", "哈哈[2;37;0m
它是丹藥的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "dan");
        set("owner_name", "丹藥");
        set_temp("owner", "dan");
        set_temp("owner_name", "丹藥");
        ::setup();
}
