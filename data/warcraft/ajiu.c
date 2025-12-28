// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m凱利布魯克[2;37;0m[2;37;0m", ({"buluke"}));        
        set("gender", "女性");                
        set("long", "凱利布魯克，絕代妖姬，世界級的女神![2;37;0m
它是南宮九的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "ajiu");
        set("owner_name", "南宮九");
        set_temp("owner", "ajiu");
        set_temp("owner_name", "南宮九");
        ::setup();
}
