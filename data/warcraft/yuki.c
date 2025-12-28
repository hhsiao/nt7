// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛毛腿[2;37;0m[2;37;0m", ({"oko"}));        
        set("gender", "男性");                
        set("long", "導彈一號[2;37;0m
它是瘋小小的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yuki");
        set("owner_name", "瘋小小");
        set_temp("owner", "yuki");
        set_temp("owner_name", "瘋小小");
        ::setup();
}
