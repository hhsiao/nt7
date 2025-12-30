// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"ffcfes"}));        
        set("gender", "男性");                
        set("long", "多吃點[2;37;0m
它是炎熱而然的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yer");
        set("owner_name", "炎熱而然");
        set_temp("owner", "yer");
        set_temp("owner_name", "炎熱而然");
        ::setup();
}
