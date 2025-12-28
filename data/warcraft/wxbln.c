// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m天外飛龍[2;37;0m[2;37;0m", ({"llong"}));        
        set("gender", "男性");                
        set("long", "天外飛龍[2;37;0m
它是飛翔的魚的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wxbln");
        set("owner_name", "飛翔的魚");
        set_temp("owner", "wxbln");
        set_temp("owner_name", "飛翔的魚");
        ::setup();
}
