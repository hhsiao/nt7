// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("黑白郎君[2;37;0m[2;37;0m", ({"hen"}));        
        set("gender", "男性");                
        set("long", "黑白郎君南宮恨[2;37;0m
它是南宮恨的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nangong");
        set("owner_name", "南宮恨");
        set_temp("owner", "nangong");
        set_temp("owner_name", "南宮恨");
        ::setup();
}
