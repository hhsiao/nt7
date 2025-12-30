// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("上島咖啡鹼[2;37;0m[2;37;0m", ({"cib"}));        
        set("gender", "女性");                
        set("long", "上島咖啡鹼[2;37;0m
它是葡萄三號的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lyc");
        set("owner_name", "葡萄三號");
        set_temp("owner", "lyc");
        set_temp("owner_name", "葡萄三號");
        ::setup();
}
