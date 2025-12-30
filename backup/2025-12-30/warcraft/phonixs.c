// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("追風狂馬[2;37;0m[2;37;0m", ({"phonixsa"}));        
        set("gender", "男性");                
        set("long", "1234567[2;37;0m
它是蘆屋雪介的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "phonixs");
        set("owner_name", "蘆屋雪介");
        set_temp("owner", "phonixs");
        set_temp("owner_name", "蘆屋雪介");
        ::setup();
}
