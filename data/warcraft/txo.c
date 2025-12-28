// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("朱雀[2;37;0m[2;37;0m", ({"zhuque"}));        
        set("gender", "男性");                
        set("long", "朱[2;37;0m
它是土小歐的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "txo");
        set("owner_name", "土小歐");
        set_temp("owner", "txo");
        set_temp("owner_name", "土小歐");
        ::setup();
}
