// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m勾錢[2;37;0m[2;37;0m", ({"zxckpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是錢勾的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zxck");
        set("owner_name", "錢勾");
        set_temp("owner", "zxck");
        set_temp("owner_name", "錢勾");
        ::setup();
}
