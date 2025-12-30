// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "一條龍[2;37;0m
它是李二二的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "cwudang");
        set("owner_name", "李二二");
        set_temp("owner", "cwudang");
        set_temp("owner_name", "李二二");
        ::setup();
}
