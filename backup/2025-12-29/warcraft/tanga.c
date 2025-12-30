// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("獸獸[2;37;0m[2;37;0m", ({"shoua"}));        
        set("gender", "男性");                
        set("long", "這是獸首[2;37;0m
它是飛為的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "tanga");
        set("owner_name", "飛為");
        set_temp("owner", "tanga");
        set_temp("owner_name", "飛為");
        ::setup();
}
