// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m叄錢[2;37;0m[2;37;0m", ({"zxccpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是錢叄的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zxcc");
        set("owner_name", "錢叄");
        set_temp("owner", "zxcc");
        set_temp("owner_name", "錢叄");
        ::setup();
}
