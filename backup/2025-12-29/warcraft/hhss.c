// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("靈英[2;37;0m[2;37;0m", ({"jinlong"}));        
        set("gender", "男性");                
        set("long", "異族人[2;37;0m
它是唐烈的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "hhss");
        set("owner_name", "唐烈");
        set_temp("owner", "hhss");
        set_temp("owner_name", "唐烈");
        ::setup();
}
