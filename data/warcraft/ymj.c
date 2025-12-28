// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m[5m麒[1;34m[5m麟[2;37;0m[2;37;0m", ({"qiling"}));        
        set("gender", "女性");                
        set("long", "麒麟[2;37;0m
它是葉美景的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "ymj");
        set("owner_name", "葉美景");
        set_temp("owner", "ymj");
        set_temp("owner_name", "葉美景");
        ::setup();
}
