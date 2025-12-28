// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m八岐大蛇[2;37;0m[2;37;0m", ({"sheba"}));        
        set("gender", "男性");                
        set("long", "九頭蛇的二表哥！[2;37;0m
它是八仙過海的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dangba");
        set("owner_name", "八仙過海");
        set_temp("owner", "dangba");
        set_temp("owner_name", "八仙過海");
        ::setup();
}
