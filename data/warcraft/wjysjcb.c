// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("座機[2;37;0m[2;37;0m", ({"zuoji"}));        
        set("gender", "男性");                
        set("long", "啊[2;37;0m
它是吖嘻的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "wjysjcb");
        set("owner_name", "吖嘻");
        set_temp("owner", "wjysjcb");
        set_temp("owner_name", "吖嘻");
        ::setup();
}
