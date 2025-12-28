// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("威龍[2;37;0m[2;37;0m", ({"brother"}));        
        set("gender", "男性");                
        set("long", "威龍在天[2;37;0m
它是悠雲蒼天的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "faraway");
        set("owner_name", "悠雲蒼天");
        set_temp("owner", "faraway");
        set_temp("owner_name", "悠雲蒼天");
        ::setup();
}
