// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("馬五[2;37;0m[2;37;0m", ({"tccea"}));        
        set("gender", "男性");                
        set("long", "馬五[2;37;0m
它是偷五的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tcce");
        set("owner_name", "偷五");
        set_temp("owner", "tcce");
        set_temp("owner_name", "偷五");
        ::setup();
}
