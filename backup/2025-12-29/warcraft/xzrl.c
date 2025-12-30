// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("地圖精[2;37;0m[2;37;0m", ({"maphere"}));        
        set("gender", "男性");                
        set("long", "23456[2;37;0m
它是出雲午馬的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "xzrl");
        set("owner_name", "出雲午馬");
        set_temp("owner", "xzrl");
        set_temp("owner_name", "出雲午馬");
        ::setup();
}
