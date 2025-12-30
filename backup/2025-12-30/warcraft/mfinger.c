// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m制式巨龍[2;37;0m[2;37;0m", ({"mfinger_dragon"}));        
        set("gender", "男性");                
        set("long", "一頭軍用制式巨龍。[2;37;0m
它是指套倉庫的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "mfinger");
        set("owner_name", "指套倉庫");
        set_temp("owner", "mfinger");
        set_temp("owner_name", "指套倉庫");
        ::setup();
}
