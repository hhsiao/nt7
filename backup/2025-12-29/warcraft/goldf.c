// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "女性");                
        set("long", "麒麟[2;37;0m
它是錢六的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "goldf");
        set("owner_name", "錢六");
        set_temp("owner", "goldf");
        set_temp("owner_name", "錢六");
        ::setup();
}
