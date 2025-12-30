// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("戰[2;37;0m[2;37;0m", ({"zhan"}));        
        set("gender", "男性");                
        set("long", "戰[2;37;0m
它是戰天的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "zhantian");
        set("owner_name", "戰天");
        set_temp("owner", "zhantian");
        set_temp("owner_name", "戰天");
        ::setup();
}
