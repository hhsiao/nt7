// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m南方朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "南方朱雀[2;37;0m
它是夢神機的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "shenji");
        set("owner_name", "夢神機");
        set_temp("owner", "shenji");
        set_temp("owner_name", "夢神機");
        ::setup();
}
