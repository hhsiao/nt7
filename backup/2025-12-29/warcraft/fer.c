// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白虎[2;37;0m[2;37;0m", ({"ddddd"}));        
        set("gender", "男性");                
        set("long", "白虎[2;37;0m
它是紫記的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "fer");
        set("owner_name", "紫記");
        set_temp("owner", "fer");
        set_temp("owner_name", "紫記");
        ::setup();
}
