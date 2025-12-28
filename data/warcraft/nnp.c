// warcraft.c

#include "/clone/npc/warcraft.h"

void setup()
{
        set_name("小眼[2;37;0m[2;37;0m", ({"myzuoqi"}));        
        set("gender", "女性");                
        set("long", "小眼[2;37;0m
它是貨到付款的魔幻獸。
");
        set("race_type", "麒麟");
        set("magic/type", "earth");
        set("owner", "nnp");
        set("owner_name", "貨到付款");
        set_temp("owner", "nnp");
        set_temp("owner_name", "貨到付款");
        ::setup();
}
