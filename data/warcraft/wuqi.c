// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("噓噓[2;37;0m[2;37;0m", ({"xuxu"}));        
        set("gender", "男性");                
        set("long", "噓噓[2;37;0m
它是無棄的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "wuqi");
        set("owner_name", "無棄");
        set_temp("owner", "wuqi");
        set_temp("owner_name", "無棄");
        ::setup();
}
