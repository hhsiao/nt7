// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("米老頭[2;37;0m[2;37;0m", ({"xiaodamibb"}));        
        set("gender", "男性");                
        set("long", "米老頭[2;37;0m
它是米小二的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xiaodamib");
        set("owner_name", "米小二");
        set_temp("owner", "xiaodamib");
        set_temp("owner_name", "米小二");
        ::setup();
}
