// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[5m[1;36m露[5m[1;36m露[2;37;0m[2;37;0m", ({"lulu"}));        
        set("gender", "女性");                
        set("long", "可愛淫蕩的露露[2;37;0m
它是唐糖的魔幻獸。
");
        set("race_type", "白虎");
        set("magic/type", "metal");
        set("owner", "sariel");
        set("owner_name", "唐糖");
        set_temp("owner", "sariel");
        set_temp("owner_name", "唐糖");
        ::setup();
}
