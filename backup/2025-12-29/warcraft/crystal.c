// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("著騎[2;37;0m[2;37;0m", ({"along"}));        
        set("gender", "男性");                
        set("long", "一八[2;37;0m
它是水晶的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "crystal");
        set("owner_name", "水晶");
        set_temp("owner", "crystal");
        set_temp("owner_name", "水晶");
        ::setup();
}
