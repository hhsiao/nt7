// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("舊主人[2;37;0m[2;37;0m", ({"xinlong"}));        
        set("gender", "男性");                
        set("long", "我日[2;37;0m
它是新階級的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xin");
        set("owner_name", "新階級");
        set_temp("owner", "xin");
        set_temp("owner_name", "新階級");
        ::setup();
}
