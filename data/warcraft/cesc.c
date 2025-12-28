// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("唐大坑[2;37;0m[2;37;0m", ({"tangkd"}));        
        set("gender", "男性");                
        set("long", "坑爹貨[2;37;0m
它是金曉辰的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "cesc");
        set("owner_name", "金曉辰");
        set_temp("owner", "cesc");
        set_temp("owner_name", "金曉辰");
        ::setup();
}
