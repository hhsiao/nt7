// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("蛋糕雀[2;37;0m[2;37;0m", ({"piko"}));        
        set("gender", "女性");                
        set("long", "肥胖[2;37;0m
它是無處自在的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "litral");
        set("owner_name", "無處自在");
        set_temp("owner", "litral");
        set_temp("owner_name", "無處自在");
        ::setup();
}
