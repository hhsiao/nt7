// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("青龍[2;37;0m[2;37;0m", ({"zizi"}));        
        set("gender", "男性");                
        set("long", "一條青龍[2;37;0m
它是風中葉子的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "david");
        set("owner_name", "風中葉子");
        set_temp("owner", "david");
        set_temp("owner_name", "風中葉子");
        ::setup();
}
