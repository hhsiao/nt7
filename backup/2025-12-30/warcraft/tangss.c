// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[35m掃帚[2;37;0m[2;37;0m", ({"dragon"}));        
        set("gender", "女性");                
        set("long", "`(*∩_∩*)′[2;37;0m
它是唐詩詩的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "tangss");
        set("owner_name", "唐詩詩");
        set_temp("owner", "tangss");
        set_temp("owner_name", "唐詩詩");
        ::setup();
}
