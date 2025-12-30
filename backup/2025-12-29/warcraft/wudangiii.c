// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("飛龜[2;37;0m[2;37;0m", ({"flyturtle"}));        
        set("gender", "男性");                
        set("long", "飛龜[2;37;0m
它是武當四俠的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "wudangiii");
        set("owner_name", "武當四俠");
        set_temp("owner", "wudangiii");
        set_temp("owner_name", "武當四俠");
        ::setup();
}
