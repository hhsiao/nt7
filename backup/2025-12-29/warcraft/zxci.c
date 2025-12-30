// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m玖錢[2;37;0m[2;37;0m", ({"zxcipet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是錢玖的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zxci");
        set("owner_name", "錢玖");
        set_temp("owner", "zxci");
        set_temp("owner_name", "錢玖");
        ::setup();
}
