// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("可心[2;37;0m[2;37;0m", ({"lylyly"}));        
        set("gender", "男性");                
        set("long", "可信[2;37;0m
它是董無傷的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "lyineta");
        set("owner_name", "董無傷");
        set_temp("owner", "lyineta");
        set_temp("owner_name", "董無傷");
        ::setup();
}
