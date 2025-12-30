// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("無雙[2;37;0m[2;37;0m", ({"bless"}));        
        set("gender", "男性");                
        set("long", "君臨天下[2;37;0m
它是戰神的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ares");
        set("owner_name", "戰神");
        set_temp("owner", "ares");
        set_temp("owner_name", "戰神");
        ::setup();
}
