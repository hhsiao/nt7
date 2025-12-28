// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("娜可露露[2;37;0m[2;37;0m", ({"omo"}));        
        set("gender", "女性");                
        set("long", "沒有[2;37;0m
它是周倉四的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "bti");
        set("owner_name", "周倉四");
        set_temp("owner", "bti");
        set_temp("owner_name", "周倉四");
        ::setup();
}
