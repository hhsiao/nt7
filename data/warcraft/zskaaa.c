// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m龍獸[2;37;0m[2;37;0m", ({"huo"}));        
        set("gender", "男性");                
        set("long", "遠古代時的魔獸[2;37;0m
它是地獄小鬼的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "zskaaa");
        set("owner_name", "地獄小鬼");
        set_temp("owner", "zskaaa");
        set_temp("owner_name", "地獄小鬼");
        ::setup();
}
