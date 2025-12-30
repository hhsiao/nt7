// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火蓮道人[2;37;0m[2;37;0m", ({"rodl"}));        
        set("gender", "男性");                
        set("long", "。。。。[2;37;0m
它是道聽途說的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "check");
        set("owner_name", "道聽途說");
        set_temp("owner", "check");
        set_temp("owner_name", "道聽途說");
        ::setup();
}
