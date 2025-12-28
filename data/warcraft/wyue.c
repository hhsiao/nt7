// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魚雀[2;37;0m[2;37;0m", ({"huoo"}));        
        set("gender", "女性");                
        set("long", "魚雀[2;37;0m
它是西山無月的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wyue");
        set("owner_name", "西山無月");
        set_temp("owner", "wyue");
        set_temp("owner_name", "西山無月");
        ::setup();
}
