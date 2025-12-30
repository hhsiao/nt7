// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"qll"}));        
        set("gender", "男性");                
        set("long", "青龍[2;37;0m
它是七尺大儒的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "speciall");
        set("owner_name", "七尺大儒");
        set_temp("owner", "speciall");
        set_temp("owner_name", "七尺大儒");
        ::setup();
}
