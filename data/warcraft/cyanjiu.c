// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("獸性大發[2;37;0m[2;37;0m", ({"yanjiushou"}));        
        set("gender", "男性");                
        set("long", "獸性大發[2;37;0m
它是李十九的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "cyanjiu");
        set("owner_name", "李十九");
        set_temp("owner", "cyanjiu");
        set_temp("owner_name", "李十九");
        ::setup();
}
