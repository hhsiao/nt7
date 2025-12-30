// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("哦歲的河南[2;37;0m[2;37;0m", ({"cib"}));        
        set("gender", "男性");                
        set("long", "哦歲的河南[2;37;0m
它是葡萄酒號的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lyi");
        set("owner_name", "葡萄酒號");
        set_temp("owner", "lyi");
        set_temp("owner_name", "葡萄酒號");
        ::setup();
}
