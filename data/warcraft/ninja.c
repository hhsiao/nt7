// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("鳥[2;37;0m[2;37;0m", ({"axe"}));        
        set("gender", "男性");                
        set("long", "撒大聲地大颯颯的[2;37;0m
它是純純的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ninja");
        set("owner_name", "純純");
        set_temp("owner", "ninja");
        set_temp("owner_name", "純純");
        ::setup();
}
