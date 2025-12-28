// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("鵝鵝鵝[2;37;0m[2;37;0m", ({"yaoeee"}));        
        set("gender", "男性");                
        set("long", "鵝鵝鵝[2;37;0m
它是藥夜夜的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yaoee");
        set("owner_name", "藥夜夜");
        set_temp("owner", "yaoee");
        set_temp("owner_name", "藥夜夜");
        ::setup();
}
