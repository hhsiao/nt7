// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("老鷹[2;37;0m[2;37;0m", ({"baoma"}));        
        set("gender", "男性");                
        set("long", "老鷹[2;37;0m
它是藥品專家的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "wdguiji");
        set("owner_name", "藥品專家");
        set_temp("owner", "wdguiji");
        set_temp("owner_name", "藥品專家");
        ::setup();
}
