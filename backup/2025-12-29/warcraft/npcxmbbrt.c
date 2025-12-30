// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("自行車[2;37;0m[2;37;0m", ({"west"}));        
        set("gender", "男性");                
        set("long", "自行車[2;37;0m
它是陶濤奮的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "npcxmbbrt");
        set("owner_name", "陶濤奮");
        set_temp("owner", "npcxmbbrt");
        set_temp("owner_name", "陶濤奮");
        ::setup();
}
