// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;36m青蜂俠[2;37;0m[2;37;0m", ({"driver"}));        
        set("gender", "女性");                
        set("long", "朱雀[2;37;0m
它是蕭晨風的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "xcw");
        set("owner_name", "蕭晨風");
        set_temp("owner", "xcw");
        set_temp("owner_name", "蕭晨風");
        ::setup();
}
