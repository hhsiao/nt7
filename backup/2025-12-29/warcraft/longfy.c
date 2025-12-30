// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;37m靈魂深處[2;37;0m[2;37;0m", ({"lhsc"}));        
        set("gender", "男性");                
        set("long", "靈魂深處[2;37;0m
它是龍飛雲的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "longfy");
        set("owner_name", "龍飛雲");
        set_temp("owner", "longfy");
        set_temp("owner_name", "龍飛雲");
        ::setup();
}
