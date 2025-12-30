// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m人力三輪[2;37;0m[2;37;0m", ({"doo"}));        
        set("gender", "女性");                
        set("long", "$HIW$人力三輪[2;37;0m
它是認球不得的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kood");
        set("owner_name", "認球不得");
        set_temp("owner", "kood");
        set_temp("owner_name", "認球不得");
        ::setup();
}
