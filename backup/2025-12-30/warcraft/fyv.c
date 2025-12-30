// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("考拉[2;37;0m[2;37;0m", ({"myfy"}));        
        set("gender", "男性");                
        set("long", "考拉[2;37;0m
它是菜比蔣的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "fyv");
        set("owner_name", "菜比蔣");
        set_temp("owner", "fyv");
        set_temp("owner_name", "菜比蔣");
        ::setup();
}
