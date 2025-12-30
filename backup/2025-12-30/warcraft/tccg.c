// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("馬六六[2;37;0m[2;37;0m", ({"tccfa"}));        
        set("gender", "男性");                
        set("long", "馬六六[2;37;0m
它是偷七的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tccg");
        set("owner_name", "偷七");
        set_temp("owner", "tccg");
        set_temp("owner_name", "偷七");
        ::setup();
}
