// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m吞田[2;37;0m[2;37;0m", ({"tuantian"}));        
        set("gender", "男性");                
        set("long", "威風凜凜[2;37;0m
它是斷滄海的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "canghai");
        set("owner_name", "斷滄海");
        set_temp("owner", "canghai");
        set_temp("owner_name", "斷滄海");
        ::setup();
}
