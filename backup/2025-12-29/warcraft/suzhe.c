// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m玄武[2;37;0m[2;37;0m", ({"xuanwu"}));        
        set("gender", "男性");                
        set("long", "玄武[2;37;0m
它是蘇轍的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "suzhe");
        set("owner_name", "蘇轍");
        set_temp("owner", "suzhe");
        set_temp("owner_name", "蘇轍");
        ::setup();
}
