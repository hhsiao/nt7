// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m高鐵[2;37;0m[2;37;0m", ({"gaotie"}));        
        set("gender", "男性");                
        set("long", "高鐵[2;37;0m
它是塔思肯的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "task");
        set("owner_name", "塔思肯");
        set_temp("owner", "task");
        set_temp("owner_name", "塔思肯");
        ::setup();
}
