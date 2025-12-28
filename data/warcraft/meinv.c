// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小紅馬[2;37;0m[2;37;0m", ({"ooo"}));        
        set("gender", "男性");                
        set("long", "沒啥描述的隨便玩的[2;37;0m
它是美女爽爽的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "meinv");
        set("owner_name", "美女爽爽");
        set_temp("owner", "meinv");
        set_temp("owner_name", "美女爽爽");
        ::setup();
}
