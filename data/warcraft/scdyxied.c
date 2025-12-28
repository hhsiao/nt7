// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("土土土土土鱉[2;37;0m[2;37;0m", ({"xied"}));        
        set("gender", "男性");                
        set("long", "一隻大烏龜[2;37;0m
它是伯賞昆御的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "scdyxied");
        set("owner_name", "伯賞昆御");
        set_temp("owner", "scdyxied");
        set_temp("owner_name", "伯賞昆御");
        ::setup();
}
