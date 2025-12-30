// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("霸王龍[2;37;0m[2;37;0m", ({"dargon"}));        
        set("gender", "男性");                
        set("long", "兇猛的龍[2;37;0m
它是寒雨涼的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "elon");
        set("owner_name", "寒雨涼");
        set_temp("owner", "elon");
        set_temp("owner_name", "寒雨涼");
        ::setup();
}
