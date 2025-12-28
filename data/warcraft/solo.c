// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m空軍一號[2;37;0m[2;37;0m", ({"johnny"}));        
        set("gender", "男性");                
        set("long", "我要坐空軍一號[2;37;0m
它是司馬甄寰的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "solo");
        set("owner_name", "司馬甄寰");
        set_temp("owner", "solo");
        set_temp("owner_name", "司馬甄寰");
        ::setup();
}
