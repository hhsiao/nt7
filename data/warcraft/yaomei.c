// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m吡咯[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "上古神獸[2;37;0m
它是柳輕風的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yaomei");
        set("owner_name", "柳輕風");
        set_temp("owner", "yaomei");
        set_temp("owner_name", "柳輕風");
        ::setup();
}
