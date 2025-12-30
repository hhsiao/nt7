// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m法制治國[2;37;0m[2;37;0m", ({"pigcc"}));        
        set("gender", "男性");                
        set("long", "法制治國[2;37;0m
它是襲勁瓶的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "pigc");
        set("owner_name", "襲勁瓶");
        set_temp("owner", "pigc");
        set_temp("owner_name", "襲勁瓶");
        ::setup();
}
