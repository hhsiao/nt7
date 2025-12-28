// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("藍色憂鬱[2;37;0m[2;37;0m", ({"food"}));        
        set("gender", "男性");                
        set("long", "藍色憂鬱[2;37;0m
它是唐寧的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "fenly");
        set("owner_name", "唐寧");
        set_temp("owner", "fenly");
        set_temp("owner_name", "唐寧");
        ::setup();
}
