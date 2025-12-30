// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("七零[2;37;0m[2;37;0m", ({"baoma"}));        
        set("gender", "男性");                
        set("long", "ask jiangong about 採礦[2;37;0m
它是皮厚會反的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kzguiji");
        set("owner_name", "皮厚會反");
        set_temp("owner", "kzguiji");
        set_temp("owner_name", "皮厚會反");
        ::setup();
}
