// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "女性");                
        set("long", "一頭麒麟[2;37;0m
它是里奧納多的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "emsj");
        set("owner_name", "里奧納多");
        set_temp("owner", "emsj");
        set_temp("owner_name", "里奧納多");
        ::setup();
}
