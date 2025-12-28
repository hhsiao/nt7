// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("無敵[2;37;0m[2;37;0m", ({"jinhu"}));        
        set("gender", "男性");                
        set("long", "無敵[2;37;0m
它是胡一亂飛的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "mcat");
        set("owner_name", "胡一亂飛");
        set_temp("owner", "mcat");
        set_temp("owner_name", "胡一亂飛");
        ::setup();
}
