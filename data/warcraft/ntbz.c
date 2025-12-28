// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "朱雀[2;37;0m
它是蒼井空的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "ntbz");
        set("owner_name", "蒼井空");
        set_temp("owner", "ntbz");
        set_temp("owner_name", "蒼井空");
        ::setup();
}
