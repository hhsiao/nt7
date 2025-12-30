// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("外套[2;37;0m[2;37;0m", ({"mygift"}));        
        set("gender", "女性");                
        set("long", "外套[2;37;0m
它是瑪馳的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "much");
        set("owner_name", "瑪馳");
        set_temp("owner", "much");
        set_temp("owner_name", "瑪馳");
        ::setup();
}
