// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("玄武[2;37;0m[2;37;0m", ({"xuanwu"}));        
        set("gender", "男性");                
        set("long", "eat gan liang[2;37;0m
它是靜一的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "jinga");
        set("owner_name", "靜一");
        set_temp("owner", "jinga");
        set_temp("owner_name", "靜一");
        ::setup();
}
