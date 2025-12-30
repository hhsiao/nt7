// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("強化神獸[2;37;0m[2;37;0m", ({"jinhu"}));        
        set("gender", "男性");                
        set("long", "強化神獸[2;37;0m
它是胡亂飛的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "xiaocat");
        set("owner_name", "胡亂飛");
        set_temp("owner", "xiaocat");
        set_temp("owner_name", "胡亂飛");
        ::setup();
}
