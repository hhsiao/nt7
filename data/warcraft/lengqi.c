// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("捕風[2;37;0m[2;37;0m", ({"bufeng"}));        
        set("gender", "男性");                
        set("long", "捕風[2;37;0m
它是冷棄的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "lengqi");
        set("owner_name", "冷棄");
        set_temp("owner", "lengqi");
        set_temp("owner_name", "冷棄");
        ::setup();
}
