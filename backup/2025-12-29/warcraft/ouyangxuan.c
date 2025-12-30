// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("漢生麒麟[2;37;0m[2;37;0m", ({"ouyangxuanride"}));        
        set("gender", "男性");                
        set("long", "漢生麒麟[2;37;0m
它是歐陽漢生的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ouyangxuan");
        set("owner_name", "歐陽漢生");
        set_temp("owner", "ouyangxuan");
        set_temp("owner_name", "歐陽漢生");
        ::setup();
}
