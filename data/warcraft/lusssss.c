// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("超級神獸[2;37;0m[2;37;0m", ({"ljs"}));        
        set("gender", "男性");                
        set("long", "防禦超強[2;37;0m
它是順哽在的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "lusssss");
        set("owner_name", "順哽在");
        set_temp("owner", "lusssss");
        set_temp("owner_name", "順哽在");
        ::setup();
}
