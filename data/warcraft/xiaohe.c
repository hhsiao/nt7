// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("河內蛟龍[2;37;0m[2;37;0m", ({"huansl"}));        
        set("gender", "女性");                
        set("long", "河內蛟龍[2;37;0m
它是有條小河的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xiaohe");
        set("owner_name", "有條小河");
        set_temp("owner", "xiaohe");
        set_temp("owner_name", "有條小河");
        ::setup();
}
