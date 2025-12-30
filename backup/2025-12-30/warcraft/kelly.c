// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("山中精靈[2;37;0m[2;37;0m", ({"grace"}));        
        set("gender", "女性");                
        set("long", "山中精靈[2;37;0m
它是杜銘萱的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "kelly");
        set("owner_name", "杜銘萱");
        set_temp("owner", "kelly");
        set_temp("owner_name", "杜銘萱");
        ::setup();
}
