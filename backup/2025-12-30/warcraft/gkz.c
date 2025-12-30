// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"fkaa"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是郭魯的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "gkz");
        set("owner_name", "郭魯");
        set_temp("owner", "gkz");
        set_temp("owner_name", "郭魯");
        ::setup();
}
