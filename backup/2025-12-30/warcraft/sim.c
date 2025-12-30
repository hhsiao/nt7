// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m青龍[2;37;0m[2;37;0m", ({"long"}));        
        set("gender", "男性");                
        set("long", "龍[2;37;0m
它是不知道的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "sim");
        set("owner_name", "不知道");
        set_temp("owner", "sim");
        set_temp("owner_name", "不知道");
        ::setup();
}
