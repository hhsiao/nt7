// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("哼哈[2;37;0m[2;37;0m", ({"ggrain"}));        
        set("gender", "男性");                
        set("long", "哼哈[2;37;0m
它是飄渺雲雨的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "grain");
        set("owner_name", "飄渺雲雨");
        set_temp("owner", "grain");
        set_temp("owner_name", "飄渺雲雨");
        ::setup();
}
