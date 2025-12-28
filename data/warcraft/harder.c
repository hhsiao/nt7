// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("火麒麟[2;37;0m[2;37;0m", ({"qilin"}));        
        set("gender", "男性");                
        set("long", "火眼麒麟[2;37;0m
它是軒轅重出的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "harder");
        set("owner_name", "軒轅重出");
        set_temp("owner", "harder");
        set_temp("owner_name", "軒轅重出");
        ::setup();
}
