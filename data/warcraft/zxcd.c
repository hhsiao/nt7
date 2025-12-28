// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;34m肆錢[2;37;0m[2;37;0m", ({"zxcdpet"}));        
        set("gender", "男性");                
        set("long", "美麗中國夢[2;37;0m
它是錢肆的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "zxcd");
        set("owner_name", "錢肆");
        set_temp("owner", "zxcd");
        set_temp("owner_name", "錢肆");
        ::setup();
}
