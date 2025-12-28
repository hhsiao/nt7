// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[35m貔貅[2;37;0m[2;37;0m", ({"pixiu"}));        
        set("gender", "男性");                
        set("long", "傳說中的招財瑞獸，以財為食，納食四方之財。[2;37;0m
它是唐藍的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "blue");
        set("owner_name", "唐藍");
        set_temp("owner", "blue");
        set_temp("owner_name", "唐藍");
        ::setup();
}
