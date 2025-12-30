// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小頑皮[2;37;0m[2;37;0m", ({"xpp"}));        
        set("gender", "男性");                
        set("long", "頭大如鬥[2;37;0m
它是皮皮的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "pipi");
        set("owner_name", "皮皮");
        set_temp("owner", "pipi");
        set_temp("owner_name", "皮皮");
        ::setup();
}
