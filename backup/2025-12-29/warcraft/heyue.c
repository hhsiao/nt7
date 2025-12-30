// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"carofheyue"}));        
        set("gender", "男性");                
        set("long", "heyue的魔幻獸[2;37;0m
它是北宮荷月的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "heyue");
        set("owner_name", "北宮荷月");
        set_temp("owner", "heyue");
        set_temp("owner_name", "北宮荷月");
        ::setup();
}
