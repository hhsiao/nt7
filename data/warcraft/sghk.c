// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神仙狗[2;37;0m[2;37;0m", ({"shengou"}));        
        set("gender", "女性");                
        set("long", "神仙狗[2;37;0m
它是龍十二的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "sghk");
        set("owner_name", "龍十二");
        set_temp("owner", "sghk");
        set_temp("owner_name", "龍十二");
        ::setup();
}
