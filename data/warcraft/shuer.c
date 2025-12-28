// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("虎飛[2;37;0m[2;37;0m", ({"feio"}));        
        set("gender", "女性");                
        set("long", "什麼也沒有留下[2;37;0m
它是蘇爾白的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "shuer");
        set("owner_name", "蘇爾白");
        set_temp("owner", "shuer");
        set_temp("owner_name", "蘇爾白");
        ::setup();
}
