// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("四號[2;37;0m[2;37;0m", ({"cafe"}));        
        set("gender", "女性");                
        set("long", "四號[2;37;0m
它是咖啡四號的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ccftony");
        set("owner_name", "咖啡四號");
        set_temp("owner", "ccftony");
        set_temp("owner_name", "咖啡四號");
        ::setup();
}
