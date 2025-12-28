// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;33m一[1;36m萬[36m金[1;31m票[2;37;0m[2;37;0m", ({"lingshan"}));        
        set("gender", "女性");                
        set("long", "加工[2;37;0m
它是靈山上人的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "linga");
        set("owner_name", "靈山上人");
        set_temp("owner", "linga");
        set_temp("owner_name", "靈山上人");
        ::setup();
}
