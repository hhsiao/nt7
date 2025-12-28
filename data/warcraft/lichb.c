// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("梁朝偉[2;37;0m[2;37;0m", ({"sadfajl"}));        
        set("gender", "男性");                
        set("long", "阿斯頓發生了[2;37;0m
它是綠一的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "lichb");
        set("owner_name", "綠一");
        set_temp("owner", "lichb");
        set_temp("owner_name", "綠一");
        ::setup();
}
