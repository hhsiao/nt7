// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("寶寶的坐騎[2;37;0m[2;37;0m", ({"lautmbb"}));        
        set("gender", "男性");                
        set("long", "寶寶的坐騎[2;37;0m
它是唐寶寶的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "lautm");
        set("owner_name", "唐寶寶");
        set_temp("owner", "lautm");
        set_temp("owner_name", "唐寶寶");
        ::setup();
}
