// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神仙狗[2;37;0m[2;37;0m", ({"shengou"}));        
        set("gender", "男性");                
        set("long", "神仙狗[2;37;0m
它是鳳帽子的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lfengc");
        set("owner_name", "鳳帽子");
        set_temp("owner", "lfengc");
        set_temp("owner_name", "鳳帽子");
        ::setup();
}
