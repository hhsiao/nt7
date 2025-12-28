// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("睚眥[2;37;0m[2;37;0m", ({"olo"}));        
        set("gender", "男性");                
        set("long", "龍身鬼口[2;37;0m
它是唐斬的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "opp");
        set("owner_name", "唐斬");
        set_temp("owner", "opp");
        set_temp("owner_name", "唐斬");
        ::setup();
}
