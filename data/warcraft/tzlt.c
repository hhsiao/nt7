// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;33m東方金龍[2;37;0m[2;37;0m", ({"dragonraja"}));        
        set("gender", "男性");                
        set("long", "一隻金光燦燦的神龍，渾身散發古老神秘的氣息。[2;37;0m
它是魔神的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tzlt");
        set("owner_name", "魔神");
        set_temp("owner", "tzlt");
        set_temp("owner_name", "魔神");
        ::setup();
}
