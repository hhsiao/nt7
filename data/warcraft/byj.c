// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青鸞[2;37;0m[2;37;0m", ({"qingluan"}));        
        set("gender", "男性");                
        set("long", "青鸞杳，碧天雲海音絕[2;37;0m
它是白玉京的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "byj");
        set("owner_name", "白玉京");
        set_temp("owner", "byj");
        set_temp("owner_name", "白玉京");
        ::setup();
}
