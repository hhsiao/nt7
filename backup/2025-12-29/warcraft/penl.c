// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m赤焰駒[2;37;0m[2;37;0m", ({"baima"}));        
        set("gender", "女性");                
        set("long", "$HIW$赤焰駒[2;37;0m
它是柳公權的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "penl");
        set("owner_name", "柳公權");
        set_temp("owner", "penl");
        set_temp("owner_name", "柳公權");
        ::setup();
}
