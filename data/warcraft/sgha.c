// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("神仙龍[2;37;0m[2;37;0m", ({"shengou"}));        
        set("gender", "男性");                
        set("long", "神仙龍[2;37;0m
它是龍醫的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "sgha");
        set("owner_name", "龍醫");
        set_temp("owner", "sgha");
        set_temp("owner_name", "龍醫");
        ::setup();
}
