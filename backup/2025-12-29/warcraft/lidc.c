// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小濁氣[2;37;0m[2;37;0m", ({"zhuoqi"}));        
        set("gender", "男性");                
        set("long", "小濁氣[2;37;0m
它是煉王的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "lidc");
        set("owner_name", "煉王");
        set_temp("owner", "lidc");
        set_temp("owner_name", "煉王");
        ::setup();
}
