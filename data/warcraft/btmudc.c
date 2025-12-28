// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("變獸三[2;37;0m[2;37;0m", ({"btc"}));        
        set("gender", "男性");                
        set("long", "爽[2;37;0m
它是變態米三的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "btmudc");
        set("owner_name", "變態米三");
        set_temp("owner", "btmudc");
        set_temp("owner_name", "變態米三");
        ::setup();
}
