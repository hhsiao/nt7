// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"ddxsss"}));        
        set("gender", "女性");                
        set("long", "搜索[2;37;0m
它是破華的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "pohua");
        set("owner_name", "破華");
        set_temp("owner", "pohua");
        set_temp("owner_name", "破華");
        ::setup();
}
