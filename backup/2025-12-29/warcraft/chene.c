// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m[1;34m新任務[2;37;0m[2;37;0m", ({"loooo"}));        
        set("gender", "男性");                
        set("long", "新任務[2;37;0m
它是成不有的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "chene");
        set("owner_name", "成不有");
        set_temp("owner", "chene");
        set_temp("owner_name", "成不有");
        ::setup();
}
