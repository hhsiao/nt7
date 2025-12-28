// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龍令風[2;37;0m[2;37;0m", ({"drong"}));        
        set("gender", "女性");                
        set("long", "龍令風[2;37;0m
它是哦啦的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "oolala");
        set("owner_name", "哦啦");
        set_temp("owner", "oolala");
        set_temp("owner_name", "哦啦");
        ::setup();
}
