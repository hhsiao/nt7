// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("童子[2;37;0m[2;37;0m", ({"tongzi"}));        
        set("gender", "男性");                
        set("long", "童子[2;37;0m
它是藥米的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "yaomi");
        set("owner_name", "藥米");
        set_temp("owner", "yaomi");
        set_temp("owner_name", "藥米");
        ::setup();
}
