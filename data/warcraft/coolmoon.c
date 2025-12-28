// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("淫蕩情人[2;37;0m[2;37;0m", ({"aimin"}));        
        set("gender", "女性");                
        set("long", "一頭很淫蕩的.....[2;37;0m
它是幽林清風的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "coolmoon");
        set("owner_name", "幽林清風");
        set_temp("owner", "coolmoon");
        set_temp("owner_name", "幽林清風");
        ::setup();
}
