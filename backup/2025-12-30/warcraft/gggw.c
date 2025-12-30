// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("歐歐[2;37;0m[2;37;0m", ({"ouou"}));        
        set("gender", "男性");                
        set("long", "歐歐[2;37;0m
它是吖貳的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "gggw");
        set("owner_name", "吖貳");
        set_temp("owner", "gggw");
        set_temp("owner_name", "吖貳");
        ::setup();
}
