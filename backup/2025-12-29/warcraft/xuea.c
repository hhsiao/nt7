// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[35m絕[1;36m滅[36m小[1;31m師[33m太[2;37;0m[2;37;0m", ({"shen"}));        
        set("gender", "男性");                
        set("long", "四項基本原則[2;37;0m
它是一錘定音的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "xuea");
        set("owner_name", "一錘定音");
        set_temp("owner", "xuea");
        set_temp("owner_name", "一錘定音");
        ::setup();
}
