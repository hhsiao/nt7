// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m八抬大轎[2;37;0m[2;37;0m", ({"jiaozi"}));        
        set("gender", "男性");                
        set("long", "八抬大轎[2;37;0m
它是胡雪巖的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "superrich");
        set("owner_name", "胡雪巖");
        set_temp("owner", "superrich");
        set_temp("owner_name", "胡雪巖");
        ::setup();
}
