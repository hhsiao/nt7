// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小青龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "一條小青龍[2;37;0m
它是無涯的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "gogoa");
        set("owner_name", "無涯");
        set_temp("owner", "gogoa");
        set_temp("owner_name", "無涯");
        ::setup();
}
