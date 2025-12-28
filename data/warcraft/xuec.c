// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("旺財[2;37;0m[2;37;0m", ({"longlonga"}));        
        set("gender", "男性");                
        set("long", "黑莓手機[2;37;0m
它是霍大金的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xuec");
        set("owner_name", "霍大金");
        set_temp("owner", "xuec");
        set_temp("owner_name", "霍大金");
        ::setup();
}
