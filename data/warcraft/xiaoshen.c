// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小小[2;37;0m[2;37;0m", ({"xss"}));        
        set("gender", "男性");                
        set("long", "醜就一個字[2;37;0m
它是小神的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xiaoshen");
        set("owner_name", "小神");
        set_temp("owner", "xiaoshen");
        set_temp("owner_name", "小神");
        ::setup();
}
