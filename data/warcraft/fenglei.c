// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("狂龍[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "男性");                
        set("long", "大長金[2;37;0m
它是風雷的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "fenglei");
        set("owner_name", "風雷");
        set_temp("owner", "fenglei");
        set_temp("owner_name", "風雷");
        ::setup();
}
