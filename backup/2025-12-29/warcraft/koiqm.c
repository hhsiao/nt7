// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("回答速度[2;37;0m[2;37;0m", ({"yiyayo"}));        
        set("gender", "女性");                
        set("long", "的發放[2;37;0m
它是清明一的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "koiqm");
        set("owner_name", "清明一");
        set_temp("owner", "koiqm");
        set_temp("owner_name", "清明一");
        ::setup();
}
