// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"sads"}));        
        set("gender", "女性");                
        set("long", "白虎[2;37;0m
它是飛飛的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ffh");
        set("owner_name", "飛飛");
        set_temp("owner", "ffh");
        set_temp("owner_name", "飛飛");
        ::setup();
}
