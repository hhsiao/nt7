// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("哦我的[2;37;0m[2;37;0m", ({"mygift"}));        
        set("gender", "女性");                
        set("long", "哦我的[2;37;0m
它是武當師九的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wdppi");
        set("owner_name", "武當師九");
        set_temp("owner", "wdppi");
        set_temp("owner_name", "武當師九");
        ::setup();
}
