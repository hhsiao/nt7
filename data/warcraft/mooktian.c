// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("遠古[2;37;0m[2;37;0m", ({"qinglong"}));        
        set("gender", "女性");                
        set("long", "這是一隻遠古青龍。[2;37;0m
它是清清的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "mooktian");
        set("owner_name", "清清");
        set_temp("owner", "mooktian");
        set_temp("owner_name", "清清");
        ::setup();
}
