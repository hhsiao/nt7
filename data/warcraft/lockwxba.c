// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("竹掃帚[2;37;0m[2;37;0m", ({"saozhou"}));        
        set("gender", "男性");                
        set("long", "一把破舊的竹掃帚。[2;37;0m
它是老僕人的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "lockwxba");
        set("owner_name", "老僕人");
        set_temp("owner", "lockwxba");
        set_temp("owner_name", "老僕人");
        ::setup();
}
