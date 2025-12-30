// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"tgimm"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是陽頂天的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tgimj");
        set("owner_name", "陽頂天");
        set_temp("owner", "tgimj");
        set_temp("owner_name", "陽頂天");
        ::setup();
}
