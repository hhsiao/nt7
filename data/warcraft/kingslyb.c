// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("裡裡[2;37;0m[2;37;0m", ({"kin"}));        
        set("gender", "男性");                
        set("long", "裡裡[2;37;0m
它是卡老的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "kingslyb");
        set("owner_name", "卡老");
        set_temp("owner", "kingslyb");
        set_temp("owner_name", "卡老");
        ::setup();
}
