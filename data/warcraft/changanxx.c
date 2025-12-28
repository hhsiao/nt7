// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "大[2;37;0m
它是長十安的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "changanxx");
        set("owner_name", "長十安");
        set_temp("owner", "changanxx");
        set_temp("owner_name", "長十安");
        ::setup();
}
