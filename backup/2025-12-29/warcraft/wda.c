// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"long"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是無聊鬱悶的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wda");
        set("owner_name", "無聊鬱悶");
        set_temp("owner", "wda");
        set_temp("owner_name", "無聊鬱悶");
        ::setup();
}
