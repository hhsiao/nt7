// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("馬六[2;37;0m[2;37;0m", ({"tccea"}));        
        set("gender", "男性");                
        set("long", "馬六[2;37;0m
它是偷六的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tccf");
        set("owner_name", "偷六");
        set_temp("owner", "tccf");
        set_temp("owner_name", "偷六");
        ::setup();
}
