// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("烏龜[2;37;0m[2;37;0m", ({"xiaoxie"}));        
        set("gender", "男性");                
        set("long", "一隻烏龜[2;37;0m
它是謝小的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "laoxie");
        set("owner_name", "謝小");
        set_temp("owner", "laoxie");
        set_temp("owner_name", "謝小");
        ::setup();
}
