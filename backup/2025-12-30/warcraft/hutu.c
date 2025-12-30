// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m刀神[2;37;0m[2;37;0m", ({"bladeshen"}));        
        set("gender", "男性");                
        set("long", "這就是刀神，[2;37;0m
它是糊塗的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "hutu");
        set("owner_name", "糊塗");
        set_temp("owner", "hutu");
        set_temp("owner_name", "糊塗");
        ::setup();
}
