// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[42m[1;31m渡劫飛昇[2;37;0m[2;37;0m", ({"ture"}));        
        set("gender", "男性");                
        set("long", "馬上要渡劫飛昇仙界，前輩不是你們這些螻蟻看的。[2;37;0m
它是邵流淚的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "swingswing");
        set("owner_name", "邵流淚");
        set_temp("owner", "swingswing");
        set_temp("owner_name", "邵流淚");
        ::setup();
}
