// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("死龍[2;37;0m[2;37;0m", ({"hid"}));        
        set("gender", "男性");                
        set("long", "死龍[2;37;0m
它是殺柏的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hieen");
        set("owner_name", "殺柏");
        set_temp("owner", "hieen");
        set_temp("owner_name", "殺柏");
        ::setup();
}
