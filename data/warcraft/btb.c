// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("拜納姆[2;37;0m[2;37;0m", ({"bnm"}));        
        set("gender", "男性");                
        set("long", "finish[2;37;0m
它是周丹貳的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "btb");
        set("owner_name", "周丹貳");
        set_temp("owner", "btb");
        set_temp("owner_name", "周丹貳");
        ::setup();
}
