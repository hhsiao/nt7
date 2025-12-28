// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("罹天火[2;37;0m[2;37;0m", ({"que"}));        
        set("gender", "男性");                
        set("long", "拈花渡影攝太虛，傲世無雙罹乾坤[2;37;0m
它是劍無塵的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "longjian");
        set("owner_name", "劍無塵");
        set_temp("owner", "longjian");
        set_temp("owner_name", "劍無塵");
        ::setup();
}
