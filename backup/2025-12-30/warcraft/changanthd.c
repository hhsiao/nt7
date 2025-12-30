// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "女性");                
        set("long", "大[2;37;0m
它是長五安的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "changanthd");
        set("owner_name", "長五安");
        set_temp("owner", "changanthd");
        set_temp("owner_name", "長五安");
        ::setup();
}
