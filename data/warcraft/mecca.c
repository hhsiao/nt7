// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m玄僕[2;37;0m[2;37;0m", ({"meccapet"}));        
        set("gender", "男性");                
        set("long", "玄僕[2;37;0m
它是阿蘭貝勒的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "mecca");
        set("owner_name", "阿蘭貝勒");
        set_temp("owner", "mecca");
        set_temp("owner_name", "阿蘭貝勒");
        ::setup();
}
