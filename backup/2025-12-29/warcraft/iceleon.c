// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小龍龍[2;37;0m[2;37;0m", ({"xlong"}));        
        set("gender", "男性");                
        set("long", "@@@@[2;37;0m
它是蒼穹無悔的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "iceleon");
        set("owner_name", "蒼穹無悔");
        set_temp("owner", "iceleon");
        set_temp("owner_name", "蒼穹無悔");
        ::setup();
}
