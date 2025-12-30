// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("天樂麒麟[2;37;0m[2;37;0m", ({"ttqilin"}));        
        set("gender", "男性");                
        set("long", "這是bwwss的座機[2;37;0m
它是豔南天的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "bwwss");
        set("owner_name", "豔南天");
        set_temp("owner", "bwwss");
        set_temp("owner_name", "豔南天");
        ::setup();
}
