// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("隨例題[2;37;0m[2;37;0m", ({"qmaaa"}));        
        set("gender", "男性");                
        set("long", "隨例題[2;37;0m
它是完美用戶的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "solqm");
        set("owner_name", "完美用戶");
        set_temp("owner", "solqm");
        set_temp("owner_name", "完美用戶");
        ::setup();
}
