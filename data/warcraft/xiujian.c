// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("曉曉[2;37;0m[2;37;0m", ({"xiaoxiao"}));        
        set("gender", "男性");                
        set("long", "這是一隻小小的麒麟。[2;37;0m
它是鏽劍的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xiujian");
        set("owner_name", "鏽劍");
        set_temp("owner", "xiujian");
        set_temp("owner_name", "鏽劍");
        ::setup();
}
