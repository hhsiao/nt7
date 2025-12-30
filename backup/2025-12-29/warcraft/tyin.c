// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m火紅鳳凰[2;37;0m[2;37;0m", ({"tyinpet"}));        
        set("gender", "女性");                
        set("long", "一隻幼小的火紅鳳凰！[2;37;0m
它是唐影的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "tyin");
        set("owner_name", "唐影");
        set_temp("owner", "tyin");
        set_temp("owner_name", "唐影");
        ::setup();
}
