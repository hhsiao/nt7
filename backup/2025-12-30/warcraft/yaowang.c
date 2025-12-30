// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;32m採藥童子[2;37;0m[2;37;0m", ({"zuoqi"}));        
        set("gender", "男性");                
        set("long", "採藥童子[2;37;0m
它是藥王的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "yaowang");
        set("owner_name", "藥王");
        set_temp("owner", "yaowang");
        set_temp("owner_name", "藥王");
        ::setup();
}
