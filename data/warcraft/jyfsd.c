// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白虎[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "男性");                
        set("long", "白虎[2;37;0m
它是拓拔興中的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "jyfsd");
        set("owner_name", "拓拔興中");
        set_temp("owner", "jyfsd");
        set_temp("owner_name", "拓拔興中");
        ::setup();
}
