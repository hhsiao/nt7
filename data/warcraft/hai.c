// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m不死神龍[2;37;0m[2;37;0m", ({"shenlong"}));        
        set("gender", "男性");                
        set("long", "不死神龍[2;37;0m
它是爽嗨嗨的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hai");
        set("owner_name", "爽嗨嗨");
        set_temp("owner", "hai");
        set_temp("owner_name", "爽嗨嗨");
        ::setup();
}
