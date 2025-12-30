// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("地圖精[2;37;0m[2;37;0m", ({"maphere"}));        
        set("gender", "男性");                
        set("long", "23456[2;37;0m
它是無所謂的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "nslj");
        set("owner_name", "無所謂");
        set_temp("owner", "nslj");
        set_temp("owner_name", "無所謂");
        ::setup();
}
