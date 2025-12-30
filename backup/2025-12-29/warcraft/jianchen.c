// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("寶馬[2;37;0m[2;37;0m", ({"baoma"}));        
        set("gender", "男性");                
        set("long", "寶馬[2;37;0m
它是劍辰的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "jianchen");
        set("owner_name", "劍辰");
        set_temp("owner", "jianchen");
        set_temp("owner_name", "劍辰");
        ::setup();
}
