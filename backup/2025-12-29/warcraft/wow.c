// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m藥袋[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "女性");                
        set("long", "藥袋[2;37;0m
它是妖丹師的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wow");
        set("owner_name", "妖丹師");
        set_temp("owner", "wow");
        set_temp("owner_name", "妖丹師");
        ::setup();
}
