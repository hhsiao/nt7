// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("月月都來[2;37;0m[2;37;0m", ({"liuxuebuting"}));        
        set("gender", "男性");                
        set("long", "白色的大貓[2;37;0m
它是雪球飛的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "helpme");
        set("owner_name", "雪球飛");
        set_temp("owner", "helpme");
        set_temp("owner_name", "雪球飛");
        ::setup();
}
