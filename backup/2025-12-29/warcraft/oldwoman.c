// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("金烏[2;37;0m[2;37;0m", ({"old"}));        
        set("gender", "女性");                
        set("long", "金烏[2;37;0m
它是老婦的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "oldwoman");
        set("owner_name", "老婦");
        set_temp("owner", "oldwoman");
        set_temp("owner_name", "老婦");
        ::setup();
}
