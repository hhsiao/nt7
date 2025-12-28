// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("貸款金額哦[2;37;0m[2;37;0m", ({"cib"}));        
        set("gender", "男性");                
        set("long", "貸款金額哦[2;37;0m
它是葡萄四號的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lyd");
        set("owner_name", "葡萄四號");
        set_temp("owner", "lyd");
        set_temp("owner_name", "葡萄四號");
        ::setup();
}
