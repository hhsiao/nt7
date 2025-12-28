// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小心[2;37;0m[2;37;0m", ({"xxxx"}));        
        set("gender", "男性");                
        set("long", "小心[2;37;0m
它是誰呀的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "shuiya");
        set("owner_name", "誰呀");
        set_temp("owner", "shuiya");
        set_temp("owner_name", "誰呀");
        ::setup();
}
