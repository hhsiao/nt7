// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("坐騎寶寶[2;37;0m[2;37;0m", ({"zuoqibaobao"}));        
        set("gender", "女性");                
        set("long", "坐騎寶寶[2;37;0m
它是血劍盟的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "syshiyi");
        set("owner_name", "血劍盟");
        set_temp("owner", "syshiyi");
        set_temp("owner_name", "血劍盟");
        ::setup();
}
