// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("水袋[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "水袋[2;37;0m
它是華山米米的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hsdumy");
        set("owner_name", "華山米米");
        set_temp("owner", "hsdumy");
        set_temp("owner_name", "華山米米");
        ::setup();
}
