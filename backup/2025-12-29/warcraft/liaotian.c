// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("長腿美女[2;37;0m[2;37;0m", ({"ctmn"}));        
        set("gender", "女性");                
        set("long", "長腿美女[2;37;0m
它是撩舔的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "liaotian");
        set("owner_name", "撩舔");
        set_temp("owner", "liaotian");
        set_temp("owner_name", "撩舔");
        ::setup();
}
