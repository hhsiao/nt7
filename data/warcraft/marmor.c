// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m制式巨龍[2;37;0m[2;37;0m", ({"mcloth_dragon"}));        
        set("gender", "男性");                
        set("long", "一頭軍用制式巨龍。[2;37;0m
它是護甲倉庫的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "marmor");
        set("owner_name", "護甲倉庫");
        set_temp("owner", "marmor");
        set_temp("owner_name", "護甲倉庫");
        ::setup();
}
