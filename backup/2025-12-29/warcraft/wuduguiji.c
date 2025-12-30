// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小寵物[2;37;0m[2;37;0m", ({"baoma"}));        
        set("gender", "男性");                
        set("long", "小寵物[2;37;0m
它是寵物大師的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "wuduguiji");
        set("owner_name", "寵物大師");
        set_temp("owner", "wuduguiji");
        set_temp("owner_name", "寵物大師");
        ::setup();
}
