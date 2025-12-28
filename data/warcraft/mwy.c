// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("無雨虎[2;37;0m[2;37;0m", ({"wuyu"}));        
        set("gender", "男性");                
        set("long", "無雨虎[2;37;0m
它是魔無雨的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "mwy");
        set("owner_name", "魔無雨");
        set_temp("owner", "mwy");
        set_temp("owner_name", "魔無雨");
        ::setup();
}
