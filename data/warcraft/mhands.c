// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m制式巨龍[2;37;0m[2;37;0m", ({"mhands_dragon"}));        
        set("gender", "男性");                
        set("long", "一頭軍用制式巨龍。[2;37;0m
它是鐵掌倉庫的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "mhands");
        set("owner_name", "鐵掌倉庫");
        set_temp("owner", "mhands");
        set_temp("owner_name", "鐵掌倉庫");
        ::setup();
}
