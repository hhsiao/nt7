// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("地圖精[2;37;0m[2;37;0m", ({"maphere"}));        
        set("gender", "男性");                
        set("long", "23456[2;37;0m
它是出雲巳蛇的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "xzrk");
        set("owner_name", "出雲巳蛇");
        set_temp("owner", "xzrk");
        set_temp("owner_name", "出雲巳蛇");
        ::setup();
}
