// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m魔幻獸[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "sleep[2;37;0m
它是啊啊的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ccc");
        set("owner_name", "啊啊");
        set_temp("owner", "ccc");
        set_temp("owner_name", "啊啊");
        ::setup();
}
