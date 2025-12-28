// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("煩煩煩[2;37;0m[2;37;0m", ({"yaofff"}));        
        set("gender", "男性");                
        set("long", "煩煩煩[2;37;0m
它是藥發發的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yaoff");
        set("owner_name", "藥發發");
        set_temp("owner", "yaoff");
        set_temp("owner_name", "藥發發");
        ::setup();
}
