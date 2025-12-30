// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神仙龍[2;37;0m[2;37;0m", ({"shengou"}));        
        set("gender", "男性");                
        set("long", "神仙龍[2;37;0m
它是龍思的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "sghdxd");
        set("owner_name", "龍思");
        set_temp("owner", "sghdxd");
        set_temp("owner_name", "龍思");
        ::setup();
}
