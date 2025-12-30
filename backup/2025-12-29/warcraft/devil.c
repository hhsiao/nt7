// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("睡袋[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "睡袋[2;37;0m
它是炒飯的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "devil");
        set("owner_name", "炒飯");
        set_temp("owner", "devil");
        set_temp("owner_name", "炒飯");
        ::setup();
}
