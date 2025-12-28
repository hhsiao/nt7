// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("鳳凰[2;37;0m[2;37;0m", ({"qlw"}));        
        set("gender", "男性");                
        set("long", "鳳凰[2;37;0m
它是無際的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "kokob");
        set("owner_name", "無際");
        set_temp("owner", "kokob");
        set_temp("owner_name", "無際");
        ::setup();
}
