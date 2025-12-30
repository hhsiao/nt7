// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m可愛的[2;37;0m[2;37;0m", ({"lovely"}));        
        set("gender", "男性");                
        set("long", "可愛的一條小青龍[2;37;0m
它是葉綠風的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "zues");
        set("owner_name", "葉綠風");
        set_temp("owner", "zues");
        set_temp("owner_name", "葉綠風");
        ::setup();
}
