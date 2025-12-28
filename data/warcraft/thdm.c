// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("拿書專用坐騎[2;37;0m[2;37;0m", ({"thdmm"}));        
        set("gender", "男性");                
        set("long", "拿書專用坐騎[2;37;0m
它是桃花多多的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "thdm");
        set("owner_name", "桃花多多");
        set_temp("owner", "thdm");
        set_temp("owner_name", "桃花多多");
        ::setup();
}
