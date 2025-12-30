// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("乞靈[2;37;0m[2;37;0m", ({"noneys"}));        
        set("gender", "女性");                
        set("long", "乞靈[2;37;0m
它是錢不通的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "noneyn");
        set("owner_name", "錢不通");
        set_temp("owner", "noneyn");
        set_temp("owner_name", "錢不通");
        ::setup();
}
