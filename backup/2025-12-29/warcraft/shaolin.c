// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("中草藥[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "中草藥[2;37;0m
它是淨段的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "shaolin");
        set("owner_name", "淨段");
        set_temp("owner", "shaolin");
        set_temp("owner_name", "淨段");
        ::setup();
}
