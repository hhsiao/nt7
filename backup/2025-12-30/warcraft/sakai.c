// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;31m麒[1;35m麟[1;36m王[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "混沌初開的第一隻麒麟，也是麒麟一族族長[2;37;0m
它是靈風的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "sakai");
        set("owner_name", "靈風");
        set_temp("owner", "sakai");
        set_temp("owner_name", "靈風");
        ::setup();
}
