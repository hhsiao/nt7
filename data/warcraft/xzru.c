// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("地圖精[2;37;0m[2;37;0m", ({"maphere"}));        
        set("gender", "男性");                
        set("long", "23456[2;37;0m
它是克萊斯勒的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "xzru");
        set("owner_name", "克萊斯勒");
        set_temp("owner", "xzru");
        set_temp("owner_name", "克萊斯勒");
        ::setup();
}
