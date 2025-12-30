// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m東坡[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "男性");                
        set("long", "東坡[2;37;0m
它是蘇軾的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "sushi");
        set("owner_name", "蘇軾");
        set_temp("owner", "sushi");
        set_temp("owner_name", "蘇軾");
        ::setup();
}
