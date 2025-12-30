// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神仙狗[2;37;0m[2;37;0m", ({"shengou"}));        
        set("gender", "女性");                
        set("long", "神仙狗[2;37;0m
它是龍倉庫的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "sghz");
        set("owner_name", "龍倉庫");
        set_temp("owner", "sghz");
        set_temp("owner_name", "龍倉庫");
        ::setup();
}
