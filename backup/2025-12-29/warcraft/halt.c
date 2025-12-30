// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("嚕嚕[2;37;0m[2;37;0m", ({"ssx"}));        
        set("gender", "男性");                
        set("long", "啊[2;37;0m
它是古劍的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "halt");
        set("owner_name", "古劍");
        set_temp("owner", "halt");
        set_temp("owner_name", "古劍");
        ::setup();
}
