// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;32m萬[1;31m惡[1;33m之[1;35m源[2;37;0m[2;37;0m[2;37;0m", ({"allevil"}));        
        set("gender", "男性");                
        set("long", "萬惡之源！[2;37;0m
它是盛意拳拳的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "evilsky");
        set("owner_name", "盛意拳拳");
        set_temp("owner", "evilsky");
        set_temp("owner_name", "盛意拳拳");
        ::setup();
}
