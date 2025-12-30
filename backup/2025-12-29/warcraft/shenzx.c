// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m晨曦[2;37;0m[2;37;0m", ({"shen"}));        
        set("gender", "男性");                
        set("long", "是妖為成仙[2;37;0m
它是聶風的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "shenzx");
        set("owner_name", "聶風");
        set_temp("owner", "shenzx");
        set_temp("owner_name", "聶風");
        ::setup();
}
