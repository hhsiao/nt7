// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m緣起[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "緣起[2;37;0m
它是緣滅的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "msy");
        set("owner_name", "緣滅");
        set_temp("owner", "msy");
        set_temp("owner_name", "緣滅");
        ::setup();
}
