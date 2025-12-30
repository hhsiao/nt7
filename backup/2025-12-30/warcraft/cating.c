// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小紅帽[2;37;0m[2;37;0m", ({"redmao"}));        
        set("gender", "男性");                
        set("long", "小紅帽[2;37;0m
它是貓咪的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "cating");
        set("owner_name", "貓咪");
        set_temp("owner", "cating");
        set_temp("owner_name", "貓咪");
        ::setup();
}
