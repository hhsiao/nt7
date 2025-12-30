// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("著騎[2;37;0m[2;37;0m", ({"along"}));        
        set("gender", "男性");                
        set("long", "一八[2;37;0m
它是小院區的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "xiaoc");
        set("owner_name", "小院區");
        set_temp("owner", "xiaoc");
        set_temp("owner_name", "小院區");
        ::setup();
}
