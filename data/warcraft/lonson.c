// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("[1;31m金[1;33m屬[1;36m暴[1;32m龍[2;37;0m[2;37;0m", ({"goldlon"}));        
        set("gender", "男性");                
        set("long", "怎麼都走步快[2;37;0m
它是東方流星的魔幻獸。
");
        set("race_type", "玄武");
        set("magic/type", "water");
        set("owner", "lonson");
        set("owner_name", "東方流星");
        set_temp("owner", "lonson");
        set_temp("owner_name", "東方流星");
        ::setup();
}
