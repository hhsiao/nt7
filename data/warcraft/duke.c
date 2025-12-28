// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m江鐵牛[2;37;0m[2;37;0m", ({"dukeo"}));        
        set("gender", "女性");                
        set("long", "江鐵牛[2;37;0m
它是豬七的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "duke");
        set("owner_name", "豬七");
        set_temp("owner", "duke");
        set_temp("owner_name", "豬七");
        ::setup();
}
