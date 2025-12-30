// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("魔幻獸[2;37;0m[2;37;0m", ({"gmsss"}));        
        set("gender", "男性");                
        set("long", "一隻普通魔幻獸。[2;37;0m
它是飛流三尺的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "testgms");
        set("owner_name", "飛流三尺");
        set_temp("owner", "testgms");
        set_temp("owner_name", "飛流三尺");
        ::setup();
}
