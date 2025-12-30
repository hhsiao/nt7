// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "大[2;37;0m
它是長神島的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "changansd");
        set("owner_name", "長神島");
        set_temp("owner", "changansd");
        set_temp("owner_name", "長神島");
        ::setup();
}
