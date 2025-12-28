// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m慕容長青[2;37;0m[2;37;0m", ({"jioker"}));        
        set("gender", "女性");                
        set("long", "慕容長青[2;37;0m
它是豬六的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "jicker");
        set("owner_name", "豬六");
        set_temp("owner", "jicker");
        set_temp("owner_name", "豬六");
        ::setup();
}
