// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("熾翼[2;37;0m[2;37;0m", ({"puppy"}));        
        set("gender", "男性");                
        set("long", "red[2;37;0m
它是浪還潮的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "kyon");
        set("owner_name", "浪還潮");
        set_temp("owner", "kyon");
        set_temp("owner_name", "浪還潮");
        ::setup();
}
