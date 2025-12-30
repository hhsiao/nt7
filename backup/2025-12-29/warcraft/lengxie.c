// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("鐺[2;37;0m[2;37;0m", ({"dang"}));        
        set("gender", "男性");                
        set("long", "鐺[2;37;0m
它是冷血的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lengxie");
        set("owner_name", "冷血");
        set_temp("owner", "lengxie");
        set_temp("owner_name", "冷血");
        ::setup();
}
