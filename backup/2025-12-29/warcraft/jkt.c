// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("東北虎[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "男性");                
        set("long", "hp[2;37;0m
它是於大的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "jkt");
        set("owner_name", "於大");
        set_temp("owner", "jkt");
        set_temp("owner_name", "於大");
        ::setup();
}
