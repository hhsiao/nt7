// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("第五[2;37;0m[2;37;0m", ({"mygift"}));        
        set("gender", "女性");                
        set("long", "第五[2;37;0m
它是武當師零的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wdppj");
        set("owner_name", "武當師零");
        set_temp("owner", "wdppj");
        set_temp("owner_name", "武當師零");
        ::setup();
}
