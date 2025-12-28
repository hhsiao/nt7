// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m歷史書[2;37;0m[2;37;0m", ({"lsbook"}));        
        set("gender", "男性");                
        set("long", "哈哈哈哈h[2;37;0m
它是羅賓的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xlqxh");
        set("owner_name", "羅賓");
        set_temp("owner", "xlqxh");
        set_temp("owner_name", "羅賓");
        ::setup();
}
