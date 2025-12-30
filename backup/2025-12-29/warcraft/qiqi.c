// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("寶貝[2;37;0m[2;37;0m", ({"qixuan"}));        
        set("gender", "女性");                
        set("long", "寶貝[2;37;0m
它是軒轅淇萱的魔幻獸。
");
        set("race_type", "朱雀");
        set("magic/type", "fire");
        set("owner", "qiqi");
        set("owner_name", "軒轅淇萱");
        set_temp("owner", "qiqi");
        set_temp("owner_name", "軒轅淇萱");
        ::setup();
}
