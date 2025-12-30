// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("母青龍[2;37;0m[2;37;0m", ({"oko"}));        
        set("gender", "女性");                
        set("long", "好看的[2;37;0m
它是慕容飛的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yuri");
        set("owner_name", "慕容飛");
        set_temp("owner", "yuri");
        set_temp("owner_name", "慕容飛");
        ::setup();
}
