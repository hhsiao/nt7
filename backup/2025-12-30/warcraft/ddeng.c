// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[36m青龍[2;37;0m[2;37;0m", ({"qlong"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是鄧鄧的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ddeng");
        set("owner_name", "鄧鄧");
        set_temp("owner", "ddeng");
        set_temp("owner_name", "鄧鄧");
        ::setup();
}
