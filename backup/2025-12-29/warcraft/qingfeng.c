// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("月明麒麟[2;37;0m[2;37;0m", ({"qingfengride"}));        
        set("gender", "女性");                
        set("long", "月明麒麟[2;37;0m
它是清風的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "qingfeng");
        set("owner_name", "清風");
        set_temp("owner", "qingfeng");
        set_temp("owner_name", "清風");
        ::setup();
}
