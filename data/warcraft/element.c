// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m小秘[2;37;0m[2;37;0m", ({"solo"}));        
        set("gender", "女性");                
        set("long", "黑絲迷死人[2;37;0m
它是司馬悟空的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "element");
        set("owner_name", "司馬悟空");
        set_temp("owner", "element");
        set_temp("owner_name", "司馬悟空");
        ::setup();
}
