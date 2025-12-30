// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("異形[2;37;0m[2;37;0m", ({"queen"}));        
        set("gender", "女性");                
        set("long", "皇后[2;37;0m
它是一長的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "shitweeka");
        set("owner_name", "一長");
        set_temp("owner", "shitweeka");
        set_temp("owner_name", "一長");
        ::setup();
}
