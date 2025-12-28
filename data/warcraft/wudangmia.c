// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("烏當三米麒麟[2;37;0m[2;37;0m", ({"wudangmiaqilin"}));        
        set("gender", "男性");                
        set("long", "烏當三米麒麟[2;37;0m
它是烏當三米的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "wudangmia");
        set("owner_name", "烏當三米");
        set_temp("owner", "wudangmia");
        set_temp("owner_name", "烏當三米");
        ::setup();
}
