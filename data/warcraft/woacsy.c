// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[31m遠古龍[2;37;0m[2;37;0m", ({"konglong"}));        
        set("gender", "男性");                
        set("long", "$RED$遠古龍[2;37;0m
它是重小雨的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "woacsy");
        set("owner_name", "重小雨");
        set_temp("owner", "woacsy");
        set_temp("owner_name", "重小雨");
        ::setup();
}
