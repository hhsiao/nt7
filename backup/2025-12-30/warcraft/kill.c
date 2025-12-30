// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("亞克西[2;37;0m[2;37;0m", ({"xixi"}));        
        set("gender", "女性");                
        set("long", "亞克西[2;37;0m
它是幽冥血吟的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "kill");
        set("owner_name", "幽冥血吟");
        set_temp("owner", "kill");
        set_temp("owner_name", "幽冥血吟");
        ::setup();
}
