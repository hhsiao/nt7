// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qingv"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是菜農六的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tcf");
        set("owner_name", "菜農六");
        set_temp("owner", "tcf");
        set_temp("owner_name", "菜農六");
        ::setup();
}
