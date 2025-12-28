// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("三號[2;37;0m[2;37;0m", ({"cafe"}));        
        set("gender", "男性");                
        set("long", "三號[2;37;0m
它是咖啡三號的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ccfpaper");
        set("owner_name", "咖啡三號");
        set_temp("owner", "ccfpaper");
        set_temp("owner_name", "咖啡三號");
        ::setup();
}
