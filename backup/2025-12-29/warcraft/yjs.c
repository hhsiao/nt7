// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m叫獸[2;37;0m[2;37;0m", ({"screaming"}));        
        set("gender", "男性");                
        set("long", "bmw[2;37;0m
它是菸酒僧的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "yjs");
        set("owner_name", "菸酒僧");
        set_temp("owner", "yjs");
        set_temp("owner_name", "菸酒僧");
        ::setup();
}
