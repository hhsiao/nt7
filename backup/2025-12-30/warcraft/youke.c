// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("轎子[2;37;0m[2;37;0m", ({"benz"}));        
        set("gender", "男性");                
        set("long", "                                  [2;37;0m
它是遊客的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "youke");
        set("owner_name", "遊客");
        set_temp("owner", "youke");
        set_temp("owner_name", "遊客");
        ::setup();
}
