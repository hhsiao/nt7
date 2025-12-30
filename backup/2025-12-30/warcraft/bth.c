// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("娜可露露[2;37;0m[2;37;0m", ({"omo"}));        
        set("gender", "女性");                
        set("long", "請描述魔幻獸[2;37;0m
它是周倉叄的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "bth");
        set("owner_name", "周倉叄");
        set_temp("owner", "bth");
        set_temp("owner_name", "周倉叄");
        ::setup();
}
