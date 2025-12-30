// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("哼哼[2;37;0m[2;37;0m", ({"sleepbag"}));        
        set("gender", "男性");                
        set("long", "哼哼[2;37;0m
它是輔助的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "sup");
        set("owner_name", "輔助");
        set_temp("owner", "sup");
        set_temp("owner_name", "輔助");
        ::setup();
}
