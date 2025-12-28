// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m神仙狗[2;37;0m[2;37;0m", ({"shengou"}));        
        set("gender", "男性");                
        set("long", "神仙狗[2;37;0m
它是犢子的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "duzi");
        set("owner_name", "犢子");
        set_temp("owner", "duzi");
        set_temp("owner_name", "犢子");
        ::setup();
}
