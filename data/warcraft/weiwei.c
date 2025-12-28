// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m小大眾[2;37;0m[2;37;0m", ({"zsw"}));        
        set("gender", "女性");                
        set("long", "薇薇的小POLO[2;37;0m
它是唐薇薇的魔幻獸。
");
        set("race_type", "青龍");
        set("magic/type", "wood");
        set("owner", "weiwei");
        set("owner_name", "唐薇薇");
        set_temp("owner", "weiwei");
        set_temp("owner_name", "唐薇薇");
        ::setup();
}
