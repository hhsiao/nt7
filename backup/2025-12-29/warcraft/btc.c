// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m瑪莎啦蒂[2;37;0m[2;37;0m", ({"msa"}));        
        set("gender", "女性");                
        set("long", "finish[2;37;0m
它是周叄丹的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "btc");
        set("owner_name", "周叄丹");
        set_temp("owner", "btc");
        set_temp("owner_name", "周叄丹");
        ::setup();
}
