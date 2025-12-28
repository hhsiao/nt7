// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("回答速度[2;37;0m[2;37;0m", ({"yiyayo"}));        
        set("gender", "女性");                
        set("long", "的發放[2;37;0m
它是還混六的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "haihunf");
        set("owner_name", "還混六");
        set_temp("owner", "haihunf");
        set_temp("owner_name", "還混六");
        ::setup();
}
