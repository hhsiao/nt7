// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m鋼鐵裝甲[2;37;0m[2;37;0m", ({"tank"}));        
        set("gender", "男性");                
        set("long", "鋼鐵裝甲[2;37;0m
它是打工一號的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "job");
        set("owner_name", "打工一號");
        set_temp("owner", "job");
        set_temp("owner_name", "打工一號");
        ::setup();
}
