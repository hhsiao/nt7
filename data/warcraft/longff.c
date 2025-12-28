// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神仙狗[2;37;0m[2;37;0m", ({"shengou"}));        
        set("gender", "男性");                
        set("long", "神仙狗[2;37;0m
它是龍鐵腕的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "longff");
        set("owner_name", "龍鐵腕");
        set_temp("owner", "longff");
        set_temp("owner_name", "龍鐵腕");
        ::setup();
}
