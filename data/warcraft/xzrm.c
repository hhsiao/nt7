// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("地圖精[2;37;0m[2;37;0m", ({"maphere"}));        
        set("gender", "男性");                
        set("long", "23456[2;37;0m
它是出雲未羊的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "xzrm");
        set("owner_name", "出雲未羊");
        set_temp("owner", "xzrm");
        set_temp("owner_name", "出雲未羊");
        ::setup();
}
