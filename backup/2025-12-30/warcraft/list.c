// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("血山飛狐[2;37;0m[2;37;0m", ({"flyfox"}));        
        set("gender", "男性");                
        set("long", "血山飛狐[2;37;0m
它是咕嘟球唄的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "list");
        set("owner_name", "咕嘟球唄");
        set_temp("owner", "list");
        set_temp("owner_name", "咕嘟球唄");
        ::setup();
}
