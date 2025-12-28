// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("香香公主[2;37;0m[2;37;0m", ({"wudulong"}));        
        set("gender", "女性");                
        set("long", "執行[2;37;0m
它是降頭師的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wudu");
        set("owner_name", "降頭師");
        set_temp("owner", "wudu");
        set_temp("owner_name", "降頭師");
        ::setup();
}
