// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("白狐[2;37;0m[2;37;0m", ({"baihu"}));        
        set("gender", "男性");                
        set("long", "白[2;37;0m
它是風月的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "afeng");
        set("owner_name", "風月");
        set_temp("owner", "afeng");
        set_temp("owner_name", "風月");
        ::setup();
}
