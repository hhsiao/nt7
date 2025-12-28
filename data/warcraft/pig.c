// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("豬寶貝[2;37;0m[2;37;0m", ({"hip"}));        
        set("gender", "女性");                
        set("long", "我的寶貝[2;37;0m
它是豬太郎的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "pig");
        set("owner_name", "豬太郎");
        set_temp("owner", "pig");
        set_temp("owner_name", "豬太郎");
        ::setup();
}
