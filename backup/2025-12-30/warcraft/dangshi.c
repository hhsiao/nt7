// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m十全大補丸[2;37;0m[2;37;0m", ({"bushi"}));        
        set("gender", "男性");                
        set("long", "十全大補!![2;37;0m
它是死地後生的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "dangshi");
        set("owner_name", "死地後生");
        set_temp("owner", "dangshi");
        set_temp("owner_name", "死地後生");
        ::setup();
}
