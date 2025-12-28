// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m三陽開泰[2;37;0m[2;37;0m", ({"yangsan"}));        
        set("gender", "男性");                
        set("long", "三陽開泰[2;37;0m
它是傷心公子的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dangsan");
        set("owner_name", "傷心公子");
        set_temp("owner", "dangsan");
        set_temp("owner_name", "傷心公子");
        ::setup();
}
