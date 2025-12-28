// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m拾錢[2;37;0m[2;37;0m", ({"zxcjpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是錢拾的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zxcj");
        set("owner_name", "錢拾");
        set_temp("owner", "zxcj");
        set_temp("owner_name", "錢拾");
        ::setup();
}
