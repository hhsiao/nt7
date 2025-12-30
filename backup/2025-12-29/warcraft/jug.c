// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("時之沙[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "時之沙[2;37;0m
它是王二的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jug");
        set("owner_name", "王二");
        set_temp("owner", "jug");
        set_temp("owner_name", "王二");
        ::setup();
}
