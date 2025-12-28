// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("麒麟[2;37;0m[2;37;0m", ({"yaovvv"}));        
        set("gender", "男性");                
        set("long", "麒麟[2;37;0m
它是藥喂喂的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "yaovv");
        set("owner_name", "藥喂喂");
        set_temp("owner", "yaovv");
        set_temp("owner_name", "藥喂喂");
        ::setup();
}
