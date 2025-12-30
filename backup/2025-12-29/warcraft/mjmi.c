// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("大貓[2;37;0m[2;37;0m", ({"mao"}));        
        set("gender", "男性");                
        set("long", "大貓[2;37;0m
它是明大的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "mjmi");
        set("owner_name", "明大");
        set_temp("owner", "mjmi");
        set_temp("owner_name", "明大");
        ::setup();
}
