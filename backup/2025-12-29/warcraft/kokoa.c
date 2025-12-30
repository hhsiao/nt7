// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"qlw"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是無紀的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "kokoa");
        set("owner_name", "無紀");
        set_temp("owner", "kokoa");
        set_temp("owner_name", "無紀");
        ::setup();
}
