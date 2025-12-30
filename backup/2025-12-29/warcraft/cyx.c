// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("唸書坐騎[2;37;0m[2;37;0m", ({"cyxzq"}));        
        set("gender", "男性");                
        set("long", "唸書坐騎[2;37;0m
它是念書為家的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "cyx");
        set("owner_name", "唸書為家");
        set_temp("owner", "cyx");
        set_temp("owner_name", "唸書為家");
        ::setup();
}
