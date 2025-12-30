// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("無電[2;37;0m[2;37;0m", ({"wudian"}));        
        set("gender", "男性");                
        set("long", "無電[2;37;0m
它是魔無電的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "mwd");
        set("owner_name", "魔無電");
        set_temp("owner", "mwd");
        set_temp("owner_name", "魔無電");
        ::setup();
}
