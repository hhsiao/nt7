// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;35m龍寶貝[2;37;0m[2;37;0m", ({"celia"}));        
        set("gender", "女性");                
        set("long", "漂亮、可愛、又善良的龍寶貝[2;37;0m
它是鮑清揚的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ormer");
        set("owner_name", "鮑清揚");
        set_temp("owner", "ormer");
        set_temp("owner_name", "鮑清揚");
        ::setup();
}
