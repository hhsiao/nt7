// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"kkll"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是恆十恆的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zzhh");
        set("owner_name", "恆十恆");
        set_temp("owner", "zzhh");
        set_temp("owner_name", "恆十恆");
        ::setup();
}
