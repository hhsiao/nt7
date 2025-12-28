// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m葉良辰[2;37;0m[2;37;0m", ({"yiyayo"}));        
        set("gender", "女性");                
        set("long", "的發放[2;37;0m
它是華九的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jkoi");
        set("owner_name", "華九");
        set_temp("owner", "jkoi");
        set_temp("owner_name", "華九");
        ::setup();
}
