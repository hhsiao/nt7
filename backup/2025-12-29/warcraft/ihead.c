// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("龍[2;37;0m[2;37;0m", ({"long"}));        
        set("gender", "男性");                
        set("long", "龍[2;37;0m
它是頭盔師傅的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "ihead");
        set("owner_name", "頭盔師傅");
        set_temp("owner", "ihead");
        set_temp("owner_name", "頭盔師傅");
        ::setup();
}
