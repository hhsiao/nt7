// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("極品毒蟲[2;37;0m[2;37;0m", ({"myma"}));        
        set("gender", "男性");                
        set("long", "一隻極品毒蟲[2;37;0m
它是葵花子的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "kuihua");
        set("owner_name", "葵花子");
        set_temp("owner", "kuihua");
        set_temp("owner_name", "葵花子");
        ::setup();
}
