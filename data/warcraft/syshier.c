// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("瘋狂獅子[2;37;0m[2;37;0m", ({"mushiz"}));        
        set("gender", "女性");                
        set("long", "瘋狂獅子—做愛瘋狂無止境[2;37;0m
它是霸劍盟的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "syshier");
        set("owner_name", "霸劍盟");
        set_temp("owner", "syshier");
        set_temp("owner_name", "霸劍盟");
        ::setup();
}
