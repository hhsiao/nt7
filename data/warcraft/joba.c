// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("啦啦啦[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "啦啦啦[2;37;0m
它是勞動人民的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "joba");
        set("owner_name", "勞動人民");
        set_temp("owner", "joba");
        set_temp("owner_name", "勞動人民");
        ::setup();
}
