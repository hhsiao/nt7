// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("地圖精[2;37;0m[2;37;0m", ({"maphere"}));        
        set("gender", "男性");                
        set("long", "qwe[2;37;0m
它是出雲戌狗的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "xzrp");
        set("owner_name", "出雲戌狗");
        set_temp("owner", "xzrp");
        set_temp("owner_name", "出雲戌狗");
        ::setup();
}
