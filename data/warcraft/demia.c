// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("三輪車[2;37;0m[2;37;0m", ({"xdemia"}));        
        set("gender", "女性");                
        set("long", "勞動工具[2;37;0m
它是壯士一的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "demia");
        set("owner_name", "壯士一");
        set_temp("owner", "demia");
        set_temp("owner_name", "壯士一");
        ::setup();
}
