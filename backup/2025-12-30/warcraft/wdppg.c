// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("都[2;37;0m[2;37;0m", ({"mygift"}));        
        set("gender", "女性");                
        set("long", "都[2;37;0m
它是武當師七的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "wdppg");
        set("owner_name", "武當師七");
        set_temp("owner", "wdppg");
        set_temp("owner_name", "武當師七");
        ::setup();
}
