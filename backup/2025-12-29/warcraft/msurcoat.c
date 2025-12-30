// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m制式巨龍[2;37;0m[2;37;0m", ({"marmor_dragon"}));        
        set("gender", "男性");                
        set("long", "一頭軍用制式巨龍。[2;37;0m
它是披風倉庫的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "msurcoat");
        set("owner_name", "披風倉庫");
        set_temp("owner", "msurcoat");
        set_temp("owner_name", "披風倉庫");
        ::setup();
}
