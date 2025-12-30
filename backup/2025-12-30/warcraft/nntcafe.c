// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("七號[2;37;0m[2;37;0m", ({"cafe"}));        
        set("gender", "女性");                
        set("long", "七號[2;37;0m
它是咖啡七號的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "nntcafe");
        set("owner_name", "咖啡七號");
        set_temp("owner", "nntcafe");
        set_temp("owner_name", "咖啡七號");
        ::setup();
}
