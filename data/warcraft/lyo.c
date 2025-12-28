// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("額外好方法[2;37;0m[2;37;0m", ({"cib"}));        
        set("gender", "男性");                
        set("long", "額外好方法[2;37;0m
它是櫻桃五號的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "lyo");
        set("owner_name", "櫻桃五號");
        set_temp("owner", "lyo");
        set_temp("owner_name", "櫻桃五號");
        ::setup();
}
