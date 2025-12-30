// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"oppo"}));        
        set("gender", "男性");                
        set("long", "快要退役的[2;37;0m
它是慕容飛飛的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "adbo");
        set("owner_name", "慕容飛飛");
        set_temp("owner", "adbo");
        set_temp("owner_name", "慕容飛飛");
        ::setup();
}
